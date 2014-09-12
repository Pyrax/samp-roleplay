#if defined _INCLUDED_WEATHER
    #endinput
#endif
#define _INCLUDED_WEATHER

//-----------------------------------------------------

#include <YSI\y_hooks>

//-----------------------------------------------------



//-----------------------------------------------------

static currentWeather;
// weather forecasts keep information about which weather ID's come next and when the weather changes
static weatherForecast[2][2];

static weather[] = {
    0, 0
};

//-----------------------------------------------------

ChangeWeather() {
    
}

hook OnPlayerConnect(playerid) {
    SetPlayerWeather(playerid, currentWeather);
}