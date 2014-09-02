#if defined _INCLUDED_HOUSES
    #endinput
#endif
#define _INCLUDED_HOUSES

//-----------------------------------------------------

#include "./roleplay/textdraws/houses"

//-----------------------------------------------------

#define MAX_HOUSES 500

//-----------------------------------------------------

enum E_HOUSE {
    ORM:g_orm_ID,
    g_ID,
    g_interior_ID,
    g_value,
    bool:g_locked,
    Float:g_entranceX,
    Float:g_entranceY,
    Float:g_entranceZ,
    Float:g_entranceAngle,
    Float:g_exitX,
    Float:g_exitY,
    Float:g_exitZ,
    Float:g_exitAngle,
    
    // variables that are only needed for the shopping menu
    g_model_ID,
    Float:g_cameraPosX,
    Float:g_cameraPosY,
    Float:g_cameraPosZ,
    Float:g_cameraLookAtX,
    Float:g_cameraLookAtY,
    Float:g_cameraLookAtZ,
    
    // non-stored variables
    g_entrancePickup,
    g_exitPickup
}

enum E_HOUSE_OWNER {
    ORM:g_orm_ID,
    g_house_ID,
    g_owner_ID
}

// houses being sold
enum E_SELL_HOUSE {
    ORM:g_orm_ID,
    g_house_ID,
    g_price
}

//-----------------------------------------------------

new g_House[MAX_HOUSES][E_HOUSE],
    Iterator:g_HouseIterator<MAX_HOUSES>;
new g_HouseOwner[MAX_HOUSES][E_HOUSE_OWNER],
    Iterator:g_HouseOwnerIterator<MAX_HOUSES>;
new g_SellHouse[MAX_HOUSES][E_SELL_HOUSE],
    Iterator:g_SellHouseIterator<MAX_HOUSES>;

// playerHouseOfferPage is the idx of the first house which is shown in the list
static playerHouseOfferPage[MAX_PLAYERS];
static Float:playerCamera[MAX_PLAYERS][2][3];

//-----------------------------------------------------

ShowPlayerHouseOffers(playerid) {
    if(!IsPlayerLoggedIn(playerid)) {
        return;
    }
    
    CreateHouseOfferPlayerTD(playerid);
    
    playerHouseOfferPage[playerid] = 0;
    
    SetPlayerVirtualWorld(playerid, VW_BROKER);
    
    GetPlayerCameraPos(playerid, posArr{playerCamera[playerid][0]} );
    
    // GetPlayerCameraLookAt
    GetPlayerCameraFrontVector(playerid, posArr{playerCamera[playerid][1]} );
    playerCamera[playerid][1][0] += playerCamera[playerid][0][0];
    playerCamera[playerid][1][1] += playerCamera[playerid][0][1];
    playerCamera[playerid][1][2] += playerCamera[playerid][0][2];
    
    // use spectate mode for camera to stream nearby objects
    TogglePlayerSpectating(playerid, true);
    AttachCameraToPlayerObject(playerid, GetPlayerCameraDummy(playerid));
    
    // init first page with max. 5 houses
    inline QueryResponse() {
        new rows = cache_num_rows();
        
        if(!rows) {
            // TODO: no houses being sold
        } else {
            for(new r = 0; r < rows; r++) {
                //PushPlayerHouseOffer(playerid,
                //    cache_get_field_content_int(r, "house_ID"),
                //    cache_get_field_content_int(r, "model"),
                //    cache_get_field_content_int(r, "price"));
                SetPlayerHouseOffer(playerid, r,
                    cache_get_field_content_int(r, "house_ID"),
                    cache_get_field_content_int(r, "model"),
                    cache_get_field_content_int(r, "price"));
            }
            
            if(rows < MAX_HOUSES_PER_PAGE) {
                for(new r = rows; r < MAX_HOUSES_PER_PAGE; r++) {
                    //PushPlayerHouseOffer(playerid);
                    SetPlayerHouseOffer(playerid, r);
                }
            }
            
            SetPlayerActiveHouseOffer(playerid, 0);
            ShowPlayerHouseOfferTD(playerid);
        }
    }
    mysql_tquery_inline(g_MysqlHandler, "SELECT t.ID AS house_ID, IF(sh.price IS NULL, t.value, sh.price) AS price, t.model_ID AS model \
        FROM houses t \
        LEFT JOIN house_owners ho ON t.ID = ho.house_ID \
        LEFT JOIN sell_houses sh ON t.ID = sh.house_ID \
        WHERE ho.owner_ID IS NULL \
        LIMIT 0,5", using inline QueryResponse, "");
}

