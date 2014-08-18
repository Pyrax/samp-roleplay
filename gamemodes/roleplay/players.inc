#if defined _INCLUDED_PLAYERS
    #endinput
#endif
#define _INCLUDED_PLAYERS

//-----------------------------------------------------

#define MIN_PW_LEN          6
#define MAX_PW_LEN          32
#define MAX_LOG_TRIES       3

//-----------------------------------------------------

enum E_PLAYER {
    ORM:orm_ID,
    ID,
    password[129],
    name[PLAYER_NAME_LEN]
    
    // non-stored variables
};

//-----------------------------------------------------

new g_Player[MAX_PLAYERS][E_PLAYER];

//-----------------------------------------------------

AuthenticatePlayer(playerid) {
    new ORM:ormid = g_Player[playerid][orm_ID] = orm_create("players");
    
    // Only load credentials as long as player is not authenticated
    orm_addvar_string(ormid, g_Player[playerid][name], PLAYER_NAME_LEN, "name");
    orm_setkey(ormid, "name");
    
    orm_addvar_string(ormid, g_Player[playerid][password], 129, "password");
    
    inline CredentialsLoaded(i_playerid) {
        switch(orm_errno(g_Player[i_playerid][orm_ID])) {
            case ERROR_OK: {
                // user exists, ask for password
                #define DIALOG_LOGIN Dialog_ShowCallback(i_playerid, using inline LoginResponse, DIALOG_STYLE_PASSWORD, "Anmelden", "Herzlich Willkommen zurück!\nGib unten dein Passwort ein, um dich anzumelden.\n[Falls du das erste Mal auf dem Server bist, ist dein Benutzername schon vergeben.\nÄndere deinen Namen und komm zurück.]", "Anmelden");
                
                inline LoginResponse(ii_playerid, ii_dialogid, ii_response, ii_listitem, string:ii_inputtext[]) {
                    #pragma unused ii_dialogid, ii_listitem
                    if(ii_response) {
                        new hash[129];
                        WP_Hash(hash, 129, ii_inputtext);
                        
                        if(!strcmp(hash, g_Player[ii_playerid][password])) {
                            orm_addvar_int(ormid, g_Player[ii_playerid][ID], "ID");
                            
                            orm_setkey(g_Player[ii_playerid][orm_ID], "ID");
                            // orm_select to load
                        } else {
                            // wrong password
                            DIALOG_LOGIN
                        }
                    } else {
                        // KICK
                    }
                }
                DIALOG_LOGIN
                
                #undef DIALOG_LOGIN
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
                                    WP_Hash(g_Player[iii_playerid][password], 129, ii_inputtext);
                                    
                                    orm_addvar_int(ormid, g_Player[iii_playerid][ID], "ID");
                                    
                                    // change key to ID before inserting to automatically update it after the account has been inserted
                                    orm_setkey(g_Player[iii_playerid][orm_ID], "ID");
                                    orm_insert(g_Player[iii_playerid][orm_ID]);
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
                        // KICK
                    }
                }
                DIALOG_REGISTER
                
                #undef DIALOG_REGISTER
            }
        }
    }
    orm_select_inline(ormid, using inline CredentialsLoaded, "d", playerid);
}

SavePlayer(playerid) {
    if(IsPlayerLoggedIn(playerid)) {
        orm_update(g_Player[playerid][orm_ID]);
    }
    
    orm_destroy(g_Player[playerid][orm_ID]);
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
    return g_Player[playerid][ID] != 0;
}

GetPlayerID(playerid) {
    return g_Player[playerid][ID];
}