#if defined _INCLUDED_PLAYERS
    #endinput
#endif
#define _INCLUDED_PLAYERS

//-----------------------------------------------------

loadtext mode_text[players];

//-----------------------------------------------------

#define MIN_PW_LEN          6
#define MAX_PW_LEN          32
#define MAX_LOG_TRIES       3

//-----------------------------------------------------

enum E_PLAYER {
    ORM:g_orm_ID,
    g_ID,
    g_password[129],
    g_name[PLAYER_NAME_LEN],
    g_money,
    
    // non-stored variables
    g_cameraDummy
};

//-----------------------------------------------------

new g_Player[MAX_PLAYERS][E_PLAYER];

//-----------------------------------------------------

AuthenticatePlayer(playerid) {
    new ORM:ormid = g_Player[playerid][g_orm_ID] = orm_create("players");
    
    orm_addvar_int(ormid, g_Player[playerid][g_ID], "ID");
    orm_addvar_string(ormid, g_Player[playerid][g_password], 129, "password");
    orm_addvar_string(ormid, g_Player[playerid][g_name], PLAYER_NAME_LEN, "name");
    orm_addvar_int(ormid, g_Player[playerid][g_money], "money");
    
    orm_setkey(ormid, "name");
    
    inline CredentialsLoaded(i_playerid) {
        switch(orm_errno(g_Player[i_playerid][g_orm_ID])) {
            case ERROR_OK: {
                // user exists, ask for password
                
                inline LoginResponse(ii_playerid, ii_dialogid, ii_response, ii_listitem, string:ii_inputtext[]) {
                    #pragma unused ii_dialogid, ii_listitem
                    if(ii_response) {
                        new hash[129];
                        WP_Hash(hash, 129, ii_inputtext);
                        
                        if(!strcmp(hash, g_Player[ii_playerid][g_password])) {
                            orm_setkey(g_Player[ii_playerid][g_orm_ID], "ID");
                            orm_select(g_Player[ii_playerid][g_orm_ID], "OnPlayerLoggedIn", "d", ii_playerid);
                        } else {
                            // wrong password
                            Text_PasswordBox(i_playerid, using inline LoginResponse, $DIALOG_LOGIN_H, $DIALOG_LOGIN_B, $DIALOG_LOGIN_SUB, "");
                        }
                    } else {
                        // TODO: kick
                    }
                }
                Text_PasswordBox(i_playerid, using inline LoginResponse, $DIALOG_LOGIN_H, $DIALOG_LOGIN_B, $DIALOG_LOGIN_SUB, "");
            }
            case ERROR_NO_DATA: {
                // user does not exist, ask to register
                #define DIALOG_REGISTER Dialog_ShowCallback(i_playerid, using inline RegisterResponse, DIALOG_STYLE_PASSWORD, "Registrieren", "Um auf dem Server zu spielen, benötigst du ein Benutzerkonto.\nDu kannst direkt loslegen und ein Benutzerkonto anlegen, indem du dein gewünschtes Passwort unten eingibst.", "Registrieren");
                
                inline RegisterResponse(ii_playerid, ii_dialogid, ii_response, ii_listitem, string:ii_inputtext[]) {
                    #pragma unused ii_playerid, ii_dialogid, ii_listitem
                    
                    if(ii_response) {
                        // validate password
                        inline ValidateResponse(iii_playerid, iii_dialogid, iii_response, iii_listitem, string:iii_inputtext[]) {
                            #pragma unused iii_dialogid, iii_listitem
                            
                            if(iii_response) {
                                if(!strcmp(ii_inputtext, iii_inputtext)) {
                                    // store hashed password in g_Player
                                    WP_Hash(g_Player[iii_playerid][g_password], 129, ii_inputtext);
                                    
                                    // change key to ID before inserting to automatically update it after the account has been inserted
                                    orm_setkey(g_Player[iii_playerid][g_orm_ID], "ID");
                                    orm_insert(g_Player[iii_playerid][g_orm_ID], "OnPlayerLoggedIn", "d", iii_playerid);
                                } else {
                                    // passwords did not match
                                    DIALOG_REGISTER
                                }
                            } else {
                                DIALOG_REGISTER
                            }
                        }
                        Dialog_ShowCallback(i_playerid, using inline ValidateResponse, DIALOG_STYLE_PASSWORD, "Passwort bestätigen", "Gib dein Passwort erneut ein, um es zu bestätigen.", "Spielen!");
                    } else {
                        // TODO: kick
                    }
                }
                DIALOG_REGISTER
                
                #undef DIALOG_REGISTER
            }
        }
    }
    orm_select_inline(ormid, using inline CredentialsLoaded, "d", playerid);
}

function OnPlayerLoggedIn(playerid) {
    GivePlayerMoney(playerid, g_Player[playerid][g_money]);
}

SavePlayer(playerid) {
    if(IsPlayerLoggedIn(playerid)) {
        orm_update(g_Player[playerid][g_orm_ID]);
    }
    
    orm_destroy(g_Player[playerid][g_orm_ID]);
}

ResetPlayer(playerid) {
    static blank[E_PLAYER];
    g_Player[playerid] = blank;
    
    DeletePVars(playerid);
}

static DeletePVars(playerid) {
    new pVarUpperIndex = GetPVarsUpperIndex(playerid) + 1;
    
    for(new i = 0; i != pVarUpperIndex; i++)
    {
        new pVarName[128];
        GetPVarNameAtIndex(playerid, i, pVarName, sizeof pVarName);
        
        // delete PVar if var is set (type not null)
        if(GetPVarType(playerid, pVarName) != 0) {
            DeletePVar(playerid, pVarName);
        }
    }
}

IsPlayerLoggedIn(playerid) {
    return g_Player[playerid][g_ID] != 0;
}

GetPlayerID(playerid) {
    return g_Player[playerid][g_ID];
}

CreatePlayerCameraDummy(playerid) {
    g_Player[playerid][g_cameraDummy] = CreatePlayerObject(playerid, 19300, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
}

GetPlayerCameraDummy(playerid) {
    return g_Player[playerid][g_cameraDummy];
}