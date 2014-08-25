#if defined _INCLUDED_TEXTDRAWS_HOUSES
    #endinput
#endif
#define _INCLUDED_TEXTDRAWS_HOUSES

//-----------------------------------------------------

static Text:OfferListTextDraws[6];
static PlayerText:OfferListPlayerTextDraws[MAX_PLAYERS][10];

hook OnGameModeInit() {
    CreateHouseOfferTD();
}

CreateHouseOfferTD() {
    OfferListTextDraws[0] = TextDrawCreate(320.0, 353.0, "~n~~n~~n~");
    TextDrawAlignment(OfferListTextDraws[0], 2);
    TextDrawBackgroundColor(OfferListTextDraws[0], 255);
    TextDrawFont(OfferListTextDraws[0], 1);
    TextDrawLetterSize(OfferListTextDraws[0], 0.50, 5.0);
    TextDrawColor(OfferListTextDraws[0], 255);
    TextDrawSetOutline(OfferListTextDraws[0], 0);
    TextDrawSetProportional(OfferListTextDraws[0], 1);
    TextDrawSetShadow(OfferListTextDraws[0], 1);
    TextDrawUseBox(OfferListTextDraws[0], 1);
    TextDrawBoxColor(OfferListTextDraws[0], 252651584);
    TextDrawTextSize(OfferListTextDraws[0], 180.0, 650.0);
    TextDrawSetSelectable(OfferListTextDraws[0], 0);
    
    OfferListTextDraws[1] = TextDrawCreate(320.0, 354.0, "~n~");
    TextDrawAlignment(OfferListTextDraws[1], 2);
    TextDrawBackgroundColor(OfferListTextDraws[1], 255);
    TextDrawFont(OfferListTextDraws[1], 1);
    TextDrawLetterSize(OfferListTextDraws[1], 0.80, 0.0);
    TextDrawColor(OfferListTextDraws[1], -1);
    TextDrawSetOutline(OfferListTextDraws[1], 0);
    TextDrawSetProportional(OfferListTextDraws[1], 1);
    TextDrawSetShadow(OfferListTextDraws[1], 1);
    TextDrawUseBox(OfferListTextDraws[1], 1);
    TextDrawBoxColor(OfferListTextDraws[1], 64);
    TextDrawTextSize(OfferListTextDraws[1], 0.0, 650.0);
    TextDrawSetSelectable(OfferListTextDraws[1], 0);

    OfferListTextDraws[2] = TextDrawCreate(628.0, 357.0, " ~n~ >>~n~ ~n~");
    TextDrawAlignment(OfferListTextDraws[2], 2);
    TextDrawBackgroundColor(OfferListTextDraws[2], 32);
    TextDrawFont(OfferListTextDraws[2], 3);
    TextDrawLetterSize(OfferListTextDraws[2], 0.230000, 3.20);
    TextDrawColor(OfferListTextDraws[2], -1);
    TextDrawSetOutline(OfferListTextDraws[2], 1);
    TextDrawSetProportional(OfferListTextDraws[2], 1);
    TextDrawUseBox(OfferListTextDraws[2], 1);
    TextDrawBoxColor(OfferListTextDraws[2], 842170448);
    TextDrawTextSize(OfferListTextDraws[2], 160.0, 21.0);
    TextDrawSetSelectable(OfferListTextDraws[2], 1);

    OfferListTextDraws[3] = TextDrawCreate(9.0, 357.0, " ~n~ <<~n~ ~n~");
    TextDrawAlignment(OfferListTextDraws[3], 2);
    TextDrawBackgroundColor(OfferListTextDraws[3], 32);
    TextDrawFont(OfferListTextDraws[3], 3);
    TextDrawLetterSize(OfferListTextDraws[3], 0.219999, 3.20);
    TextDrawColor(OfferListTextDraws[3], -1);
    TextDrawSetOutline(OfferListTextDraws[3], 0);
    TextDrawSetProportional(OfferListTextDraws[3], 1);
    TextDrawSetShadow(OfferListTextDraws[3], 1);
    TextDrawUseBox(OfferListTextDraws[3], 1);
    TextDrawBoxColor(OfferListTextDraws[3], 842170448);
    TextDrawTextSize(OfferListTextDraws[3], 90.0, 25.0);
    TextDrawSetSelectable(OfferListTextDraws[3], 1);

    OfferListTextDraws[4] = TextDrawCreate(320.0, 447.0, "~n~");
    TextDrawAlignment(OfferListTextDraws[4], 2);
    TextDrawBackgroundColor(OfferListTextDraws[4], 255);
    TextDrawFont(OfferListTextDraws[4], 1);
    TextDrawLetterSize(OfferListTextDraws[4], 0.80, 1.299999);
    TextDrawColor(OfferListTextDraws[4], -1);
    TextDrawSetOutline(OfferListTextDraws[4], 0);
    TextDrawSetProportional(OfferListTextDraws[4], 1);
    TextDrawSetShadow(OfferListTextDraws[4], 1);
    TextDrawUseBox(OfferListTextDraws[4], 1);
    TextDrawBoxColor(OfferListTextDraws[4], 64);
    TextDrawTextSize(OfferListTextDraws[4], 0.0, 640.0);
    TextDrawSetSelectable(OfferListTextDraws[4], 0);

    OfferListTextDraws[5] = TextDrawCreate(0.0, 267.0, " ");
    TextDrawBackgroundColor(OfferListTextDraws[5], 0);
    TextDrawFont(OfferListTextDraws[5], 5);
    TextDrawSetPreviewModel(OfferListTextDraws[5], 17699);
    TextDrawSetPreviewRot(OfferListTextDraws[5], -4.0, 0.0, 71.0, 0.899999);
    TextDrawSetPreviewVehCol(OfferListTextDraws[5], 0, 0);
    TextDrawLetterSize(OfferListTextDraws[5], 0.50, 1.0);
    TextDrawColor(OfferListTextDraws[5], -1);
    TextDrawSetOutline(OfferListTextDraws[5], 0);
    TextDrawSetProportional(OfferListTextDraws[5], 1);
    TextDrawSetShadow(OfferListTextDraws[5], 1);
    TextDrawTextSize(OfferListTextDraws[5], 120.0, 120.0);
    TextDrawSetSelectable(OfferListTextDraws[5], 0);
    TextDrawSetPreviewModel(OfferListTextDraws[5], 17699);
    TextDrawSetPreviewRot(OfferListTextDraws[5], -4.0, 0.0, 71.0, 0.899999);
    TextDrawSetPreviewVehCol(OfferListTextDraws[5], 0, 0);
}

