#if defined _INCLUDED_JOBS_BUSDRIVER
    #endinput
#endif
#define _INCLUDED_JOBS_BUSDRIVER

//-----------------------------------------------------

#include <YSI\y_hooks>

//-----------------------------------------------------

new Group:g_Busdriver;

//-----------------------------------------------------

hook OnGameModeInit() {
    g_Busdriver = Group_Create("Busfahrer");
    return 1;
}

hook OnPlayerLoadJob(playerid, newJobType) {
    if(newJobType == 2) {
        Group_SetPlayer(g_Busdriver, playerid, true);
    }
}