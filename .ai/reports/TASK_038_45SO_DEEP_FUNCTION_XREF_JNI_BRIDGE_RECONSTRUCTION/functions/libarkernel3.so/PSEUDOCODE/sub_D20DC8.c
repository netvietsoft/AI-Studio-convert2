// Function: sub_D20DC8
// RVA: 0xd20dc8, Size: 136 bytes
int64_t sub_D20DC8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call PLT API at 0xd20df4
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call PLT API at 0xd20e0c
    _ZNSt6__ndk15mutex6unlockEv(...); // call PLT API at 0xd20e28
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xd20e4c
}