function OnNextHouseOfferPage(playerid) {
    new query[312];
    
    inline QueryResponse() {
        new rows = cache_num_rows();
        
        playerHouseOfferPage[playerid] += rows;
        
        if(!rows || (CountHousesForSale() <= playerHouseOfferPage[playerid] + 5 && rows == 5 )) {
            PlaySoundFail(playerid, 0.0, 0.0, 0.0);
        } else {
            PlaySoundSuccess(playerid, 0.0, 0.0, 0.0);
            PushPlayerHouseOffers(playerid, rows);
        }
        
        for(new r = 0, i = MAX_HOUSES_PER_PAGE-1; r < rows; r++) {
            SetPlayerHouseOffer(playerid, i - r,
                cache_get_field_content_int(r, "house_ID"),
                cache_get_field_content_int(r, "model"),
                cache_get_field_content_int(r, "price"));
        }
    }
    mysql_format(g_MysqlHandler, query, sizeof query, "SELECT t.ID AS house_ID, IF(sh.price IS NULL, t.value, sh.price) AS price, t.model_ID AS model \
        FROM houses t \
        LEFT JOIN house_owners ho ON t.ID = ho.house_ID \
        LEFT JOIN sell_houses sh ON t.ID = sh.house_ID \
        WHERE ho.owner_ID IS NULL \
        LIMIT %i,5", playerHouseOfferPage[playerid] + 5);
    mysql_tquery_inline(g_MysqlHandler, query, using inline QueryResponse, "");
}

function OnPrevHouseOfferPage(playerid) {
    new query[312];
    
    if(playerHouseOfferPage[playerid] == 0) {
        PlaySoundFail(playerid, 0.0, 0.0, 0.0);
        return;
    }
    
    if(playerHouseOfferPage[playerid] - MAX_HOUSES_PER_PAGE < 0) {
        // prevent negative values on SQL limit
        playerHouseOfferPage[playerid] = MAX_HOUSES_PER_PAGE;
    }
    
    inline QueryResponse() {
        new rows = cache_num_rows();
        
        playerHouseOfferPage[playerid] -= rows;
        
        if(!rows) {
            PlaySoundFail(playerid, 0.0, 0.0, 0.0);
        } else {
            PlaySoundSuccess(playerid, 0.0, 0.0, 0.0);
            PullPlayerHouseOffers(playerid, rows);
        }
        
        for(new r = 0; r < rows; r++) {
            SetPlayerHouseOffer(playerid, r,
                cache_get_field_content_int(r, "house_ID"),
                cache_get_field_content_int(r, "model"),
                cache_get_field_content_int(r, "price"));
        }
    }
    mysql_format(g_MysqlHandler, query, sizeof query, "SELECT t.ID AS house_ID, IF(sh.price IS NULL, t.value, sh.price) AS price, t.model_ID AS model \
        FROM houses t \
        LEFT JOIN house_owners ho ON t.ID = ho.house_ID \
        LEFT JOIN sell_houses sh ON t.ID = sh.house_ID \
        WHERE ho.owner_ID IS NULL \
        LIMIT %i,5", playerHouseOfferPage[playerid] - 5);
    mysql_tquery_inline(g_MysqlHandler, query, using inline QueryResponse, "");
}

