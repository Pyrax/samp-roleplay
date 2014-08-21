#if defined _INCLUDED_HOUSES
    #endinput
#endif
#define _INCLUDED_HOUSES

//-----------------------------------------------------

#define MAX_HOUSES 50

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

//-----------------------------------------------------

/*ShowPlayerHouseOffers(playerid) {
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
    new ORM:ormid = g_HouseOwner[idx][g_orm_ID] = orm_create("houseOwners");
    
    orm_addvar_int(ormid, g_HouseOwner[idx][g_house_ID], "house_ID");
    orm_addvar_int(ormid, g_HouseOwner[idx][g_owner_ID], "owner_ID");
    return ormid;
}

static ORM:CreateSellHousesORM(idx) {
    new ORM:ormid = g_SellHouse[idx][g_orm_ID] = orm_create("sellHouses");
    
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
    return IsPlayerInRangeOfPoint(playerid, 1.5, g_House[houseid][g_entranceX], g_House[houseid][g_entranceY], g_House[houseid][g_entranceZ]);
}

IsAtHouseExit(playerid, houseid) {
    return IsPlayerInRangeOfPoint(playerid, 1.5, g_House[houseid][g_exitX], g_House[houseid][g_exitY], g_House[houseid][g_exitZ]);
}

EnterHouse(playerid, houseid) {
    if(!g_House[houseid][g_locked] || GetHouseOwnerByHouseID(houseid) == GetPlayerID(playerid)) {
        SetPlayerVirtualWorld(playerid, VW_OFFSET_HOUSES + g_House[houseid][g_ID]);
        SetPlayerInterior(playerid, g_House[houseid][g_interior_ID]);
        SetPlayerPos(playerid, g_House[houseid][g_exitX], g_House[houseid][g_exitY], g_House[houseid][g_exitZ]);
        SetPlayerFacingAngle(playerid, 180.0-g_House[houseid][g_entranceAngle]);
        return 1;
    }
    return 0;
}

LeaveHouse(playerid, houseid) {
    if(!g_House[houseid][g_locked] || GetHouseOwnerByHouseID(houseid) == GetPlayerID(playerid)) {
        SetPlayerVirtualWorld(playerid, VW_DEFAULT);
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, g_House[houseid][g_entranceX], g_House[houseid][g_entranceY], g_House[houseid][g_entranceZ]);
        SetPlayerFacingAngle(playerid, 180.0-g_House[houseid][g_exitAngle]);
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
        price = -1;
    
    if(oldOwner == -1) {
        houseForSale = true;
        price = g_House[GetHouseIdxByID(houseid)][g_value];
    } else {
        foreach(new i : g_SellHouseIterator) {
            if(g_SellHouse[i][g_house_ID] == houseid) {
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
                ORM:ormid = CreateHouseOwnerORM(idx),
                bool:vendorOnline = false;
            
            g_HouseOwner[idx][g_owner_ID] = GetPlayerID(playerid);
            g_HouseOwner[idx][g_house_ID] = houseid;
            orm_insert(ormid);
            Iter_Add(g_HouseOwnerIterator, idx);
            
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
    
    // add house to sale
    new idx = Iter_Free(g_SellHouseIterator);
    g_SellHouse[idx][g_house_ID] = houseid;
    g_SellHouse[idx][g_price] = price;
    Iter_Add(g_SellHouseIterator, idx);
    return 1;
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