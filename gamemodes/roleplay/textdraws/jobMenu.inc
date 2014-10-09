#if defined _INCLUDED_TEXTDRAWS_JOBMENU
    #endinput
#endif
#define _INCLUDED_TEXTDRAWS_JOBMENU

//-----------------------------------------------------

#include <YSI\y_hooks>

//-----------------------------------------------------

static Text:jobListHeader;
static Text:jobListTextDraws[MAX_JOBS*3];
static Iterator:jobListIterator<MAX_JOBS>;
static bool:playerJobMenu[MAX_PLAYERS];

//-----------------------------------------------------

CreateJobMenuTD() {
    jobListHeader = TextDrawCreate(320.0, 120.0, "Jobangebote");
    TextDrawAlignment(jobListHeader, 2);
    TextDrawBackgroundColor(jobListHeader, 255);
    TextDrawFont(jobListHeader, 1);
    TextDrawLetterSize(jobListHeader, 0.50, 2.0);
    TextDrawSetOutline(jobListHeader, 0);
    TextDrawSetProportional(jobListHeader, 1);
    TextDrawSetShadow(jobListHeader, 1);
    TextDrawUseBox(jobListHeader, 1);
    TextDrawBoxColor(jobListHeader, 180);
    TextDrawTextSize(jobListHeader, 40.0, 240.0);
    
    foreach(new i : g_JobIterator) {
        // only display jobs which do not need an invitation
        if(g_Job[i][g_ID] > 0 && !g_Job[i][g_inviteOnly]) {
            jobListTextDraws[i] = TextDrawCreate(320.0, 141.0, "                                     >");
            TextDrawAlignment(jobListTextDraws[i], 2);
            TextDrawBackgroundColor(jobListTextDraws[i], 255);
            TextDrawFont(jobListTextDraws[i], 2);
            TextDrawLetterSize(jobListTextDraws[i], 0.50, 3.0);
            TextDrawColor(jobListTextDraws[i], -1);
            TextDrawSetOutline(jobListTextDraws[i], 0);
            TextDrawSetProportional(jobListTextDraws[i], 1);
            TextDrawSetShadow(jobListTextDraws[i], 1);
            TextDrawUseBox(jobListTextDraws[i], 1);
            TextDrawBoxColor(jobListTextDraws[i], 128);
            TextDrawTextSize(jobListTextDraws[i], 26.0, 240.0);
            TextDrawSetSelectable(jobListTextDraws[i], 1);

            jobListTextDraws[i+1] = TextDrawCreate(240.0, 146.0, "Company name");
            TextDrawBackgroundColor(jobListTextDraws[i+1], 255);
            TextDrawFont(jobListTextDraws[i+1], 0);
            TextDrawLetterSize(jobListTextDraws[i+1], 0.50, 1.50);
            TextDrawColor(jobListTextDraws[i+1], -1);
            TextDrawSetOutline(jobListTextDraws[i+1], 0);
            TextDrawSetProportional(jobListTextDraws[i+1], 1);
            TextDrawSetShadow(jobListTextDraws[i+1], 1);
            TextDrawTextSize(jobListTextDraws[i+1], 440.0, 0.0);

            jobListTextDraws[i+2] = TextDrawCreate(207.0, 136.0, "previewModel");
            TextDrawBackgroundColor(jobListTextDraws[i+2], -256);
            TextDrawFont(jobListTextDraws[i+2], 5);
            TextDrawColor(jobListTextDraws[i+2], -1);
            TextDrawSetOutline(jobListTextDraws[i+2], 0);
            TextDrawSetProportional(jobListTextDraws[i+2], 1);
            TextDrawSetShadow(jobListTextDraws[i+2], 1);
            TextDrawUseBox(jobListTextDraws[i+2], 1);
            TextDrawBoxColor(jobListTextDraws[i+2], -256);
            TextDrawTextSize(jobListTextDraws[i+2], 33.0, 33.0);
            TextDrawSetPreviewModel(jobListTextDraws[i+2], 431);
            TextDrawSetPreviewRot(jobListTextDraws[i+2], -12.0, 0.0, -17.0, 0.80);
            TextDrawSetPreviewVehCol(jobListTextDraws[i+2], 0, 0);
            
            Iter_Add(jobListIterator, i);
        }
    }
}

ShowPlayerJobMenuTD(playerid) {
    foreach(new i : jobListIterator) {
        TextDrawShowForPlayer(playerid, jobListTextDraws[i]);
        TextDrawShowForPlayer(playerid, jobListTextDraws[i+1]);
        TextDrawShowForPlayer(playerid, jobListTextDraws[i+2]);
    }
}

HidePlayerJobMenuTD(playerid) {
    foreach(new i : jobListIterator) {
        TextDrawHideForPlayer(playerid, jobListTextDraws[i]);
        TextDrawHideForPlayer(playerid, jobListTextDraws[i+1]);
        TextDrawHideForPlayer(playerid, jobListTextDraws[i+2]);
    }
}

hook OnPlayerDisconnect(playerid, reason) {
    HidePlayerJobMenuTD(playerid);
    playerJobMenu[playerid] = false;
}

hook OnPlayerClickTextDraw(playerid, Text:clickedid) {
    foreach(new i : jobListIterator) {
        if(clickedid == jobListTextDraws[i]) {
            ShowPlayerJobOfferDialog(playerid, i);
            return 1;
        }
    }
    
    if(clickedid == Text:INVALID_TEXT_DRAW && playerJobMenu[playerid]) {
        // hide menu
        CancelSelectTextDraw(playerid);
        HidePlayerJobMenuTD(playerid);
        
        TogglePlayerSpectating(playerid, false);
        SetPlayerVirtualWorld(playerid, VW_DEFAULT);
        return 1;
    }
    return 0;
}

hook OnPlayerSpawn(playerid) {
    if(playerJobMenu[playerid]) {
        playerJobMenu[playerid] = !playerJobMenu[playerid];
        SetPlayerToLabourOffice(playerid);
    }
    return 1;
}