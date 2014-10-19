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
    
    new counter = 0;
    foreach(new i : g_JobIterator) {
        // only display jobs which do not need an invitation
        if(g_Job[i][g_ID] > 0 && !g_Job[i][g_inviteOnly]) {
            jobListTextDraws[counter*3] = TextDrawCreate(320.0, 141.0+counter*30.0, "                                     >");
            TextDrawAlignment(jobListTextDraws[counter*3], 2);
            TextDrawBackgroundColor(jobListTextDraws[counter*3], 255);
            TextDrawFont(jobListTextDraws[counter*3], 2);
            TextDrawLetterSize(jobListTextDraws[counter*3], 0.50, 3.0);
            TextDrawColor(jobListTextDraws[counter*3], -1);
            TextDrawSetOutline(jobListTextDraws[counter*3], 0);
            TextDrawSetProportional(jobListTextDraws[counter*3], 1);
            TextDrawSetShadow(jobListTextDraws[counter*3], 1);
            TextDrawUseBox(jobListTextDraws[counter*3], 1);
            TextDrawBoxColor(jobListTextDraws[counter*3], 128);
            TextDrawTextSize(jobListTextDraws[counter*3], 26.0, 240.0);
            TextDrawSetSelectable(jobListTextDraws[counter*3], 1);

            jobListTextDraws[counter*3+1] = TextDrawCreate(240.0, 146.0+counter*30.0, g_Job[i][g_company]);
            TextDrawBackgroundColor(jobListTextDraws[counter*3+1], 255);
            TextDrawFont(jobListTextDraws[counter*3+1], 0);
            TextDrawLetterSize(jobListTextDraws[counter*3+1], 0.50, 1.50);
            TextDrawColor(jobListTextDraws[counter*3+1], -1);
            TextDrawSetOutline(jobListTextDraws[counter*3+1], 0);
            TextDrawSetProportional(jobListTextDraws[counter*3+1], 1);
            TextDrawSetShadow(jobListTextDraws[counter*3+1], 1);
            TextDrawTextSize(jobListTextDraws[counter*3+1], 440.0, 0.0);

            jobListTextDraws[counter*3+2] = TextDrawCreate(207.0, 136.0+counter*30.0, "previewModel");
            TextDrawBackgroundColor(jobListTextDraws[counter*3+2], -256);
            TextDrawFont(jobListTextDraws[counter*3+2], 5);
            TextDrawColor(jobListTextDraws[counter*3+2], -1);
            TextDrawSetOutline(jobListTextDraws[counter*3+2], 0);
            TextDrawSetProportional(jobListTextDraws[counter*3+2], 1);
            TextDrawSetShadow(jobListTextDraws[counter*3+2], 1);
            TextDrawUseBox(jobListTextDraws[counter*3+2], 1);
            TextDrawBoxColor(jobListTextDraws[counter*3+2], -256);
            TextDrawTextSize(jobListTextDraws[counter*3+2], 33.0, 33.0);
            TextDrawSetPreviewModel(jobListTextDraws[counter*3+2], g_Job[i][g_previewModel]);
            TextDrawSetPreviewRot(jobListTextDraws[counter*3+2], -12.0, 0.0, -17.0, 0.80);
            TextDrawSetPreviewVehCol(jobListTextDraws[counter*3+2], 0, 0);
            
            Iter_Add(jobListIterator, i);
            counter++;
        }
    }
}

ShowPlayerJobMenuTD(playerid) {
    TextDrawShowForPlayer(playerid, jobListHeader);
    foreach(new i : jobListIterator) {
        TextDrawShowForPlayer(playerid, jobListTextDraws[i*3]);
        TextDrawShowForPlayer(playerid, jobListTextDraws[i*3+1]);
        TextDrawShowForPlayer(playerid, jobListTextDraws[i*3+2]);
    }
    SelectTextDraw(playerid, HOVER_COLOR_DEFAULT);
    playerJobMenu[playerid] = true;
}

HidePlayerJobMenuTD(playerid) {
    TextDrawHideForPlayer(playerid, jobListHeader);
    foreach(new i : jobListIterator) {
        TextDrawHideForPlayer(playerid, jobListTextDraws[i*3]);
        TextDrawHideForPlayer(playerid, jobListTextDraws[i*3+1]);
        TextDrawHideForPlayer(playerid, jobListTextDraws[i*3+2]);
    }
    CancelSelectTextDraw(playerid);
}

hook OnPlayerDisconnect(playerid, reason) {
    HidePlayerJobMenuTD(playerid);
    playerJobMenu[playerid] = false;
}

hook OnPlayerClickTextDraw(playerid, Text:clickedid) {
    foreach(new i : jobListIterator) {
        if(clickedid == jobListTextDraws[i*3]) {
            ShowPlayerJobOfferDialog(playerid, i);
            return 1;
        }
    }
    
    if(clickedid == Text:INVALID_TEXT_DRAW && playerJobMenu[playerid]) {
        // hide menu
        HidePlayerJobMenuTD(playerid);
        
        TogglePlayerSpectating(playerid, false);
        SetPlayerVirtualWorld(playerid, VW_DEFAULT);
        return 1;
    }
    return 0;
}

hook OnPlayerSpawn(playerid) {
    if(playerJobMenu[playerid]) {
        playerJobMenu[playerid] = false;
        SetPlayerToLabourOffice(playerid);
    }
    return 1;
}