#if defined _INCLUDED_JOBS_MAIN
    #endinput
#endif
#define _INCLUDED_JOBS_MAIN

//-----------------------------------------------------

loadtext mode_text[jobs];

//-----------------------------------------------------

#define MAX_JOBS 10

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
    g_previewModel
};

//-----------------------------------------------------

new g_Job[MAX_JOBS][E_JOBS],
    Iterator:g_JobIterator<MAX_JOBS>;
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
    
    // SETCAMERAPOS AND LOOKAT
}

ShowPlayerJobOfferDialog(playerid, idx) {
    inline DialogResponse(i_playerid, i_dialogid, i_response, i_listitem, string:i_inputtext[]) {
        #pragma unused i_playerid, i_dialogid, i_listitem, i_inputtext
        
        if(i_response) {
            AddJobMember(playerid, g_Job[idx][g_ID]);
        }
    }
    Text_MessageBox(playerid, using inline DialogResponse, $DIALOG_BUY_HOUSE_H, $DIALOG_BUY_HOUSE_B, $DIALOG_BUY_HOUSE_SUB, $DIALOG_BUY_HOUSE_CAN);
}

AddJobMember(playerid, jobid) {
    new query[256],
        pid = GetPlayerID(playerid);
    
    format(query, sizeof query, "INSERT INTO job_members (job_ID, player_ID, rank_ID) VALUES ('%d', '%d', (SELECT `ID` FROM job_ranks WHERE `job_ID` = '%d' ORDER BY `order` LIMIT 1))", jobid, pid, jobid);
    inline JobMemberAdded() {
        if(cache_affected_rows()) {
            format(query, sizeof query, "SELECT jr.%sTitle AS jobTitle, j.company AS company FROM job_members jm \
                LEFT JOIN job_ranks jr ON jr.ID = jm.rank_ID \
                LEFT JOIN jobs j ON j.ID = jm.job_ID \
                WHERE player_ID = '%d'", (IsMale(playerid)) ? ("male") : ("female"), pid);
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
    }
    mysql_tquery_inline(g_MysqlHandler, "SELECT * FROM jobs", using inline JobsLoaded, "");
}