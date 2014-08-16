#if defined _HOUSES_INCLUDED
	#endinput
#endif
#define _HOUSES_INCLUDED

//-----------------------------------------------------

#define MAX_HOUSES 50

#define GetPlayerMoney GetPlayerMoney
#define IsPlayerLoggedIn IsPlayerConnected

//-----------------------------------------------------

enum E_HOUSE {
	ORM:ORM_ID,
	ID,
	Owner_ID,
	
	// Variables that are only needed for the shopping menu
	Model_ID,
	Price,
	Float:CameraPosX,
	Float:CameraPosY,
	Float:CameraPosZ,
	Float:CameraLookAtX,
	Float:CameraLookAtY,
	Float:CameraLookAtZ
}

//-----------------------------------------------------

new g_House[MAX_HOUSES][E_HOUSE];

//-----------------------------------------------------

ShowPlayerHouseList(playerid) {
	if(!IsPlayerLoggedIn()) {
		return 0;
	}
	
	// SHOW TEXTDRAWS
	// TextDrawSetPreviewModel(td_houseModel, ModelID);
	return 1;
}

LoadHousesFromDatabase() {
	// SELECT * FROM houses
	// new data = 
}