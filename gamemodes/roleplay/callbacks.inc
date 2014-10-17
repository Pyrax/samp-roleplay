#if defined _INCLUDED_CALLBACKS
    #endinput
#endif
#define _INCLUDED_CALLBACKS

//-----------------------------------------------------

// by wiki.sa-mp.com
#define KEY_PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

// by wiki.sa-mp.com
#define KEY_RELEASED(%0) \
	(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))

//-----------------------------------------------------

static  brokersPickup,
        labourOfficePickup;
static  Text3D:brokers3DText,
        Text3D:labourOffice3DText;

//-----------------------------------------------------

public OnGameModeInit() {
    Bootstrap();
    
    LoadHousesFromDatabase();
    LoadJobsFromDatabase();
    
    brokersPickup = CreatePickup(ENTER_PICKUP, 1, BROKER_POS, VW_DEFAULT);
    brokers3DText = Create3DTextLabel("Hausmakler", COLOR_3DTEXT, BROKER_POS, D3_DRAW_DISTANCE_DEFAULT, VW_DEFAULT, 1);
    
    labourOfficePickup = CreatePickup(ENTER_PICKUP, 1, LABOUR_OFFICE_POS, VW_DEFAULT);
    labourOffice3DText = Create3DTextLabel("Arbeitsamt", COLOR_3DTEXT, LABOUR_OFFICE_POS, D3_DRAW_DISTANCE_DEFAULT, VW_DEFAULT, 1);
    
    AddPlayerClass(0, 1554.1963, -1097.0775, 25.0625, 95.6683, 0, 0, 0, 0, 0, 0);
    return 1;
}

public OnGameModeExit() {
    foreach(new i : Player) {
        CancelSelectTextDraw(i);
    }
    
    Delete3DTextLabel(brokers3DText);
    Delete3DTextLabel(labourOffice3DText);
    return 1;
}

public OnPlayerConnect(playerid) {
    GetPlayerName(playerid, g_Player[playerid][g_name], MAX_PLAYER_NAME);
    Langs_SetPlayerLanguage(playerid, g_langGerman);
    CreatePlayerCameraDummy(playerid);
    AuthenticatePlayer(playerid);
    return 1;
}

public OnPlayerDisconnect(playerid, reason) {
    SavePlayer(playerid);
    ResetPlayer(playerid);
    HidePlayerDateTime(playerid);
    DestroyPlayerCameraDummy(playerid);
    return 1;
}

public OnPlayerSpawn(playerid) {
    PreloadAnimations(playerid);
    ShowPlayerDateTime(playerid);
    return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid) {
    // brokers
    if(pickupid == brokersPickup) {
        SetPVarInt(playerid, "IsAtBrokersPickup", 1);
        return 1;
    }
        
    // labour office
    if(pickupid == labourOfficePickup) {
        SetPVarInt(playerid, "IsAtLabourOfficePickup", 1);
        return 1;
    }
    
    // house entrance
    if(!GetPVarInt(playerid, "IsAtHouseEntrance")) {
        // check if pickup is a house entrance
        new nearHouseEntrance = IsHousePickup(pickupid); // returns the array idx
        
        if(nearHouseEntrance != -1) {
            SetPVarInt(playerid, "IsAtHouseEntrance", nearHouseEntrance);
            return 1;
        }
    }
    return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if(KEY_PRESSED(KEY_SECONDARY_ATTACK)) {
        if(GetPVarInt(playerid, "EnterExitBlock") < gettime()) {
            if(GetPVarType(playerid, "IsAtBrokersPickup")) {
                ShowPlayerHouseOffers(playerid);
                
                EnterExitBlock(playerid);
                return 0;
            } else if(GetPVarType(playerid, "IsAtLabourOfficePickup")) {
                ShowPlayerJobMenu(playerid);
                
                EnterExitBlock(playerid);
                return 0;
            }
            
            new nearHouseEntrance = GetPVarInt(playerid, "IsAtHouseEntrance"),
                inHouse = GetPVarInt(playerid, "IsInHouse");
            
            if(GetPVarType(playerid, "IsAtHouseEntrance")) {
                if(EnterHouse(playerid, nearHouseEntrance)) {
                    SetPVarInt(playerid, "IsInHouse", nearHouseEntrance);
                    
                    // prevent player from spamming entering/exiting houses
                    EnterExitBlock(playerid);
                    return 0;
                }
            } else if(GetPVarType(playerid, "IsInHouse")) {
                if(IsAtHouseExit(playerid, inHouse)) {
                    if(LeaveHouse(playerid, inHouse)) {
                        DeletePVar(playerid, "IsInHouse");
                        
                        // prevent player from spamming entering/exiting houses
                        EnterExitBlock(playerid);
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

function OnPlayerLogin(playerid) {
    return 1;
}

function OnPlayerLoadJob(playerid, newJobType) {
    return 1;
}

EnterExitBlock(playerid) {
    SetPVarInt(playerid, "EnterExitBlock", gettime() + 5);
}

SetPlayerToBroker(playerid) {
    SetPlayerPos(playerid, BROKER_POS);
    SetPlayerFacingAngle(playerid, BROKER_EXIT_ANGLE);
}

SetPlayerToLabourOffice(playerid) {
    SetPlayerPos(playerid, LABOUR_OFFICE_POS);
    SetPlayerFacingAngle(playerid, LABOUR_OFFICE_EXIT_ANGLE);
    SetPlayerInterior(playerid, 0);
}

// reset IsAtHouseEntrance-PVar if the player is not near the pickup anymore
ptask ResetAtHouseEntrance[1000](playerid) {
    if(GetPVarType(playerid, "IsAtHouseEntrance")) {
        // when player is not near the house entrance anymore delete the PVar
        if(!IsAtHouseEntrance(playerid, GetPVarInt(playerid, "IsAtHouseEntrance"))) {
            DeletePVar(playerid, "IsAtHouseEntrance");
        }
    }
}

ptask ResetAtBrokersPickup[1000](playerid) {
    if(GetPVarType(playerid, "IsAtBrokersPickup")) {
        if(!IsPlayerInRangeOfPoint(playerid, PICKUP_RANGE, BROKER_POS)) {
            DeletePVar(playerid, "IsAtBrokersPickup");
        }
    }
}

ptask ResetAtLabourOfficePickup[1000](playerid) {
    if(GetPVarType(playerid, "IsAtLabourOfficePickup")) {
        if(!IsPlayerInRangeOfPoint(playerid, PICKUP_RANGE, LABOUR_OFFICE_POS)) {
            DeletePVar(playerid, "IsAtLabourOfficePickup");
        }
    }
}