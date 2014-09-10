#if defined _INCLUDED_TIME
    #endinput
#endif
#define _INCLUDED_TIME

//-----------------------------------------------------

UpdateTime() {
    new h;
    gettime(h);
    
    SetWorldTime(h);
}