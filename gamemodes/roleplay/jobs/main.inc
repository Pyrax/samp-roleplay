#if defined _INCLUDED_JOBS_MAIN
    #endinput
#endif
#define _INCLUDED_JOBS_MAIN

//-----------------------------------------------------

loadtext mode_text[jobs];

//-----------------------------------------------------

#define MAX_JOBS 10
#define MAX_RANKS 20

//-----------------------------------------------------

#include <YSI\y_hooks>

//-----------------------------------------------------

enum E_JOBS {
    ORM:g_orm_ID,
    g_ID,
    g_company[64],
    Float:g_dutyPosX,
    Float:g_dutyPosY,
    Float:g_dutyPosZ,
    g_dutyInteriorID,
    g_inviteOnly,
    g_previewModel,
    g_jobType
};

enum E_JOB_VEHICLES {
    ORM:g_orm_ID,
    g_ID,
    g_model_ID,
    Float:g_spawnX,
    Float:g_spawnY,
    Float:g_spawnZ,
    Float:g_spawnAngle,
    g_color1,
    g_color2,
    g_job_ID,
    g_rank_ID,
    
    // run-time data (non stored)
    g_vehicle_ID,
    g_rankOrder
};

enum E_PLAYER_JOB {
    
};

//-----------------------------------------------------

new g_Job[MAX_JOBS][E_JOBS],
    Iterator:g_JobIterator<MAX_JOBS>;
new g_JobVehicle[MAX_VEHICLES][E_JOB_VEHICLES],
    Iterator:g_JobVehicleIterator<MAX_VEHICLES>;
new Group:g_JobGroup[MAX_JOBS][MAX_RANKS];
static bool:playerJobMenu[MAX_PLAYERS];

//-----------------------------------------------------

#include "./roleplay/textdraws/jobMenu"

//-----------------------------------------------------

ShowPlayerJobMenu(playerid) {
    if(!IsPlayerLoggedIn(playerid)) {
        return;
    }
    
    ShowPlayerJobMenuTD(playerid);
    
    SetPlayerVirtualWorld(playerid, VW_LABOUR_OFFICE);
    
    TogglePlayerSpectating(playerid, true);
    AttachCameraToPlayerObject(playerid, GetPlayerCameraDummy(playerid));
    
    SetPlayerInterior(playerid, 3);
    SetPlayerCameraPos(playerid, LABOUR_CAMERA_POS);
    SetPlayerCameraLookAt(playerid, LABOUR_CAMERA_LOOK);
}

ShowPlayerJobOfferDialog(playerid, idx) {
    inline DialogResponse(i_playerid, i_dialogid, i_response, i_listitem, string:i_inputtext[]) {
        #pragma unused i_playerid, i_dialogid, i_listitem, i_inputtext
        
        if(i_response) {
            AddJobMember(playerid, g_Job[idx][g_ID], g_Job[idx][g_jobType]);
            HidePlayerJobMenuTD(playerid);
        }
    }
    Text_MessageBox(playerid, using inline DialogResponse, $DIALOG_ACCEPT_JOB_H, $DIALOG_ACCEPT_JOB_B, $DIALOG_ACCEPT_JOB_SUB, $DIALOG_ACCEPT_JOB_CAN);
}

AddJobMember(playerid, jobid, jobtype) {
    new query[256],
        pid = GetPlayerID(playerid);
    
    format(query, sizeof query, "INSERT INTO job_members (job_ID, player_ID, rank_ID) VALUES ('%d', '%d', (SELECT `ID` FROM job_ranks WHERE `job_ID` = '%d' ORDER BY `order` LIMIT 1))", jobid, pid, jobid);
    inline JobMemberAdded() {
        if(cache_affected_rows()) {
            format(query, sizeof query, "SELECT jr.order FROM job_members jm LEFT JOIN job_ranks jr ON jr.ID = jm.rank_ID WHERE player_ID = '%d'", pid);
            inline RankOrderFetched() {
                CallLocalFunction("OnPlayerLoadJob", "dddd", playerid, jobid, jobtype, cache_get_row_int(0, 0));
            }
            mysql_tquery_inline(g_MysqlHandler, query, using inline RankOrderFetched, "");
            
            format(query, sizeof query, "SELECT jr.%s AS jobTitle, j.company AS company FROM job_members jm \
                LEFT JOIN job_ranks jr ON jr.ID = jm.rank_ID \
                LEFT JOIN jobs j ON j.ID = jm.job_ID \
                WHERE player_ID = '%d'", (IsMale(playerid)) ? ("maleTitle") : ("femaleTitle"), pid);
            inline JobTitleFetched() {
                new jobTitle[32],
                    company[64];
                
                cache_get_field_content(0, "jobTitle", jobTitle);
                cache_get_field_content(0, "company", company);
                
                Text_Send(playerid, $JOB_ACCEPTED, jobTitle, company);
            }
            mysql_tquery_inline(g_MysqlHandler, query, using inline JobTitleFetched, "");
        } else {
            // TODO: error, user already has job?!
        }
    }
    mysql_tquery_inline(g_MysqlHandler, query, using inline JobMemberAdded, "");
}

static ORM:CreateJobORM(idx) {
    new ORM:ormid = g_Job[idx][g_orm_ID] = orm_create("jobs");
    
    orm_addvar_int(ormid, g_Job[idx][g_ID], "ID");
    orm_setkey(ormid, "ID");
    
    orm_addvar_string(ormid, g_Job[idx][g_company], 64, "company");
    orm_addvar_float(ormid, g_Job[idx][g_dutyPosX], "dutyPosX");
    orm_addvar_float(ormid, g_Job[idx][g_dutyPosY], "dutyPosY");
    orm_addvar_float(ormid, g_Job[idx][g_dutyPosZ], "dutyPosZ");
    orm_addvar_int(ormid, g_Job[idx][g_dutyInteriorID], "dutyInteriorID");
    orm_addvar_int(ormid, g_Job[idx][g_inviteOnly], "inviteOnly");
    orm_addvar_int(ormid, g_Job[idx][g_previewModel], "previewModel");
    orm_addvar_int(ormid, g_Job[idx][g_jobType], "jobType");
    return ormid;
}

