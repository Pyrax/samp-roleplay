#if defined _PLAYERS_INCLUDED
	#endinput
#endif
#define _PLAYERS_INCLUDED

//-----------------------------------------------------

#define MIN_PW_LEN			6
#define MAX_PW_LEN			16
#define MAX_LOG_TRIES		3

//-----------------------------------------------------

enum E_PLAYER {
	ORM:ORM_ID,
	ID,
	Name[PLAYER_NAME_LEN],
	Float:PosX,
	Float:PosY,
	Float:PosZ,
	Float:Angle,
	Float:SpawnX,
	Float:SpawnY,
	Float:SpawnZ,
	SpawnInterior,
	SpawnWorld,
	NewbieSpawn
};

//-----------------------------------------------------

new g_Player[MAX_PLAYERS][E_PLAYER];

//-----------------------------------------------------

function OnPlayerDataLoad(playerid) {
    switch(orm_errno(g_Player[playerid][ORM_ID])) {
		case ERROR_OK: {
			// LOGIN
		}
		case ERROR_NO_DATA: {
			// REGISTER
		}
	}
    orm_setkey(g_Player[playerid][ORM_ID], "ID");
    return 1;
}

AddPlayerORM(playerid) {
	new ORM:ormid = g_Player[playerid][ORM_ID] = orm_create("players");

	orm_addvar_int(ormid, g_Player[playerid][ID], "ID");
	orm_addvar_string(ormid, g_Player[playerid][Name], PLAYER_NAME_LEN, "Name");
	orm_addvar_float(ormid, g_Player[playerid][PosX], "PosX");
	orm_addvar_float(ormid, g_Player[playerid][PosY], "PosY");
	orm_addvar_float(ormid, g_Player[playerid][PosZ], "PosZ");
	orm_addvar_float(ormid, g_Player[playerid][Angle], "Angle");
	orm_addvar_float(ormid, g_Player[playerid][SpawnX], "SpawnX");
	orm_addvar_float(ormid, g_Player[playerid][SpawnY], "SpawnY");
	orm_addvar_float(ormid, g_Player[playerid][SpawnZ], "SpawnZ");
	orm_addvar_int(ormid, g_Player[playerid][SpawnInterior], "SpawnInterior");
	orm_addvar_int(ormid, g_Player[playerid][SpawnWorld], "SpawnWorld");
	orm_addvar_int(ormid, g_Player[playerid][NewbieSpawn], "NewbieSpawn");
	
	orm_setkey(ormid, "Name");
	orm_select(ormid, "OnPlayerDataLoad", "i", playerid);
}

RemovePlayerORM(playerid) {
	if(g_Player[playerid][ID] != 0) {
		orm_update(g_Player[playerid][ORM_ID]);   
	}

	orm_destroy(g_Player[playerid][ORM_ID]);
}

ResetPlayer(playerid) {
	static blank[E_PLAYER];
	g_Player[playerid] = blank;
}

UpdatePlayerPos(playerid) {
	new Float:pos[3];
	
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	g_Player[playerid][PosX] = pos[0];
	g_Player[playerid][PosY] = pos[1];
	g_Player[playerid][PosZ] = pos[2];
	
	GetPlayerFacingAngle(playerid, pos[0]);
	g_Player[playerid][Angle] = pos[0];
}