CreateHouseOfferPlayerTD(playerid) {
    OfferListPlayerTextDraws[playerid][0] = CreatePlayerTextDraw(playerid, 48.0, 360.0, " ");
    PlayerTextDrawAlignment(playerid, OfferListPlayerTextDraws[playerid][0], 2);
    PlayerTextDrawBackgroundColor(playerid, OfferListPlayerTextDraws[playerid][0], 0);
    PlayerTextDrawFont(playerid, OfferListPlayerTextDraws[playerid][0], 5);
    PlayerTextDrawLetterSize(playerid, OfferListPlayerTextDraws[playerid][0], 0.50, 1.0);
    PlayerTextDrawColor(playerid, OfferListPlayerTextDraws[playerid][0], -1);
    PlayerTextDrawSetOutline(playerid, OfferListPlayerTextDraws[playerid][0], 0);
    PlayerTextDrawSetProportional(playerid, OfferListPlayerTextDraws[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, (OfferListPlayerTextDraws[playerid][0], 1);
    PlayerTextDrawTextSize(playerid, OfferListPlayerTextDraws[playerid][0], 70.0, 70.0);
    PlayerTextDrawSetSelectable(playerid, OfferListPlayerTextDraws[playerid][0], 0);
    PlayerTextDrawSetPreviewModel(playerid, OfferListPlayerTextDraws[playerid][0], 3614);
    PlayerTextDrawSetPreviewRot(playerid, OfferListPlayerTextDraws[playerid][0], 0.0, 0.0, 0.0, 1.0);
    PlayerTextDrawSetPreviewVehCol(playerid, OfferListPlayerTextDraws[playerid][0], 0, 0);
    
    OfferListPlayerTextDraws[playerid][1] = CreatePlayerTextDraw(playerid, 167.399993, 360.0, " ");
    PlayerTextDrawAlignment(playerid, OfferListPlayerTextDraws[playerid][1], 2);
    PlayerTextDrawBackgroundColor(playerid, OfferListPlayerTextDraws[playerid][1], 0);
    PlayerTextDrawFont(playerid, OfferListPlayerTextDraws[playerid][1], 5);
    PlayerTextDrawLetterSize(playerid, OfferListPlayerTextDraws[playerid][1], 0.50, 1.0);
    PlayerTextDrawColor(playerid, OfferListPlayerTextDraws[playerid][1], -1);
    PlayerTextDrawSetOutline(playerid, OfferListPlayerTextDraws[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, OfferListPlayerTextDraws[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, (OfferListPlayerTextDraws[playerid][1], 1);
    PlayerTextDrawTextSize(playerid, OfferListPlayerTextDraws[playerid][1], 70.0, 70.0);
    PlayerTextDrawSetSelectable(playerid, OfferListPlayerTextDraws[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, OfferListPlayerTextDraws[playerid][1], 3614);
    PlayerTextDrawSetPreviewRot(playerid, OfferListPlayerTextDraws[playerid][1], 0.0, 0.0, 0.0, 1.0);
    PlayerTextDrawSetPreviewVehCol(playerid, OfferListPlayerTextDraws[playerid][1], 0, 0);
    
    OfferListPlayerTextDraws[playerid][2] = CreatePlayerTextDraw(playerid, 276.799987, 360.0, " ");
    PlayerTextDrawAlignment(playerid, OfferListPlayerTextDraws[playerid][2], 2);
    PlayerTextDrawBackgroundColor(playerid, OfferListPlayerTextDraws[playerid][2], 0);
    PlayerTextDrawFont(playerid, OfferListPlayerTextDraws[playerid][2], 5);
    PlayerTextDrawLetterSize(playerid, OfferListPlayerTextDraws[playerid][2], 0.50, 1.0);
    PlayerTextDrawColor(playerid, OfferListPlayerTextDraws[playerid][2], -1);
    PlayerTextDrawSetOutline(playerid, OfferListPlayerTextDraws[playerid][2], 0);
    PlayerTextDrawSetProportional(playerid, OfferListPlayerTextDraws[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, (OfferListPlayerTextDraws[playerid][2], 1);
    PlayerTextDrawTextSize(playerid, OfferListPlayerTextDraws[playerid][2], 70.0, 70.0);
    PlayerTextDrawSetSelectable(playerid, OfferListPlayerTextDraws[playerid][2], 0);
    PlayerTextDrawSetPreviewModel(playerid, OfferListPlayerTextDraws[playerid][2], 3614);
    PlayerTextDrawSetPreviewRot(playerid, OfferListPlayerTextDraws[playerid][2], 0.0, 0.0, 0.0, 1.0);
    PlayerTextDrawSetPreviewVehCol(playerid, OfferListPlayerTextDraws[playerid][2], 0, 0);
    
    OfferListPlayerTextDraws[playerid][3] = CreatePlayerTextDraw(playerid, 386.200012, 360.0, " ");
    PlayerTextDrawAlignment(playerid, OfferListPlayerTextDraws[playerid][3], 2);
    PlayerTextDrawBackgroundColor(playerid, OfferListPlayerTextDraws[playerid][3], 0);
    PlayerTextDrawFont(playerid, OfferListPlayerTextDraws[playerid][3], 5);
    PlayerTextDrawLetterSize(playerid, OfferListPlayerTextDraws[playerid][3], 0.50, 1.0);
    PlayerTextDrawColor(playerid, OfferListPlayerTextDraws[playerid][3], -1);
    PlayerTextDrawSetOutline(playerid, OfferListPlayerTextDraws[playerid][3], 0);
    PlayerTextDrawSetProportional(playerid, OfferListPlayerTextDraws[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, (OfferListPlayerTextDraws[playerid][3], 1);
    PlayerTextDrawTextSize(playerid, OfferListPlayerTextDraws[playerid][3], 70.0, 70.0);
    PlayerTextDrawSetSelectable(playerid, OfferListPlayerTextDraws[playerid][3], 0);
    PlayerTextDrawSetPreviewModel(playerid, OfferListPlayerTextDraws[playerid][3], 3614);
    PlayerTextDrawSetPreviewRot(playerid, OfferListPlayerTextDraws[playerid][3], 0.0, 0.0, 0.0, 1.0);
    PlayerTextDrawSetPreviewVehCol(playerid, OfferListPlayerTextDraws[playerid][3], 0, 0);
    
    OfferListPlayerTextDraws[playerid][4] = CreatePlayerTextDraw(playerid, 495.600006, 360.0, " ");
    PlayerTextDrawAlignment(playerid, OfferListPlayerTextDraws[playerid][4], 2);
    PlayerTextDrawBackgroundColor(playerid, OfferListPlayerTextDraws[playerid][4], 0);
    PlayerTextDrawFont(playerid, OfferListPlayerTextDraws[playerid][4], 5);
    PlayerTextDrawLetterSize(playerid, OfferListPlayerTextDraws[playerid][4], 0.50, 1.0);
    PlayerTextDrawColor(playerid, OfferListPlayerTextDraws[playerid][4], -1);
    PlayerTextDrawSetOutline(playerid, OfferListPlayerTextDraws[playerid][4], 0);
    PlayerTextDrawSetProportional(playerid, OfferListPlayerTextDraws[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, (OfferListPlayerTextDraws[playerid][4], 1);
    PlayerTextDrawTextSize(playerid, OfferListPlayerTextDraws[playerid][4], 70.0, 70.0);
    PlayerTextDrawSetSelectable(playerid, OfferListPlayerTextDraws[playerid][4], 0);
    PlayerTextDrawSetPreviewModel(playerid, OfferListPlayerTextDraws[playerid][4], 3614);
    PlayerTextDrawSetPreviewRot(playerid, OfferListPlayerTextDraws[playerid][4], 0.0, 0.0, 0.0, 1.0);
    PlayerTextDrawSetPreviewVehCol(playerid, OfferListPlayerTextDraws[playerid][4], 0, 0);
    
    OfferListPlayerTextDraws[playerid][5] = CreatePlayerTextDraw(playerid, 93.400001, 360.0, "~n~~n~~n~~n~~n~~n~~n~~n~Kaufen - ~g~$290.000");
    PlayerTextDrawAlignment(playerid, OfferListPlayerTextDraws[playerid][5], 2);
    PlayerTextDrawBackgroundColor(playerid, OfferListPlayerTextDraws[playerid][5], 255);
    PlayerTextDrawFont(playerid, OfferListPlayerTextDraws[playerid][5], 2);
    PlayerTextDrawLetterSize(playerid, OfferListPlayerTextDraws[playerid][5], 0.20, 1.0);
    PlayerTextDrawColor(playerid, OfferListPlayerTextDraws[playerid][5], -1);
    PlayerTextDrawSetOutline(playerid, OfferListPlayerTextDraws[playerid][5], 0);
    PlayerTextDrawSetProportional(playerid, OfferListPlayerTextDraws[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, (OfferListPlayerTextDraws[playerid][5], 1);
    PlayerTextDrawUseBox(playerid, OfferListPlayerTextDraws[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, OfferListPlayerTextDraws[playerid][5], 100);
    PlayerTextDrawTextSize(playerid, OfferListPlayerTextDraws[playerid][5], 90.0, 100.0);
    PlayerTextDrawSetSelectable(playerid, OfferListPlayerTextDraws[playerid][5], 1);

    OfferListPlayerTextDraws[playerid][6] = CreatePlayerTextDraw(playerid, 202.800003, 360.0, "~n~~n~~n~~n~~n~~n~~n~~n~Kaufen - ~g~$290.000");
    PlayerTextDrawAlignment(playerid, OfferListPlayerTextDraws[playerid][6], 2);
    PlayerTextDrawBackgroundColor(playerid, OfferListPlayerTextDraws[playerid][6], 255);
    PlayerTextDrawFont(playerid, OfferListPlayerTextDraws[playerid][6], 2);
    PlayerTextDrawLetterSize(playerid, OfferListPlayerTextDraws[playerid][6], 0.20, 1.0);
    PlayerTextDrawColor(playerid, OfferListPlayerTextDraws[playerid][6], -1);
    PlayerTextDrawSetOutline(playerid, OfferListPlayerTextDraws[playerid][6], 0);
    PlayerTextDrawSetProportional(playerid, OfferListPlayerTextDraws[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, (OfferListPlayerTextDraws[playerid][6], 1);
    PlayerTextDrawUseBox(playerid, OfferListPlayerTextDraws[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, OfferListPlayerTextDraws[playerid][6], 100);
    PlayerTextDrawTextSize(playerid, OfferListPlayerTextDraws[playerid][6], 90.0, 100.0);
    PlayerTextDrawSetSelectable(playerid, OfferListPlayerTextDraws[playerid][6], 1);

    OfferListPlayerTextDraws[playerid][7] = CreatePlayerTextDraw(playerid, 312.200012, 360.0, "~n~~n~~n~~n~~n~~n~~n~~n~Kaufen - ~g~$290.000");
    PlayerTextDrawAlignment(playerid, OfferListPlayerTextDraws[playerid][7], 2);
    PlayerTextDrawBackgroundColor(playerid, OfferListPlayerTextDraws[playerid][7], 255);
    PlayerTextDrawFont(playerid, OfferListPlayerTextDraws[playerid][7], 2);
    PlayerTextDrawLetterSize(playerid, OfferListPlayerTextDraws[playerid][7], 0.20, 1.0);
    PlayerTextDrawColor(playerid, OfferListPlayerTextDraws[playerid][7], -1);
    PlayerTextDrawSetOutline(playerid, OfferListPlayerTextDraws[playerid][7], 0);
    PlayerTextDrawSetProportional(playerid, OfferListPlayerTextDraws[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, (OfferListPlayerTextDraws[playerid][7], 1);
    PlayerTextDrawUseBox(playerid, OfferListPlayerTextDraws[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, OfferListPlayerTextDraws[playerid][7], 100);
    PlayerTextDrawTextSize(playerid, OfferListPlayerTextDraws[playerid][7], 90.0, 100.0);
    PlayerTextDrawSetSelectable(playerid, OfferListPlayerTextDraws[playerid][7], 1);

    OfferListPlayerTextDraws[playerid][8] = CreatePlayerTextDraw(playerid, 421.600006, 360.0, "~n~~n~~n~~n~~n~~n~~n~~n~Kaufen - ~g~$290.000");
    PlayerTextDrawAlignment(playerid, OfferListPlayerTextDraws[playerid][8], 2);
    PlayerTextDrawBackgroundColor(playerid, OfferListPlayerTextDraws[playerid][8], 255);
    PlayerTextDrawFont(playerid, OfferListPlayerTextDraws[playerid][8], 2);
    PlayerTextDrawLetterSize(playerid, OfferListPlayerTextDraws[playerid][8], 0.20, 1.0);
    PlayerTextDrawColor(playerid, OfferListPlayerTextDraws[playerid][8], -1);
    PlayerTextDrawSetOutline(playerid, OfferListPlayerTextDraws[playerid][8], 0);
    PlayerTextDrawSetProportional(playerid, OfferListPlayerTextDraws[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, (OfferListPlayerTextDraws[playerid][8], 1);
    PlayerTextDrawUseBox(playerid, OfferListPlayerTextDraws[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, OfferListPlayerTextDraws[playerid][8], 100);
    PlayerTextDrawTextSize(playerid, OfferListPlayerTextDraws[playerid][8], 90.0, 100.0);
    PlayerTextDrawSetSelectable(playerid, OfferListPlayerTextDraws[playerid][8], 1);

    OfferListPlayerTextDraws[playerid][9] = CreatePlayerTextDraw(playerid, 531.0, 360.0, "~n~~n~~n~~n~~n~~n~~n~~n~Kaufen - ~g~$290.000");
    PlayerTextDrawAlignment(playerid, OfferListPlayerTextDraws[playerid][9], 2);
    PlayerTextDrawBackgroundColor(playerid, OfferListPlayerTextDraws[playerid][9], 255);
    PlayerTextDrawFont(playerid, OfferListPlayerTextDraws[playerid][9], 2);
    PlayerTextDrawLetterSize(playerid, OfferListPlayerTextDraws[playerid][9], 0.20, 1.0);
    PlayerTextDrawColor(playerid, OfferListPlayerTextDraws[playerid][9], -1);
    PlayerTextDrawSetOutline(playerid, OfferListPlayerTextDraws[playerid][9], 0);
    PlayerTextDrawSetProportional(playerid, OfferListPlayerTextDraws[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, (OfferListPlayerTextDraws[playerid][9], 1);
    PlayerTextDrawUseBox(playerid, OfferListPlayerTextDraws[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, OfferListPlayerTextDraws[playerid][9], 100);
    PlayerTextDrawTextSize(playerid, OfferListPlayerTextDraws[playerid][9], 90.0, 100.0);
    PlayerTextDrawSetSelectable(playerid, OfferListPlayerTextDraws[playerid][9], 1);
}

ChangeHouseOfferPlayerTDModel(playerid, element, newModel) {
    PlayerTextDrawSetPreviewModel(playerid, OfferListPlayerTextDraws[playerid][element], newModel);
}

ChangeHouseOfferPlayerTDPrice(playerid, element, newPrice) {
    new string[64];
    format(string, sizeof string, "~n~~n~~n~~n~~n~~n~~n~~n~Kaufen - ~g~$%s", FormatNumber(newPrice));
    PlayerTextDrawSetString(playerid, OfferListPlayerTextDraws[playerid][element+5], string);
}

ShowPlayerHouseOfferTD(playerid) {
    for(new i = 0; i < sizeof OfferListTextDraws; i++) {
        TextDrawShowForPlayer(playerid, OfferListTextDraws[i]);
    }
    for(new i = 0; i < sizeof OfferListPlayerTextDraws[]; i++) {
        PlayerTextDrawShow(playerid, OfferListPlayerTextDraws[playerid][i]);
    }
}