// Function: sub_60B4B0
// RVA: 0x60b4b0, Size: 188 bytes
int64_t sub_60B4B0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call PLT API at 0x60b4e4
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call PLT API at 0x60b4f4
    _ZNSt6__ndk15mutex6unlockEv(...); // call PLT API at 0x60b4fc
    _ZNSt6__ndk16thread4joinEv(...); // call PLT API at 0x60b50c
    sub_60DD64(...); // call internal at 0x60b514
    sub_60DE04(...); // call internal at 0x60b524
    _ZdlPv(...); // call PLT API at 0x60b52c
    sub_60DE3C(...); // call internal at 0x60b538
    sub_60DE04(...); // call internal at 0x60b540
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x60b568
}
