#define DEBUG_MODE 1
#define MYSQL_USE_YINLINE

//-----------------------------------------------------

#include <a_samp>
#include <a_mysql>
#include <sscanf2>

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
#define VW_DEFAULT 0

//-----------------------------------------------------

#include <YSI\y_hooks>
#include <YSI\y_timers>
#include <YSI\y_bit>
#include <YSI\y_inline>
#include <YSI\y_dialog>
#include <YSI\y_commands>
#include <YSI\y_iterate>

//-----------------------------------------------------

#define RGB(%0,%1,%2) (%0 << 16 | %1 << 8 | %2)
#define RGBA(%0,%1,%2,%3) (%0 << 24 | %1 << 16 | %2 << 8 | %3)

#define posArr{%0}      %0[0], %0[1], %0[2]         // for use with coordinates
#define posArrOff{%0}   %0[3], %0[4], %0[5]         // for use with coordinates with offset
#define posArrEx{%0}    %0[0], %0[1], %0[2], %0[3]  // same as above

#define function%0(%1) forward%0(%1);public%0(%1)

//-----------------------------------------------------

#define PLAYER_NAME_LEN     MAX_PLAYER_NAME+1

//-----------------------------------------------------

new g_MysqlHandler;

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
    
    DisableInteriorEnterExits();
    UsePlayerPedAnims();
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
#include "./roleplay/animations"
#include "./roleplay/players"
#include "./roleplay/houses"

// Load implementation of functions
#include "./roleplay/callbacks"