static ORM:CreateHouseORM(idx) {
    new ORM:ormid = g_House[idx][g_orm_ID] = orm_create("houses");
    
    orm_addvar_int(ormid, g_House[idx][g_ID], "ID");
    orm_setkey(ormid, "ID");
    
    orm_addvar_int(ormid, g_House[idx][g_interior_ID], "interior_ID");
    orm_addvar_int(ormid, g_House[idx][g_value], "value");
    orm_addvar_int(ormid, g_House[idx][g_locked], "locked");
    orm_addvar_float(ormid, g_House[idx][g_entranceX], "entranceX");
    orm_addvar_float(ormid, g_House[idx][g_entranceY], "entranceY");
    orm_addvar_float(ormid, g_House[idx][g_entranceZ], "entranceZ");
    orm_addvar_float(ormid, g_House[idx][g_entranceAngle], "entranceAngle");
    orm_addvar_float(ormid, g_House[idx][g_exitX], "exitX");
    orm_addvar_float(ormid, g_House[idx][g_exitY], "exitY");
    orm_addvar_float(ormid, g_House[idx][g_exitZ], "exitZ");
    orm_addvar_float(ormid, g_House[idx][g_exitAngle], "exitAngle");
    
    orm_addvar_int(ormid, g_House[idx][g_model_ID], "model_ID");
    orm_addvar_float(ormid, g_House[idx][g_cameraPosX], "cameraPosX");
    orm_addvar_float(ormid, g_House[idx][g_cameraPosY], "cameraPosY");
    orm_addvar_float(ormid, g_House[idx][g_cameraPosZ], "cameraPosZ");
    orm_addvar_float(ormid, g_House[idx][g_cameraLookAtX], "cameraLookAtX");
    orm_addvar_float(ormid, g_House[idx][g_cameraLookAtY], "cameraLookAtY");
    orm_addvar_float(ormid, g_House[idx][g_cameraLookAtZ], "cameraLookAtZ");
    return ormid;
}

static ORM:CreateHouseOwnerORM(idx) {
    new ORM:ormid = g_HouseOwner[idx][g_orm_ID] = orm_create("house_owners");
    
    orm_addvar_int(ormid, g_HouseOwner[idx][g_house_ID], "house_ID");
    orm_addvar_int(ormid, g_HouseOwner[idx][g_owner_ID], "owner_ID");
    return ormid;
}

static ORM:CreateSellHousesORM(idx) {
    new ORM:ormid = g_SellHouse[idx][g_orm_ID] = orm_create("sell_houses");
    
    orm_addvar_int(ormid, g_SellHouse[idx][g_house_ID], "house_ID");
    orm_addvar_int(ormid, g_SellHouse[idx][g_price], "price");
    return ormid;
}

LoadHousesFromDatabase() {
    inline HousesLoaded() {
        for(new r = 0; r < cache_num_rows(); r++) {
            new ORM:ormid = CreateHouseORM(Iter_Free(g_HouseIterator));
            // store data of the cache in the ORM
            orm_apply_cache(ormid, r);
            Iter_Add(g_HouseIterator, r);
        }
        
        inline HouseOwnersLoaded() {
            for(new r = 0; r < cache_num_rows(); r++) {
                new ORM:ormid = CreateHouseOwnerORM(Iter_Free(g_HouseOwnerIterator));
                orm_apply_cache(ormid, r);
                Iter_Add(g_HouseOwnerIterator, r);
            }
            
            inline SellHousesLoaded() {
                for(new r = 0; r < cache_num_rows(); r++) {
                    new ORM:ormid = CreateSellHousesORM(Iter_Free(g_SellHouseIterator));
                    orm_apply_cache(ormid, r);
                    Iter_Add(g_SellHouseIterator, r);
                }
                
                // now that all our arrays are filled with the data use the data to init pickups, etc.
                InitHouses();
            }
            mysql_tquery_inline(g_MysqlHandler, "SELECT * FROM sell_houses", using inline SellHousesLoaded, "");
            
        }
        mysql_tquery_inline(g_MysqlHandler, "SELECT * FROM house_owners", using inline HouseOwnersLoaded, "");
        
    }
    mysql_tquery_inline(g_MysqlHandler, "SELECT * FROM houses", using inline HousesLoaded, "");
}

static InitHouses() {
    foreach(new i : g_HouseIterator) {
        if(g_House[i][g_ID] != 0) {
            new pickupModel = 1273;
            
            // check if someone owns the house
            foreach(new j : g_HouseOwnerIterator) {
                if(g_HouseOwner[j][g_house_ID] == g_House[i][g_ID]) {
                    pickupModel = 1272;
                    break;
                }
            }
            
            g_House[i][g_entrancePickup] = CreatePickup(pickupModel, 1, g_House[i][g_entranceX], g_House[i][g_entranceY], g_House[i][g_entranceZ], VW_DEFAULT);
            g_House[i][g_exitPickup] = CreatePickup(19133, 1, g_House[i][g_exitX], g_House[i][g_exitY], g_House[i][g_exitZ], VW_OFFSET_HOUSES + g_House[i][g_ID]);
        }
    }
}

