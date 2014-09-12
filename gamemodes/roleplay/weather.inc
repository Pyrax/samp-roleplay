#if defined _INCLUDED_WEATHER
    #endinput
#endif
#define _INCLUDED_WEATHER

// Weather generation as described here: http://fordevsbydevs.wordpress.com/2013/08/23/designing-random-numbers-for-games/

//-----------------------------------------------------

#include <YSI\y_hooks>

//-----------------------------------------------------

enum E_WEATHER_FORECAST {
    g_weatherID,
    g_timestamp
};

//-----------------------------------------------------

static currentWeatherID = 0;
static Float:currentWeather; // 0-9
static weatherDirection;
static Float:weatherDirectionTreshold[2];

static weather_sunny[] = { // 0-3
    0, 1, 2, 3, 5, 6, 10, 11, 13, 14
};
static weather_cloudy[] = { // 3-6
    4, 7, 12, 15
};
static weather_rainy[] = { // 6-8
    8, 16
};
static weather_foggy = 9; // 8-9

//-----------------------------------------------------

UpdateWeather() {
    new Float:weatherChange = (float(random(100) + 20) / 100);
    
    // weather changes from 0.25 to 1.25 every minute
    currentWeather += (weatherDirection == 1) ? (weatherChange) : (-weatherChange);
    
    if(weatherDirection <= 0) {
        if(currentWeather < weatherDirectionTreshold[0]) {
            weatherDirection = -weatherDirection;
            weatherDirectionTreshold[0] = (float(random(45)) / 10);
        }
    } else {
        if(currentWeather > weatherDirectionTreshold[1]) {
            weatherDirection = -weatherDirection;
            weatherDirectionTreshold[1] = (float(random(45) + 45) / 10);
        }
    }
    
    log();

    switch(floatround(currentWeather, floatround_round)) {
        case 0, 1, 2: {
            switch(currentWeatherID) {
                case 4, 7, 12, 15, 8, 16, 9: currentWeatherID = weather_sunny[random(sizeof weather_sunny)];
            }
        } case 3, 4, 5: {
            switch(currentWeatherID) {
                case 0, 1, 2, 3, 5, 6, 10, 11, 13, 14, 8, 16, 9: currentWeatherID = weather_cloudy[random(sizeof weather_cloudy)];
            }
        } case 6, 7: {
            switch(currentWeatherID) {
                case 0, 1, 2, 3, 5, 6, 10, 11, 13, 14, 4, 7, 12, 15, 9: currentWeatherID = weather_rainy[random(sizeof weather_rainy)];
            }
        } case 8: {
            if(currentWeatherID != 9) currentWeatherID = weather_foggy;
        }
    }
    
    SetWeather(currentWeatherID);
}

static log() {
    new File:logf = fopen("/weather.csv", io_append),
        string[90];
    
    format(string, sizeof string, "%f,%d,%f,%f\n", currentWeather, weatherDirection, weatherDirectionTreshold[0], weatherDirectionTreshold[1]);
    
    if(logf) {
        fwrite(logf, string);
        fclose(logf);
    }
}

hook OnGameModeInit() {
    currentWeather = 4.5;
    weatherDirection = 1;
    
    weatherDirectionTreshold[0] = (float(random(45)) / 10);
    weatherDirectionTreshold[1] = (float(random(45) + 45) / 10);
    
    new File:logf = fopen("/weather.csv", io_write),
        string[128];
    
    format(string, sizeof string, "currentWeather,weatherDirection,weatherDirectionTreshold[0],weatherDirectionTreshold[1]\n");
    
    if(logf) {
        fwrite(logf, string);
        fclose(logf);
    }
    
    UpdateWeather();
}

task SyncWeather[420000]() {
    UpdateWeather();
}