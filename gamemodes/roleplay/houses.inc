#if defined _INCLUDED_HOUSES
    #endinput
#endif
#define _INCLUDED_HOUSES

//-----------------------------------------------------

#define MAX_HOUSES 50

#define GetPlayerMoney GetPlayerMoney

//-----------------------------------------------------

enum E_HOUSE {
    ORM:orm_ID,
    ID,
    interior_ID,
    Float:entranceX,
    Float:entranceY,
    Float:entranceZ,
    Float:entranceAngle,
    Float:exitX,
    Float:exitY,
    Float:exitZ,
    Float:exitAngle,
    
    // variables that are only needed for the shopping menu
    model_ID,
    Float:cameraPosX,
    Float:cameraPosY,
    Float:cameraPosZ,
    Float:cameraLookAtX,
    Float:cameraLookAtY,
    Float:cameraLookAtZ,
    
    // non-stored variables
    pickup
}

enum E_HOUSE_OWNER {
    ORM:orm_ID,
    house_ID,
    owner_ID
}

// houses being sold
enum E_SELL_HOUSE {
    ORM:orm_ID,
    house_ID,
    price
}

//-----------------------------------------------------

new g_House[MAX_HOUSES][E_HOUSE];
new g_HouseOwner[MAX_HOUSES][E_HOUSE_OWNER];
new g_SellHouse[MAX_HOUSES][E_SELL_HOUSE];

//-----------------------------------------------------

/*ShowPlayerHouseList(playerid) {
    if(!IsPlayerLoggedIn()) {
        return 0;
    }
    
    // SHOW TEXTDRAWS
    // TextDrawSetPreviewModel(td_houseModel, Model_ID);
    inline QueryResponse() {
        
    }
    mysql_tquery_inline(g_MysqlHandler, "SELECT * FROM sell_houses", using inline QueryResponse, "");
    return 1;
}*/

LoadHousesFromDatabase() {
    inline HousesLoaded() {
        for(new r = 0; r < cache_num_rows(); r++) {
            new ORM:ormid = g_House[r][orm_ID] = orm_create("houses");
            
            orm_addvar_int(ormid, g_House[r][ID], "ID");
            orm_setkey(ormid, "ID");
            
            orm_addvar_int(ormid, g_House[r][interior_ID], "interior_ID");
            orm_addvar_float(ormid, g_House[r][entranceX], "entranceX");
            orm_addvar_float(ormid, g_House[r][entranceY], "entranceY");
            orm_addvar_float(ormid, g_House[r][entranceZ], "entranceZ");
            orm_addvar_float(ormid, g_House[r][entranceAngle], "entranceAngle");
            orm_addvar_float(ormid, g_House[r][exitX], "exitX");
            orm_addvar_float(ormid, g_House[r][exitY], "exitY");
            orm_addvar_float(ormid, g_House[r][exitZ], "exitZ");
            orm_addvar_float(ormid, g_House[r][exitAngle], "exitAngle");
            
            orm_addvar_int(ormid, g_House[r][model_ID], "model_ID");
            orm_addvar_float(ormid, g_House[r][cameraPosX], "cameraPosX");
            orm_addvar_float(ormid, g_House[r][cameraPosY], "cameraPosY");
            orm_addvar_float(ormid, g_House[r][cameraPosZ], "cameraPosZ");
            orm_addvar_float(ormid, g_House[r][cameraLookAtX], "cameraLookAtX");
            orm_addvar_float(ormid, g_House[r][cameraLookAtY], "cameraLookAtY");
            orm_addvar_float(ormid, g_House[r][cameraLookAtZ], "cameraLookAtZ");
            
            // store data of the cache in the ORM
            orm_apply_cache(ormid, r);
        }
        
        inline HouseOwnersLoaded() {
            for(new r = 0; r < cache_num_rows(); r++) {
                new ORM:ormid = g_HouseOwner[r][orm_ID] = orm_create("houseOwners");
                
                orm_addvar_int(ormid, g_HouseOwner[r][house_ID], "house_ID");
                orm_addvar_int(ormid, g_HouseOwner[r][owner_ID], "owner_ID");
                
                orm_apply_cache(ormid, r);
            }
            
            inline SellHousesLoaded() {
                for(new r = 0; r < cache_num_rows(); r++) {
                    new ORM:ormid = g_SellHouse[r][orm_ID] = orm_create("sellHouses");
                    
                    orm_addvar_int(ormid, g_SellHouse[r][house_ID], "house_ID");
                    orm_addvar_int(ormid, g_SellHouse[r][price], "price");
                    
                    orm_apply_cache(ormid, r);
                }
                
                // now that all our arrays are filled with the data use the data to init pickups, etc.
                InitHouses();
            }
            mysql_tquery_inline(g_MysqlHandler, "", using inline SellHousesLoaded, "");
            
        }
        mysql_tquery_inline(g_MysqlHandler, "SELECT * FROM house_owners", using inline HouseOwnersLoaded, "");
        
    }
    mysql_tquery_inline(g_MysqlHandler, "SELECT * FROM houses", using inline HousesLoaded, "");
}

static InitHouses() {
    for(new i = 0; i < MAX_HOUSES; i++) {
        new pickupModel = 1273;
        
        // check if someone owns the house
        for(new j = 0; j < MAX_HOUSES; j++) {
            if(g_HouseOwner[j][house_ID] == g_House[i][ID]) {
                pickupModel = 1272;
                break;
            }
        }
        
        g_House[i][pickup] = CreatePickup(pickupModel, 1, g_House[i][entranceX], g_House[i][entranceY], g_House[i][entranceZ], VW_DEFAULT);
    }
}

IsHousePickup(pickupid) {
    for(new i = 0; i < MAX_HOUSES; i++) {
        if(pickupid == g_House[i][pickup]) {
            return i;
        }
    }
    return -1;
}