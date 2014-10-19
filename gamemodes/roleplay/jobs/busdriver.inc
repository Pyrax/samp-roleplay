#if defined _INCLUDED_JOBS_BUSDRIVER
    #endinput
#endif
#define _INCLUDED_JOBS_BUSDRIVER

//-----------------------------------------------------

#include <YSI\y_hooks>

//-----------------------------------------------------

#include "./roleplay/jobs/busdriver/busstops"

//-----------------------------------------------------

new Group:g_Busdriver;

//-----------------------------------------------------

hook OnGameModeInit() {
    g_Busdriver = Group_Create("Busfahrer");
    return 1;
}

hook OnPlayerLoadJob(playerid, jobid, newJobType, rankOrder) {
    if(newJobType == 2) {
        Group_SetPlayer(g_Busdriver, playerid, true);
    }
}

hook OnVehicleStreamIn(vehicleid, forplayerid) {
    foreach(new i : g_JobVehicleIterator) {
        if(vehicleid == g_JobVehicle[i][g_vehicle_ID]) {
            new jobid = g_JobVehicle[i][g_job_ID]-1,
                rankOrder = g_JobVehicle[i][g_rankOrder];
            
            if(Group_GetPlayer(g_JobGroup[jobid][rankOrder], forplayerid)) {
                UnlockVehicleForPlayer(g_JobVehicle[i][g_vehicle_ID], forplayerid);
            }
        }
    }
    return 1;
}