IsHousePickup(pickupid) {
    foreach(new i : g_HouseIterator) {
        if(pickupid == g_House[i][g_entrancePickup]) {
            return i;
        }
    }
    return -1;
}

IsAtHouseEntrance(playerid, houseid) {
    return IsPlayerInRangeOfPoint(playerid, PICKUP_RANGE, g_House[houseid][g_entranceX], g_House[houseid][g_entranceY], g_House[houseid][g_entranceZ]);
}

IsAtHouseExit(playerid, houseid) {
    return IsPlayerInRangeOfPoint(playerid, PICKUP_RANGE, g_House[houseid][g_exitX], g_House[houseid][g_exitY], g_House[houseid][g_exitZ]);
}

EnterHouse(playerid, houseid) {
    if(!g_House[houseid][g_locked] || GetHouseOwnerByHouseID(houseid) == GetPlayerID(playerid)) {
        SetPlayerVirtualWorld(playerid, VW_OFFSET_HOUSES + g_House[houseid][g_ID]);
        SetPlayerInterior(playerid, g_House[houseid][g_interior_ID]);
        SetPlayerPos(playerid, g_House[houseid][g_exitX], g_House[houseid][g_exitY], g_House[houseid][g_exitZ]);
        SetPlayerFacingAngle(playerid, 180.0-g_House[houseid][g_exitAngle]);
        return 1;
    }
    return 0;
}

LeaveHouse(playerid, houseid) {
    if(!g_House[houseid][g_locked] || GetHouseOwnerByHouseID(houseid) == GetPlayerID(playerid)) {
        SetPlayerVirtualWorld(playerid, VW_DEFAULT);
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, g_House[houseid][g_entranceX], g_House[houseid][g_entranceY], g_House[houseid][g_entranceZ]);
        SetPlayerFacingAngle(playerid, 180.0-g_House[houseid][g_entranceAngle]);
        return 1;
    }
    return 0;
}

GetHouseOwnerByHouseID(houseid) {
    return g_HouseOwner[GetHouseOwnerIdxByHouseID(houseid)][g_owner_ID];
}

/**
 * BuyHouse(playerid, houseid)
 *
 * returns
 *     (0)    - Player has not enough money
 *     (1)    - Player bought house successfully
 *     (-1)   - House is not listed for sale
 */
BuyHouse(playerid, houseid) {
    new bool:houseForSale = false,
        oldOwner = GetHouseOwnerIdxByHouseID(houseid);
        price = -1,
        sellHouseIdx = -1;
    
    if(oldOwner == -1) {
        houseForSale = true;
        price = g_House[GetHouseIdxByID(houseid)][g_value];
    } else {
        foreach(new i : g_SellHouseIterator) {
            if(g_SellHouse[i][g_house_ID] == houseid) {
                sellHouseIdx = i;
                houseForSale = true;
                price = g_SellHouse[i][g_price];
                break;
            }
        }
    }
    
    if(houseForSale) {
        if(GetPlayerMoney(playerid) < price) {
            return 0;
        } else {
            GivePlayerMoney(playerid, -price);
            
            new idx = Iter_Free(g_HouseOwnerIterator),
                houseIdx = GetHouseIdxByID(houseid),
                ORM:ormid = CreateHouseOwnerORM(idx),
                bool:vendorOnline = false;
            
            g_HouseOwner[idx][g_owner_ID] = GetPlayerID(playerid);
            g_HouseOwner[idx][g_house_ID] = houseid;
            orm_insert(ormid);
            Iter_Add(g_HouseOwnerIterator, idx);
            if(sellHouseIdx != -1) {
                orm_delete(g_SellHouse[sellHouseIdx][g_orm_ID]);
                Iter_Remove(g_SellHouseIterator, sellHouseIdx);
            }
            
            // change pickup-model of entrance
            DestroyPickup(g_House[houseIdx][entrancePickup]);
            g_House[houseIdx][entrancePickup] = CreatePickup(1272, 1, g_House[houseIdx][g_entranceX], g_House[houseIdx][g_entranceY], g_House[houseIdx][g_entranceZ], VW_DEFAULT);
            
            // give the vendor his money for the sold house
            // first check if he is online
            foreach(new i : Player) {
                if(GetPlayerID(i) == oldOwner) {
                    GivePlayerMoney(i, price);
                    vendorOnline = true;
                    break;
                }
            }
            // if he is not online, directly change his money in the database
            if(!vendorOnline) {
                new query[128];
                mysql_format(g_MysqlHandler, query, sizeof query, "UPDATE players SET money = money - %d WHERE ID = %d", price, oldOwner);
                mysql_tquery(g_MysqlHandler, query);
            }
            
            return 1;
        }
    } else {
        return -1;
    }
}

