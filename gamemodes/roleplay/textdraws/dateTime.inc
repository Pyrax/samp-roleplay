#if defined _INCLUDED_TEXTDRAWS_TIME
    #endinput
#endif
#define _INCLUDED_TEXTDRAWS_TIME

//-----------------------------------------------------

#include <YSI\y_hooks>

//-----------------------------------------------------

static Text:timeTextDraw;
static Text:dateTextDraw;

//-----------------------------------------------------

UpdateTime(hours, minutes) {
    new string[12];
    
    format(string, sizeof string, "%02d:%02d", hours, minutes);
    TextDrawSetString(timeTextDraw, string);
}

UpdateDate(year, month, day) {
    new string[12];
    
    format(string, sizeof string, "%02d.%02d.%04d", day, month, year);
    TextDrawSetString(dateTextDraw, string);
}

ShowPlayerDateTime(playerid) {
    TextDrawShowForPlayer(playerid, timeTextDraw);
    TextDrawShowForPlayer(playerid, dateTextDraw);
}

HidePlayerDateTime(playerid) {
    TextDrawHideForPlayer(playerid, timeTextDraw);
    TextDrawHideForPlayer(playerid, dateTextDraw);
}

static CreateDateTimeTextDraw() {
    timeTextDraw = TextDrawCreate(577.0, 22.0, " ");
    TextDrawAlignment(timeTextDraw, 2);
    TextDrawBackgroundColor(timeTextDraw, 255);
    TextDrawFont(timeTextDraw, 3);
    TextDrawLetterSize(timeTextDraw, 0.579999, 2.399999);
    TextDrawColor(timeTextDraw, -1);
    TextDrawSetOutline(timeTextDraw, 1);
    TextDrawSetProportional(timeTextDraw, 1);
    TextDrawTextSize(timeTextDraw, 0.0, 0.0);
    
    dateTextDraw = TextDrawCreate(553.0, 11.0, " ");
    TextDrawAlignment(dateTextDraw, 2);
    TextDrawBackgroundColor(dateTextDraw, 255);
    TextDrawFont(dateTextDraw, 3);
    TextDrawLetterSize(dateTextDraw, 0.569999, 1.299999);
    TextDrawColor(dateTextDraw, -1);
    TextDrawSetOutline(dateTextDraw, 1);
    TextDrawSetProportional(dateTextDraw, 1);
    TextDrawTextSize(dateTextDraw, 0.0, 0.0);
}

hook OnGameModeInit() {
    CreateDateTimeTextDraw();
}