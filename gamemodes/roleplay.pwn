#define DEBUG_MODE 1
#define MYSQL_USE_YINLINE

//-----------------------------------------------------

#include <a_samp>
#include <a_mysql>
#include <sscanf2>
#include <formatnumber>

//-----------------------------------------------------

native WP_Hash(buffer[], len, const str[]);

//-----------------------------------------------------

#define SERVER_NAME         "0.3z SAMP Server"
#define SERVER_MODE         "Blank mode"
#define SERVER_MAP          "San Andreas"
#define SERVER_WEBSITE      "sa-mp.com"
#define SERVER_PASSWORD     "0"

#define SQL_HOST            "127.0.0.1"
#define SQL_PORT            3306
#define SQL_USER            "root"
#define SQL_PASSWORD        ""
#define SQL_DB              "samp"

//-----------------------------------------------------

// VirtualWorlds
#define VW_DEFAULT              0
#define VW_OFFSET_HOUSES        VW_DEFAULT + 1
#define VW_BROKER               VW_DEFAULT + 1 + MAX_HOUSES + 1
#define VW_LABOUR_OFFICE        VW_DEFAULT + 1 + MAX_HOUSES + 2

//-----------------------------------------------------

//#include <YSI\y_hooks>
#include <YSI\y_timers>
#include <YSI\y_bit>
#include <YSI\y_inline>
#include <YSI\y_dialog>
#include <YSI\y_commands>
#include <YSI\y_iterate>
#include <YSI\y_colours>
#include <YSI\y_text>
#include <YSI\y_languages>
#include <YSI\y_groups>

//-----------------------------------------------------

#define RGB(%0,%1,%2) (%0 << 16 | %1 << 8 | %2)
#define RGBA(%0,%1,%2,%3) (%0 << 24 | %1 << 16 | %2 << 8 | %3)

#define posArr{%0}      %0[0], %0[1], %0[2]         // for use with coordinates
#define posArrOff{%0}   %0[3], %0[4], %0[5]         // for use with coordinates with offset
#define posArrEx{%0}    %0[0], %0[1], %0[2], %0[3]  // same as above

#define function%0(%1) forward%0(%1);public%0(%1)

//-----------------------------------------------------

#define PLAYER_NAME_LEN             MAX_PLAYER_NAME+1
#define ENTER_PICKUP                19132
#define PICKUP_RANGE                1.5
#define D3_DRAW_DISTANCE_DEFAULT    25.0
#define D3_DRAW_DISTANCE_HOUSES     15.0
#define HOVER_COLOR_DEFAULT         0xFFFFFF55

#define PlaySoundSuccess(%0,%1,%2,%3)     PlayerPlaySound(%0, 1083, %1, %2, %3)
#define PlaySoundFail(%0,%1,%2,%3)        PlayerPlaySound(%0, 1084, %1, %2, %3)

// initialise the maximum number of house offers shown by the broker
#define MAX_HOUSES_PER_PAGE     5

//-----------------------------------------------------

new g_MysqlHandler;
new g_langGerman;

//-----------------------------------------------------

main() {
    
}

//-----------------------------------------------------

Bootstrap() {
    MysqlConnect();
    
    SendRconCommand("hostname " SERVER_NAME);
    SetGameModeText(SERVER_MODE);
    SendRconCommand("mapname " SERVER_MAP);
    SendRconCommand("weburl " SERVER_WEBSITE);
    SendRconCommand("password " SERVER_PASSWORD);
    
    // y_languages
    g_langGerman = Langs_Add("DE", "Deutsch");
    
    // y_groups
    Group_SetGlobalCommandDefault(false);
    
    // implement new color codes in y_text through y_colours
    SetColour("TEXT", X11_GHOST_WHITE);
    SetColour("TEXT_HEADLINE", X11_CORNFLOWER_BLUE);
    SetColour("TEXT_HIGHLIGHT", X11_DODGER_BLUE);
    SetColour("TEXT_STRESS", X11_IVORY);
    
    SetColour("DIALOG_TEXT", X11_GHOST_WHITE);
    SetColour("DIALOG_HEADLINE", X11_CORNFLOWER_BLUE);
    SetColour("DIALOG_HIGHLIGHT", X11_DODGER_BLUE);
    SetColour("DIALOG_STRESS", X11_IVORY);
    
    SetColour("ERROR", X11_FIREBRICK);
    SetColour("SUCCESS", X11_GREEN_YELLOW);
    
    #define COLOR_3DTEXT    X11_ALICE_BLUE
    
    DisableInteriorEnterExits();
    UsePlayerPedAnims();
    EnableStuntBonusForAll(0);
    SetNameTagDrawDistance(50.0);
    ShowPlayerMarkers(PLAYER_MARKERS_MODE_OFF);
}

MysqlConnect() {
    #if DEBUG_MODE == 1
        mysql_log(LOG_ERROR | LOG_WARNING | LOG_DEBUG);
    #else
        mysql_log(LOG_ERROR | LOG_WARNING);
    #endif
    
    printf("[SQL] Server baut eine Verbindung zum SQL Server @%s:%d (User: %s) auf", SQL_HOST, SQL_PORT, SQL_USER);
    g_MysqlHandler = mysql_connect(SQL_HOST, SQL_USER, SQL_DB, SQL_PASSWORD, SQL_PORT);
    
    if(mysql_errno(g_MysqlHandler) == 0) {
        print("[SQl] Verbindung zum SQL Server wurde erfolgreich aufgebaut");
    } else {
        print("[SQL] Verbindung zum SQL Server ist fehlgeschlagen\nServer wird heruntergefahren...");
        GameModeExit();
    }
}

//-----------------------------------------------------

// Load core functions
#include "./roleplay/places"

#include "./roleplay/animations"
#include "./roleplay/players"
#include "./roleplay/houses"
#include "./roleplay/dateTime"
#include "./roleplay/weather"

#include "./roleplay/jobs/main"

// Load implementation of functions
#include "./roleplay/callbacks"
