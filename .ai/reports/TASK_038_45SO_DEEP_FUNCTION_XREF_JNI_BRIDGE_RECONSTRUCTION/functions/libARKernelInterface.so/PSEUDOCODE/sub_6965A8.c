// Function: sub_6965A8
// RVA: 0x6965a8, Size: 144 bytes
int64_t sub_6965A8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call PLT API at 0x6965cc
    pthread_self(...); // call PLT API at 0x6965d0
    sub_696678(...); // call internal at 0x6965e8
    _ZNSt6__ndk15mutex6unlockEv(...); // call PLT API at 0x69660c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x696634
}
