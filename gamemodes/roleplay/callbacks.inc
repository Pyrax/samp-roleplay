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

public OnGameModeInit() {
    Bootstrap();
    LoadHousesFromDatabase();
    AddPlayerClass(0, 1481.3070, -861.3610, 58.2491, 139.0467, 0, 0, 0, 0, 0, 0);
    return 1;
}

public OnGameModeExit() {
    return 1;
}

public OnPlayerConnect(playerid) {
    GetPlayerName(playerid, g_Player[playerid][name], MAX_PLAYER_NAME);
    AuthenticatePlayer(playerid);
    return 1;
}

public OnPlayerDisconnect(playerid, reason) {
    SavePlayer(playerid);
    ResetPlayer(playerid);
    return 1;
}

public OnPlayerSpawn(playerid) {
    PreloadAnimations(playerid);
    return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid) {
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
        if(!GetPVarType(playerid, "EnterExitBlock")) {
            new nearHouseEntrance = GetPVarInt(playerid, "IsAtHouseEntrance"),
                inHouse = GetPVarInt(playerid, "IsInHouse");
            
            if(GetPVarType(playerid, "IsAtHouseEntrance")) {
                if(EnterHouse(playerid, nearHouseEntrance)) {
                    SetPVarInt(playerid, "IsInHouse", nearHouseEntrance);
                    
                    // prevent player from spamming entering/exiting houses
                    SetPVarInt(playerid, "EnterExitBlock", 1);
                    defer ResetEnterExitBlock(playerid);
                }
            } else if(GetPVarType(playerid, "IsInHouse")) {
                if(IsAtHouseExit(playerid, inHouse)) {
                    if(LeaveHouse(playerid, inHouse)) {
                        DeletePVar(playerid, "IsInHouse");
                        
                        // prevent player from spamming entering/exiting houses
                        SetPVarInt(playerid, "EnterExitBlock", 1);
                        defer ResetEnterExitBlock(playerid);
                    }
                }
            }
        }
    }
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

timer ResetEnterExitBlock[5000](playerid) {
    if(GetPVarType(playerid, "EnterExitBlock")) {
        DeletePVar(playerid, "EnterExitBlock");
    }
}