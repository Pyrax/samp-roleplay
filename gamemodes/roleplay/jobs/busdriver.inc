#if defined _INCLUDED_JOBS_BUSDRIVER
    #endinput
#endif
#define _INCLUDED_JOBS_BUSDRIVER

//-----------------------------------------------------

#include <YSI\y_hooks>

//-----------------------------------------------------

#define MAX_BUSSTOPS    100

//-----------------------------------------------------

enum E_BUSSTOPS {
    ORM:g_orm_ID,
    g_ID,
    g_model_ID,
    Float:g_posX,
    Float:g_posY,
    Float:g_posZ,
    Float:g_rotX,
    Float:g_rotY,
    Float:g_rotZ
};

//-----------------------------------------------------

new Group:g_Busdriver;
static busstop[MAX_BUSSTOPS][E_BUSSTOPS],
    Iterator:busstopIterator<MAX_BUSSTOPS>;

//-----------------------------------------------------

static ORM:CreateBusstopORM(idx) {
    new ORM:ormid = busstop[idx][g_orm_ID] = orm_create("busstops");
    
    orm_addvar_int(ormid, busstop[idx][g_ID], "ID");
    orm_setkey(ormid, "ID");
    
    orm_addvar_int(ormid, busstop[idx][g_model_ID], "model_ID");
    orm_addvar_float(ormid, busstop[idx][g_posX], "posX");
    orm_addvar_float(ormid, busstop[idx][g_posY], "posY");
    orm_addvar_float(ormid, busstop[idx][g_posZ], "posZ");
    orm_addvar_float(ormid, busstop[idx][g_rotX], "rotX");
    orm_addvar_float(ormid, busstop[idx][g_rotY], "rotY");
    orm_addvar_float(ormid, busstop[idx][g_rotZ], "rotZ");
    return ormid;
}

CreateBusstops() {
    inline BusstopsLoaded() {
        for(new r = 0; r < cache_num_rows(); r++) {
            new ORM:ormid = CreateBusstopORM(Iter_Free(busstopIterator));
            orm_apply_cache(ormid, r);
            Iter_Add(busstopIterator, r);
            
            CreateObject(busstop[r][g_model_ID], busstop[r][g_posX], busstop[r][g_posY], busstop[r][g_posZ], busstop[r][g_rotX], busstop[r][g_rotY], busstop[r][g_rotZ], OBJECT_DRAW_DISTANCE);
        }
    }
    mysql_tquery_inline(g_MysqlHandler, "SELECT * FROM busstops", using inline BusstopsLoaded, "");
}

hook OnGameModeInit() {
    g_Busdriver = Group_Create("Busfahrer");
    
    CreateBusstops();
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