LoadJobsFromDatabase() {
    inline JobsLoaded() {
        for(new r = 0; r < cache_num_rows(); r++) {
            new ORM:ormid = CreateJobORM(Iter_Free(g_JobIterator));
            // store data of the cache in the ORM
            orm_apply_cache(ormid, r);
            Iter_Add(g_JobIterator, r);
        }
        CreateJobMenuTD();
        
        // create job groups
        inline JobRanksLoaded() {
            new groupName[100],
                company[64],
                maleTitle[32],
                jobid,
                oldJob,
                rankOrder,
                oldRank;
            
            for(new r = 0; r < cache_num_rows(); r++) {
                cache_get_field_content(r, "company", company);
                cache_get_field_content(r, "maleTitle", maleTitle);
                jobid = cache_get_field_content_int(r, "ID")-1;
                rankOrder = cache_get_field_content_int(r, "order");
                
                format(groupName, sizeof groupName, "%s: %s", company, maleTitle);
                g_JobGroup[jobid][rankOrder] = Group_Create(groupName);
                
                if(oldJob == jobid) {
                    Group_SetGroup(g_JobGroup[jobid][rankOrder], g_JobGroup[jobid][oldRank], true);
                }
                
                oldJob = jobid;
                oldRank = rankOrder;
            }
        }
        mysql_tquery_inline(g_MysqlHandler, "SELECT j.company, jr.maleTitle, j.ID, jr.order FROM job_ranks jr LEFT JOIN jobs j ON j.ID = jr.job_ID ORDER BY j.ID, jr.order", using inline JobRanksLoaded, "");
    }
    mysql_tquery_inline(g_MysqlHandler, "SELECT * FROM jobs", using inline JobsLoaded, "");
}

static ORM:CreateJobVehicleORM(idx) {
    new ORM:ormid = g_JobVehicle[idx][g_orm_ID] = orm_create("job_vehicles");
    
    orm_addvar_int(ormid, g_JobVehicle[idx][g_ID], "ID");
    orm_setkey(ormid, "ID");
    
    orm_addvar_int(ormid, g_JobVehicle[idx][g_model_ID], "model_ID");
    orm_addvar_float(ormid, g_JobVehicle[idx][g_spawnX], "spawnX");
    orm_addvar_float(ormid, g_JobVehicle[idx][g_spawnY], "spawnY");
    orm_addvar_float(ormid, g_JobVehicle[idx][g_spawnZ], "spawnZ");
    orm_addvar_float(ormid, g_JobVehicle[idx][g_spawnAngle], "spawnAngle");
    orm_addvar_int(ormid, g_JobVehicle[idx][g_color1], "color1");
    orm_addvar_int(ormid, g_JobVehicle[idx][g_color2], "color2");
    orm_addvar_int(ormid, g_JobVehicle[idx][g_job_ID], "job_ID");
    orm_addvar_int(ormid, g_JobVehicle[idx][g_rank_ID], "rank_ID");
    return ormid;
}

LoadJobVehiclesFromDatabase() {
    inline JobVehiclesLoaded() {
        for(new r = 0; r < cache_num_rows(); r++) {
            new ORM:ormid = CreateJobVehicleORM(Iter_Free(g_JobVehicleIterator));
            
            // store data of the cache in the ORM
            orm_apply_cache(ormid, r);
            Iter_Add(g_JobVehicleIterator, r);
            
            // create vehicle
            g_JobVehicle[r][g_vehicle_ID] = AddStaticVehicleEx(g_JobVehicle[r][g_model_ID], g_JobVehicle[r][g_spawnX], g_JobVehicle[r][g_spawnY], g_JobVehicle[r][g_spawnZ], g_JobVehicle[r][g_spawnAngle], g_JobVehicle[r][g_color1], g_JobVehicle[r][g_color2], -1);
            LockVehicle(g_JobVehicle[r][g_vehicle_ID]);
            
            // get required rank order
            g_JobVehicle[r][g_rankOrder] = cache_get_field_content_int(r, "order");
        }
    }
    mysql_tquery_inline(g_MysqlHandler, "SELECT jv.ID, model_ID, spawnX, spawnY, spawnZ, spawnAngle, color1, color2, jv.job_ID, rank_ID, jr.order FROM samp.job_vehicles jv LEFT JOIN job_ranks jr ON jv.rank_ID = jr.ID", using inline JobVehiclesLoaded, "");
}

function OnPlayerLoadJob(playerid, jobid, newJobType, rankOrder) {
    Group_SetPlayer(g_JobGroup[jobid-1][rankOrder], playerid, true);
    return 1;
}

hook OnPlayerLogin(playerid) {
    // Load a players job
    new query[200];
    
    format(query, sizeof query, "SELECT j.ID, j.jobType, jr.order FROM job_members jm LEFT JOIN jobs j ON j.ID = jm.job_ID LEFT JOIN job_ranks jr ON jr.ID = jm.rank_ID WHERE player_ID = '%d'", GetPlayerID(playerid));
    inline JobMembersLoaded() {
        if(cache_num_rows()) {
            CallLocalFunction("OnPlayerLoadJob", "dddd", playerid, cache_get_row_int(0, 0), cache_get_row_int(0, 1), cache_get_row_int(0, 2));
        }
    }
    mysql_tquery_inline(g_MysqlHandler, query, using inline JobMembersLoaded, "");
}