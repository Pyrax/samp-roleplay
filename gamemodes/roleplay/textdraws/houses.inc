#if defined _INCLUDED_TEXTDRAWS_HOUSES
    #endinput
#endif
#define _INCLUDED_TEXTDRAWS_HOUSES

//-----------------------------------------------------

#include <YSI\y_hooks>

//-----------------------------------------------------

static Text:offerListTextDraws[6];
static PlayerText:offerListPlayerTextDraws[MAX_PLAYERS][10];
static houseOffers[MAX_PLAYERS][5][3];
static Iterator:houseOffersIterator[MAX_PLAYERS]<5>;

hook OnGameModeInit() {
    CreateHouseOfferTD();
    Iter_Init(houseOffersIterator);
}

hook OnPlayerConnect(playerid) {
    offerListPlayerTextDraws[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
}

hook OnPlayerDisconnect(playerid, reason) {
    HidePlayerHouseOfferTD(playerid);
    DestroyPlayerHouseOfferTD(playerid);
}

CreateHouseOfferTD() {
    offerListTextDraws[0] = TextDrawCreate(320.0, 353.0, "~n~~n~~n~");
    TextDrawAlignment(offerListTextDraws[0], 2);
    TextDrawBackgroundColor(offerListTextDraws[0], 255);
    TextDrawFont(offerListTextDraws[0], 1);
    TextDrawLetterSize(offerListTextDraws[0], 0.50, 5.0);
    TextDrawColor(offerListTextDraws[0], 255);
    TextDrawSetOutline(offerListTextDraws[0], 0);
    TextDrawSetProportional(offerListTextDraws[0], 1);
    TextDrawSetShadow(offerListTextDraws[0], 1);
    TextDrawUseBox(offerListTextDraws[0], 1);
    TextDrawBoxColor(offerListTextDraws[0], 252651584);
    TextDrawTextSize(offerListTextDraws[0], 180.0, 650.0);
    
    offerListTextDraws[1] = TextDrawCreate(320.0, 354.0, "~n~");
    TextDrawAlignment(offerListTextDraws[1], 2);
    TextDrawBackgroundColor(offerListTextDraws[1], 255);
    TextDrawFont(offerListTextDraws[1], 1);
    TextDrawLetterSize(offerListTextDraws[1], 0.80, 0.0);
    TextDrawColor(offerListTextDraws[1], -1);
    TextDrawSetOutline(offerListTextDraws[1], 0);
    TextDrawSetProportional(offerListTextDraws[1], 1);
    TextDrawSetShadow(offerListTextDraws[1], 1);
    TextDrawUseBox(offerListTextDraws[1], 1);
    TextDrawBoxColor(offerListTextDraws[1], 64);
    TextDrawTextSize(offerListTextDraws[1], 0.0, 650.0);

    offerListTextDraws[2] = TextDrawCreate(628.0, 357.0, " ~n~ >>~n~ ~n~");
    TextDrawAlignment(offerListTextDraws[2], 2);
    TextDrawBackgroundColor(offerListTextDraws[2], 32);
    TextDrawFont(offerListTextDraws[2], 3);
    TextDrawLetterSize(offerListTextDraws[2], 0.230000, 3.20);
    TextDrawColor(offerListTextDraws[2], -1);
    TextDrawSetOutline(offerListTextDraws[2], 1);
    TextDrawSetProportional(offerListTextDraws[2], 1);
    TextDrawUseBox(offerListTextDraws[2], 1);
    TextDrawBoxColor(offerListTextDraws[2], 842170448);
    TextDrawTextSize(offerListTextDraws[2], 160.0, 21.0);
    TextDrawSetSelectable(offerListTextDraws[2], 1);

    offerListTextDraws[3] = TextDrawCreate(9.0, 357.0, " ~n~ <<~n~ ~n~");
    TextDrawAlignment(offerListTextDraws[3], 2);
    TextDrawBackgroundColor(offerListTextDraws[3], 32);
    TextDrawFont(offerListTextDraws[3], 3);
    TextDrawLetterSize(offerListTextDraws[3], 0.219999, 3.20);
    TextDrawColor(offerListTextDraws[3], -1);
    TextDrawSetOutline(offerListTextDraws[3], 0);
    TextDrawSetProportional(offerListTextDraws[3], 1);
    TextDrawSetShadow(offerListTextDraws[3], 1);
    TextDrawUseBox(offerListTextDraws[3], 1);
    TextDrawBoxColor(offerListTextDraws[3], 842170448);
    TextDrawTextSize(offerListTextDraws[3], 90.0, 25.0);
    TextDrawSetSelectable(offerListTextDraws[3], 1);
    
    offerListTextDraws[4] = TextDrawCreate(320.0, 447.0, "~n~");
    TextDrawAlignment(offerListTextDraws[4], 2);
    TextDrawBackgroundColor(offerListTextDraws[4], 255);
    TextDrawFont(offerListTextDraws[4], 1);
    TextDrawLetterSize(offerListTextDraws[4], 0.80, 1.299999);
    TextDrawColor(offerListTextDraws[4], -1);
    TextDrawSetOutline(offerListTextDraws[4], 0);
    TextDrawSetProportional(offerListTextDraws[4], 1);
    TextDrawSetShadow(offerListTextDraws[4], 1);
    TextDrawUseBox(offerListTextDraws[4], 1);
    TextDrawBoxColor(offerListTextDraws[4], 64);
    TextDrawTextSize(offerListTextDraws[4], 0.0, 640.0);

    offerListTextDraws[5] = TextDrawCreate(0.0, 267.0, " ");
    TextDrawBackgroundColor(offerListTextDraws[5], 0);
    TextDrawFont(offerListTextDraws[5], 5);
    TextDrawSetPreviewModel(offerListTextDraws[5], 17699);
    TextDrawSetPreviewRot(offerListTextDraws[5], -4.0, 0.0, 71.0, 0.899999);
    TextDrawSetPreviewVehCol(offerListTextDraws[5], 0, 0);
    TextDrawLetterSize(offerListTextDraws[5], 0.50, 1.0);
    TextDrawColor(offerListTextDraws[5], -1);
    TextDrawSetOutline(offerListTextDraws[5], 0);
    TextDrawSetProportional(offerListTextDraws[5], 1);
    TextDrawSetShadow(offerListTextDraws[5], 1);
    TextDrawTextSize(offerListTextDraws[5], 120.0, 120.0);
    TextDrawSetPreviewModel(offerListTextDraws[5], 17699);
    TextDrawSetPreviewRot(offerListTextDraws[5], -4.0, 0.0, 71.0, 0.899999);
    TextDrawSetPreviewVehCol(offerListTextDraws[5], 0, 0);
}

CreateHouseOfferPlayerTD(playerid) {
    if(offerListPlayerTextDraws[playerid][0] != PlayerText:INVALID_TEXT_DRAW) {
        return;
    }
    
    offerListPlayerTextDraws[playerid][0] = CreatePlayerTextDraw(playerid, 48.0, 360.0, " ");
    PlayerTextDrawAlignment(playerid, offerListPlayerTextDraws[playerid][0], 2);
    PlayerTextDrawBackgroundColor(playerid, offerListPlayerTextDraws[playerid][0], 0);
    PlayerTextDrawFont(playerid, offerListPlayerTextDraws[playerid][0], 5);
    PlayerTextDrawLetterSize(playerid, offerListPlayerTextDraws[playerid][0], 0.50, 1.0);
    PlayerTextDrawColor(playerid, offerListPlayerTextDraws[playerid][0], -1);
    PlayerTextDrawSetOutline(playerid, offerListPlayerTextDraws[playerid][0], 0);
    PlayerTextDrawSetProportional(playerid, offerListPlayerTextDraws[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, offerListPlayerTextDraws[playerid][0], 1);
    PlayerTextDrawTextSize(playerid, offerListPlayerTextDraws[playerid][0], 70.0, 70.0);
    PlayerTextDrawSetPreviewModel(playerid, offerListPlayerTextDraws[playerid][0], 3614);
    PlayerTextDrawSetPreviewRot(playerid, offerListPlayerTextDraws[playerid][0], 0.0, 0.0, 0.0, 1.0);
    PlayerTextDrawSetPreviewVehCol(playerid, offerListPlayerTextDraws[playerid][0], 0, 0);
    
    offerListPlayerTextDraws[playerid][1] = CreatePlayerTextDraw(playerid, 167.399993, 360.0, " ");
    PlayerTextDrawAlignment(playerid, offerListPlayerTextDraws[playerid][1], 2);
    PlayerTextDrawBackgroundColor(playerid, offerListPlayerTextDraws[playerid][1], 0);
    PlayerTextDrawFont(playerid, offerListPlayerTextDraws[playerid][1], 5);
    PlayerTextDrawLetterSize(playerid, offerListPlayerTextDraws[playerid][1], 0.50, 1.0);
    PlayerTextDrawColor(playerid, offerListPlayerTextDraws[playerid][1], -1);
    PlayerTextDrawSetOutline(playerid, offerListPlayerTextDraws[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, offerListPlayerTextDraws[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, offerListPlayerTextDraws[playerid][1], 1);
    PlayerTextDrawTextSize(playerid, offerListPlayerTextDraws[playerid][1], 70.0, 70.0);
    PlayerTextDrawSetPreviewModel(playerid, offerListPlayerTextDraws[playerid][1], 3614);
    PlayerTextDrawSetPreviewRot(playerid, offerListPlayerTextDraws[playerid][1], 0.0, 0.0, 0.0, 1.0);
    PlayerTextDrawSetPreviewVehCol(playerid, offerListPlayerTextDraws[playerid][1], 0, 0);
    
    offerListPlayerTextDraws[playerid][2] = CreatePlayerTextDraw(playerid, 276.799987, 360.0, " ");
    PlayerTextDrawAlignment(playerid, offerListPlayerTextDraws[playerid][2], 2);
    PlayerTextDrawBackgroundColor(playerid, offerListPlayerTextDraws[playerid][2], 0);
    PlayerTextDrawFont(playerid, offerListPlayerTextDraws[playerid][2], 5);
    PlayerTextDrawLetterSize(playerid, offerListPlayerTextDraws[playerid][2], 0.50, 1.0);
    PlayerTextDrawColor(playerid, offerListPlayerTextDraws[playerid][2], -1);
    PlayerTextDrawSetOutline(playerid, offerListPlayerTextDraws[playerid][2], 0);
    PlayerTextDrawSetProportional(playerid, offerListPlayerTextDraws[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, offerListPlayerTextDraws[playerid][2], 1);
    PlayerTextDrawTextSize(playerid, offerListPlayerTextDraws[playerid][2], 70.0, 70.0);
    PlayerTextDrawSetPreviewModel(playerid, offerListPlayerTextDraws[playerid][2], 3614);
    PlayerTextDrawSetPreviewRot(playerid, offerListPlayerTextDraws[playerid][2], 0.0, 0.0, 0.0, 1.0);
    PlayerTextDrawSetPreviewVehCol(playerid, offerListPlayerTextDraws[playerid][2], 0, 0);
    
    offerListPlayerTextDraws[playerid][3] = CreatePlayerTextDraw(playerid, 386.200012, 360.0, " ");
    PlayerTextDrawAlignment(playerid, offerListPlayerTextDraws[playerid][3], 2);
    PlayerTextDrawBackgroundColor(playerid, offerListPlayerTextDraws[playerid][3], 0);
    PlayerTextDrawFont(playerid, offerListPlayerTextDraws[playerid][3], 5);
    PlayerTextDrawLetterSize(playerid, offerListPlayerTextDraws[playerid][3], 0.50, 1.0);
    PlayerTextDrawColor(playerid, offerListPlayerTextDraws[playerid][3], -1);
    PlayerTextDrawSetOutline(playerid, offerListPlayerTextDraws[playerid][3], 0);
    PlayerTextDrawSetProportional(playerid, offerListPlayerTextDraws[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, offerListPlayerTextDraws[playerid][3], 1);
    PlayerTextDrawTextSize(playerid, offerListPlayerTextDraws[playerid][3], 70.0, 70.0);
    PlayerTextDrawSetPreviewModel(playerid, offerListPlayerTextDraws[playerid][3], 3614);
    PlayerTextDrawSetPreviewRot(playerid, offerListPlayerTextDraws[playerid][3], 0.0, 0.0, 0.0, 1.0);
    PlayerTextDrawSetPreviewVehCol(playerid, offerListPlayerTextDraws[playerid][3], 0, 0);
    
    offerListPlayerTextDraws[playerid][4] = CreatePlayerTextDraw(playerid, 495.600006, 360.0, " ");
    PlayerTextDrawAlignment(playerid, offerListPlayerTextDraws[playerid][4], 2);
    PlayerTextDrawBackgroundColor(playerid, offerListPlayerTextDraws[playerid][4], 0);
    PlayerTextDrawFont(playerid, offerListPlayerTextDraws[playerid][4], 5);
    PlayerTextDrawLetterSize(playerid, offerListPlayerTextDraws[playerid][4], 0.50, 1.0);
    PlayerTextDrawColor(playerid, offerListPlayerTextDraws[playerid][4], -1);
    PlayerTextDrawSetOutline(playerid, offerListPlayerTextDraws[playerid][4], 0);
    PlayerTextDrawSetProportional(playerid, offerListPlayerTextDraws[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, offerListPlayerTextDraws[playerid][4], 1);
    PlayerTextDrawTextSize(playerid, offerListPlayerTextDraws[playerid][4], 70.0, 70.0);
    PlayerTextDrawSetPreviewModel(playerid, offerListPlayerTextDraws[playerid][4], 3614);
    PlayerTextDrawSetPreviewRot(playerid, offerListPlayerTextDraws[playerid][4], 0.0, 0.0, 0.0, 1.0);
    PlayerTextDrawSetPreviewVehCol(playerid, offerListPlayerTextDraws[playerid][4], 0, 0);
    
    offerListPlayerTextDraws[playerid][5] = CreatePlayerTextDraw(playerid, 93.400001, 360.0, "~n~~n~~n~~n~~n~~n~~n~~n~~g~$290.000");
    PlayerTextDrawAlignment(playerid, offerListPlayerTextDraws[playerid][5], 2);
    PlayerTextDrawBackgroundColor(playerid, offerListPlayerTextDraws[playerid][5], 255);
    PlayerTextDrawFont(playerid, offerListPlayerTextDraws[playerid][5], 2);
    PlayerTextDrawLetterSize(playerid, offerListPlayerTextDraws[playerid][5], 0.20, 1.0);
    PlayerTextDrawColor(playerid, offerListPlayerTextDraws[playerid][5], -1);
    PlayerTextDrawSetOutline(playerid, offerListPlayerTextDraws[playerid][5], 0);
    PlayerTextDrawSetProportional(playerid, offerListPlayerTextDraws[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, offerListPlayerTextDraws[playerid][5], 1);
    PlayerTextDrawUseBox(playerid, offerListPlayerTextDraws[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, offerListPlayerTextDraws[playerid][5], 100);
    PlayerTextDrawTextSize(playerid, offerListPlayerTextDraws[playerid][5], 90.0, 100.0);
    PlayerTextDrawSetSelectable(playerid, offerListPlayerTextDraws[playerid][5], 1);

    offerListPlayerTextDraws[playerid][6] = CreatePlayerTextDraw(playerid, 202.800003, 360.0, "~n~~n~~n~~n~~n~~n~~n~~n~~g~$290.000");
    PlayerTextDrawAlignment(playerid, offerListPlayerTextDraws[playerid][6], 2);
    PlayerTextDrawBackgroundColor(playerid, offerListPlayerTextDraws[playerid][6], 255);
    PlayerTextDrawFont(playerid, offerListPlayerTextDraws[playerid][6], 2);
    PlayerTextDrawLetterSize(playerid, offerListPlayerTextDraws[playerid][6], 0.20, 1.0);
    PlayerTextDrawColor(playerid, offerListPlayerTextDraws[playerid][6], -1);
    PlayerTextDrawSetOutline(playerid, offerListPlayerTextDraws[playerid][6], 0);
    PlayerTextDrawSetProportional(playerid, offerListPlayerTextDraws[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, offerListPlayerTextDraws[playerid][6], 1);
    PlayerTextDrawUseBox(playerid, offerListPlayerTextDraws[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, offerListPlayerTextDraws[playerid][6], 100);
    PlayerTextDrawTextSize(playerid, offerListPlayerTextDraws[playerid][6], 90.0, 100.0);
    PlayerTextDrawSetSelectable(playerid, offerListPlayerTextDraws[playerid][6], 1);

    offerListPlayerTextDraws[playerid][7] = CreatePlayerTextDraw(playerid, 312.200012, 360.0, "~n~~n~~n~~n~~n~~n~~n~~n~~g~$290.000");
    PlayerTextDrawAlignment(playerid, offerListPlayerTextDraws[playerid][7], 2);
    PlayerTextDrawBackgroundColor(playerid, offerListPlayerTextDraws[playerid][7], 255);
    PlayerTextDrawFont(playerid, offerListPlayerTextDraws[playerid][7], 2);
    PlayerTextDrawLetterSize(playerid, offerListPlayerTextDraws[playerid][7], 0.20, 1.0);
    PlayerTextDrawColor(playerid, offerListPlayerTextDraws[playerid][7], -1);
    PlayerTextDrawSetOutline(playerid, offerListPlayerTextDraws[playerid][7], 0);
    PlayerTextDrawSetProportional(playerid, offerListPlayerTextDraws[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, offerListPlayerTextDraws[playerid][7], 1);
    PlayerTextDrawUseBox(playerid, offerListPlayerTextDraws[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, offerListPlayerTextDraws[playerid][7], 100);
    PlayerTextDrawTextSize(playerid, offerListPlayerTextDraws[playerid][7], 90.0, 100.0);
    PlayerTextDrawSetSelectable(playerid, offerListPlayerTextDraws[playerid][7], 1);

    offerListPlayerTextDraws[playerid][8] = CreatePlayerTextDraw(playerid, 421.600006, 360.0, "~n~~n~~n~~n~~n~~n~~n~~n~~g~$290.000");
    PlayerTextDrawAlignment(playerid, offerListPlayerTextDraws[playerid][8], 2);
    PlayerTextDrawBackgroundColor(playerid, offerListPlayerTextDraws[playerid][8], 255);
    PlayerTextDrawFont(playerid, offerListPlayerTextDraws[playerid][8], 2);
    PlayerTextDrawLetterSize(playerid, offerListPlayerTextDraws[playerid][8], 0.20, 1.0);
    PlayerTextDrawColor(playerid, offerListPlayerTextDraws[playerid][8], -1);
    PlayerTextDrawSetOutline(playerid, offerListPlayerTextDraws[playerid][8], 0);
    PlayerTextDrawSetProportional(playerid, offerListPlayerTextDraws[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, offerListPlayerTextDraws[playerid][8], 1);
    PlayerTextDrawUseBox(playerid, offerListPlayerTextDraws[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, offerListPlayerTextDraws[playerid][8], 100);
    PlayerTextDrawTextSize(playerid, offerListPlayerTextDraws[playerid][8], 90.0, 100.0);
    PlayerTextDrawSetSelectable(playerid, offerListPlayerTextDraws[playerid][8], 1);

    offerListPlayerTextDraws[playerid][9] = CreatePlayerTextDraw(playerid, 531.0, 360.0, "~n~~n~~n~~n~~n~~n~~n~~n~~g~$290.000");
    PlayerTextDrawAlignment(playerid, offerListPlayerTextDraws[playerid][9], 2);
    PlayerTextDrawBackgroundColor(playerid, offerListPlayerTextDraws[playerid][9], 255);
    PlayerTextDrawFont(playerid, offerListPlayerTextDraws[playerid][9], 2);
    PlayerTextDrawLetterSize(playerid, offerListPlayerTextDraws[playerid][9], 0.20, 1.0);
    PlayerTextDrawColor(playerid, offerListPlayerTextDraws[playerid][9], -1);
    PlayerTextDrawSetOutline(playerid, offerListPlayerTextDraws[playerid][9], 0);
    PlayerTextDrawSetProportional(playerid, offerListPlayerTextDraws[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, offerListPlayerTextDraws[playerid][9], 1);
    PlayerTextDrawUseBox(playerid, offerListPlayerTextDraws[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, offerListPlayerTextDraws[playerid][9], 100);
    PlayerTextDrawTextSize(playerid, offerListPlayerTextDraws[playerid][9], 90.0, 100.0);
    PlayerTextDrawSetSelectable(playerid, offerListPlayerTextDraws[playerid][9], 1);
}

PushPlayerHouseOffer(playerid, houseid = -1, model = -1, price = -1) {
    new idx = Iter_Free(houseOffersIterator[playerid]);
    
    if(idx == -1) {
        // array is full, so use the last element of the array to insert the new house offer
        idx = sizeof houseOffers[] - 1;
        
        // then move all elements one up so that idx 5 becomes 4... and so on
        for(new i = 0; i < idx; i++) {
            houseOffers[playerid][i][0] = houseOffers[playerid][i+1][0];
            houseOffers[playerid][i][1] = houseOffers[playerid][i+1][1];
            houseOffers[playerid][i][2] = houseOffers[playerid][i+1][2];
        }
    }
    
    if(model == -1) {
        PlayerTextDrawFont(playerid, offerListPlayerTextDraws[playerid][idx], 0);
    } else {
        PlayerTextDrawFont(playerid, offerListPlayerTextDraws[playerid][idx], 5);
        PlayerTextDrawSetPreviewModel(playerid, offerListPlayerTextDraws[playerid][idx], model);
    }
    
    if(price == -1) {
        PlayerTextDrawSetString(playerid, offerListPlayerTextDraws[playerid][idx+5], " ");
        PlayerTextDrawSetSelectable(playerid, offerListPlayerTextDraws[playerid][idx+5], 0);
    } else {
        new string[64];
        format(string, sizeof string, "~n~~n~~n~~n~~n~~n~~n~~n~~g~$%s", FormatNumber(price));
        PlayerTextDrawSetString(playerid, offerListPlayerTextDraws[playerid][idx+5], string);
        PlayerTextDrawSetSelectable(playerid, offerListPlayerTextDraws[playerid][idx+5], 1);
    }
    
    houseOffers[playerid][idx][0] = model;
    houseOffers[playerid][idx][1] = price;
    houseOffers[playerid][idx][2] = houseid;
    
    Iter_Remove(houseOffersIterator[playerid], idx);
    if(model != -1 && price != -1) {
        Iter_Add(houseOffersIterator[playerid], idx);
    }
}

ReversePushPlayerHouseOffer(playerid, houseid = -1, model = -1, price = -1) {
    new idx = Iter_Free(houseOffersIterator[playerid]);
    
    if(idx != -1) {
        Iter_Add(houseOffersIterator[playerid], idx);
    }
    
    for(new i = Iter_Last(houseOffersIterator[playerid]); i > 0; i--) {
        houseOffers[playerid][i][0] = houseOffers[playerid][i-1][0];
        houseOffers[playerid][i][1] = houseOffers[playerid][i-1][1];
        houseOffers[playerid][i][2] = houseOffers[playerid][i-1][2];
    }
    
    if(model != -1) {
        PlayerTextDrawFont(playerid, offerListPlayerTextDraws[playerid][0], 5);
        PlayerTextDrawSetPreviewModel(playerid, offerListPlayerTextDraws[playerid][0], model);
    }
    
    if(price != -1) {
        new string[64];
        format(string, sizeof string, "~n~~n~~n~~n~~n~~n~~n~~n~~g~$%s", FormatNumber(price));
        PlayerTextDrawSetString(playerid, offerListPlayerTextDraws[playerid][5], string);
        PlayerTextDrawSetSelectable(playerid, offerListPlayerTextDraws[playerid][5], 1);
    }
    
    houseOffers[playerid][0][0] = model;
    houseOffers[playerid][0][1] = price;
    houseOffers[playerid][0][2] = houseid;
}

ShowPlayerHouseOfferTD(playerid) {
    foreach(new i : houseOffersIterator[playerid]) {
        PlayerTextDrawShow(playerid, offerListPlayerTextDraws[playerid][i]);
        PlayerTextDrawShow(playerid, offerListPlayerTextDraws[playerid][i+5]);
    }
    for(new i = 0; i < sizeof offerListTextDraws; i++) {
        TextDrawShowForPlayer(playerid, offerListTextDraws[i]);
    }
    SelectTextDraw(playerid, HOVER_COLOR_DEFAULT);
}

HidePlayerHouseOfferTD(playerid) {
    for(new i = 0; i < sizeof offerListPlayerTextDraws[]; i++) {
        PlayerTextDrawHide(playerid, offerListPlayerTextDraws[playerid][i]);
    }
    for(new i = 0; i < sizeof offerListTextDraws; i++) {
        TextDrawHideForPlayer(playerid, offerListTextDraws[i]);
    }
}

DestroyPlayerHouseOfferTD(playerid) {
    for(new i = 0; i < sizeof offerListPlayerTextDraws[]; i++) {
        PlayerTextDrawDestroy(playerid, offerListPlayerTextDraws[playerid][i]);
    }
    Iter_Clear(houseOffersIterator[playerid]);
}

SetPlayerActiveHouseOfferID(playerid, houseid) {
    new idx = 0;
    foreach(new i : houseOffersIterator[playerid]) {
        if(houseOffers[playerid][i][2] == houseid) {
            idx = i;
            break;
        }
    }
    SetPlayerLookAtHouse(playerid, houseOffers[playerid][idx][2]);
}

SetPlayerActiveHouseOffer(playerid, idx) {
    SetPlayerLookAtHouse(playerid, houseOffers[playerid][idx][2]);
}

hook OnPlayerClickTextDraw(playerid, Text:clickedid) {
    if(clickedid == offerListTextDraws[2]) {
        // next page
        CallLocalFunction("OnNextHouseOfferPage", "d", playerid);
        return 1;
    } else if(clickedid == offerListTextDraws[3]) {
        // previous page
        CallLocalFunction("OnPrevHouseOfferPage", "d", playerid);
        return 1;
    } else if(clickedid == Text:INVALID_TEXT_DRAW && offerListPlayerTextDraws[playerid][0] != PlayerText:INVALID_TEXT_DRAW) {
        // hide menu
        CancelSelectTextDraw(playerid);
        HidePlayerHouseOfferTD(playerid);
        DestroyPlayerHouseOfferTD(playerid);
        
        offerListPlayerTextDraws[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
        
        TogglePlayerSpectating(playerid, false);
        SetPlayerVirtualWorld(playerid, VW_DEFAULT);
        return 1;
    }
    return 0;
}

hook OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid) {
    foreach(new i : houseOffersIterator[playerid]) {
        if(playertextid == offerListPlayerTextDraws[playerid][i+5]) {
            SetPlayerActiveHouseOffer(playerid, i);
        }
    }
    return 0;
}