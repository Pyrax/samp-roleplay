#if defined _INCLUDED_TIME
    #endinput
#endif
#define _INCLUDED_TIME

//-----------------------------------------------------

#include "./roleplay/textdraws/dateTime"

//-----------------------------------------------------

UpdateDateTime() {
    new t[3];
    
    gettime(t[0], t[1]);
    SetWorldTime(t[0]);
    UpdateTime(t[0], t[1]);
    
    getdate(t[0], t[1], t[2]);
    UpdateDate(t[0], t[1], t[2]);
}