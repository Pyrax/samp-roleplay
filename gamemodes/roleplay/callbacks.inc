#if defined _INCLUDED_CALLBACKS
    #endinput
#endif
#define _INCLUDED_CALLBACKS

//-----------------------------------------------------

public OnGameModeInit() {
    Bootstrap();
    LoadHousesFromDatabase();
    AddPlayerClass(0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
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