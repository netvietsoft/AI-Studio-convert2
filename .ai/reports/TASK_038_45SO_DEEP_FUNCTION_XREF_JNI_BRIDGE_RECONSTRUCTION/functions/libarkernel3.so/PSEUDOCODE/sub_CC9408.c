// Function: sub_CC9408
// RVA: 0xcc9408, Size: 276 bytes
int64_t sub_CC9408(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0xcc9440
    _ZNSt6__ndk115__thread_structC1Ev(...); // call PLT API at 0xcc9448
    _Znwm(...); // call PLT API at 0xcc9450
    pthread_create(...); // call PLT API at 0xcc9484
    return a0;
    const char* str = "thread constructor failed";
    _ZNSt6__ndk120__throw_system_errorEiPKc(...); // call PLT API at 0xcc94cc
    _ZNSt6__ndk115__thread_structD1Ev(...); // call PLT API at 0xcc94d8
    _ZdlPv(...); // call PLT API at 0xcc94e8
    sub_CCAB0C(...); // call internal at 0xcc94fc
    sub_106B814(...); // call internal at 0xcc9514
    __stack_chk_fail(...); // call PLT API at 0xcc9518
}
