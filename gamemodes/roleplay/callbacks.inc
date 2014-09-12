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

#define BROKER_X            1546.2646484375
#define BROKER_Y            -1097.6547851563
#define BROKER_Z            25.0625
#define BROKER_EXIT_ANGLE   270.0

//-----------------------------------------------------

static brokersPickup;
static Text3D:brokers3DText;

//-----------------------------------------------------

public OnGameModeInit() {
    Bootstrap();
    LoadHousesFromDatabase();
    
    brokersPickup = CreatePickup(ENTER_PICKUP, 1, BROKER_X, BROKER_Y, BROKER_Z, VW_DEFAULT);
    brokers3DText = Create3DTextLabel("Hausmakler", COLOR_3DTEXT, BROKER_X, BROKER_Y, BROKER_Z, D3_DRAW_DISTANCE_DEFAULT, VW_DEFAULT, 1);
    
    AddPlayerClass(0, 1554.1963, -1097.0775, 25.0625, 95.6683, 0, 0, 0, 0, 0, 0);
    return 1;
}

public OnGameModeExit() {
    foreach(new i : Player) {
        CancelSelectTextDraw(i);
    }
    Delete3DTextLabel(brokers3DText);
    return 1;
}

public OnPlayerConnect(playerid) {
    GetPlayerName(playerid, g_Player[playerid][g_name], MAX_PLAYER_NAME);
    CreatePlayerCameraDummy(playerid);
    AuthenticatePlayer(playerid);
    return 1;
}

public OnPlayerDisconnect(playerid, reason) {
    SavePlayer(playerid);
    ResetPlayer(playerid);
    HidePlayerDateTime(playerid);
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

EnterExitBlock(playerid) {
    SetPVarInt(playerid, "EnterExitBlock", gettime() + 5);
}

SetPlayerToBroker(playerid) {
    SetPlayerPos(playerid, BROKER_X, BROKER_Y, BROKER_Z);
    SetPlayerFacingAngle(playerid, BROKER_EXIT_ANGLE);
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
        if(!IsPlayerInRangeOfPoint(playerid, PICKUP_RANGE, BROKER_X, BROKER_Y, BROKER_Z)) {
            DeletePVar(playerid, "IsAtBrokersPickup");
        }
    }
}