/**
 * SellHouse(playerid, houseid, price)
 *
 * returns
 *    (0)    - Invalid price
 *    (1)    - House has been successfully listed for sale
 *    (-1)   - Player does not own the specified house
 */
SellHouse(playerid, houseid, price) {
    if(price <= 0) {
        return 0;
    }
    
    if(GetHouseOwnerByHouseID(houseid) != GetPlayerID(playerid)) {
        return -1;
    }
    
    new idx = Iter_Free(g_SellHouseIterator),
        houseIdx = GetHouseIdxByHouseID(houseid),
        ORM:ormid = CreateSellHouseORM(idx);
    
    // add house to sale
    g_SellHouse[idx][g_house_ID] = houseid;
    g_SellHouse[idx][g_price] = price;
    orm_insert(ormid);
    Iter_Add(g_SellHouseIterator, idx);
    
    // change pickup-model of entrance
    DestroyPickup(g_House[houseIdx][entrancePickup]);
    g_House[houseIdx][entrancePickup] = CreatePickup(1273, 1, g_House[houseIdx][g_entranceX], g_House[houseIdx][g_entranceY], g_House[houseIdx][g_entranceZ], VW_DEFAULT);
    
    return 1;
}

SetPlayerLookAtHouse(playerid, houseid) {
    new idx = GetHouseIdxByID(houseid);
    
    SetPlayerCameraPos(playerid, posArr{playerCamera[playerid][0]});
    SetPlayerCameraLookAt(playerid, posArr{playerCamera[playerid][1]});
    
    InterpolateCameraPos(playerid, posArr{playerCamera[playerid][0]}, g_House[idx][g_cameraPosX], g_House[idx][g_cameraPosY], g_House[idx][g_cameraPosZ], 2000, CAMERA_MOVE);
    InterpolateCameraLookAt(playerid, posArr{playerCamera[playerid][1]}, g_House[idx][g_cameraLookAtX], g_House[idx][g_cameraLookAtY], g_House[idx][g_cameraLookAtZ], 2000, CAMERA_MOVE);
    
    playerCamera[playerid][0][0] = g_House[idx][g_cameraPosX];
    playerCamera[playerid][0][1] = g_House[idx][g_cameraPosY];
    playerCamera[playerid][0][2] = g_House[idx][g_cameraPosZ];
    
    playerCamera[playerid][1][0] = g_House[idx][g_cameraLookAtX];
    playerCamera[playerid][1][1] = g_House[idx][g_cameraLookAtY];
    playerCamera[playerid][1][2] = g_House[idx][g_cameraLookAtZ];
}

static GetHouseIdxByID(houseid) {
    foreach(new i : g_HouseIterator) {
        if(g_House[i][g_ID] == houseid) {
            return i;
        }
    }
    return -1;
}

static GetHouseOwnerIdxByHouseID(houseid) {
    foreach(new i : g_HouseOwnerIterator) {
        if(g_HouseOwner[i][g_house_ID] == houseid) {
            return i;
        }
    }
    return -1;
}

static GetSellHouseIdxByHouseID(houseid) {
    foreach(new i : g_SellHouseIterator) {
        if(g_SellHouse[i][g_house_ID] == houseid) {
            return i;
        }
    }
    return -1;
}

static CountHousesForSale() {
    return Iter_Count(g_HouseIterator) - Iter_Count(g_HouseOwnerIterator);
}