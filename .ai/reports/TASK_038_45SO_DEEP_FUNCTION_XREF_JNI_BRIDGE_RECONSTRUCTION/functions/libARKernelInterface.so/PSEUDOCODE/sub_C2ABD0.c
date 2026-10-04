// Function: sub_C2ABD0
// RVA: 0xc2abd0, Size: 252 bytes
int64_t sub_C2ABD0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memcmp(...); // call PLT API at 0xc2ac04
    memcpy(...); // call PLT API at 0xc2ac18
    _ZNSt6__ndk15mutex4lockEv(...); // call PLT API at 0xc2ac20
    sub_C2F0FC(...); // call internal at 0xc2ac60
    sub_72DC8C(...); // call internal at 0xc2ac74
    (*x8)(...);
    _ZNSt6__ndk15mutex6unlockEv(...); // call PLT API at 0xc2ac9c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc2acc8
}
