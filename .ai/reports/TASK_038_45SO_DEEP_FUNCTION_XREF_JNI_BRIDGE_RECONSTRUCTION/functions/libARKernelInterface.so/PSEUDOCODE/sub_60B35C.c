// Function: sub_60B35C
// RVA: 0x60b35c, Size: 240 bytes
int64_t sub_60B35C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0x60b398
    sub_60DD98(...); // call internal at 0x60b3ac
    _Znwm(...); // call PLT API at 0x60b3b8
    _ZNSt6__ndk115__thread_structC1Ev(...); // call PLT API at 0x60b3c0
    _Znwm(...); // call PLT API at 0x60b3c8
    pthread_create(...); // call PLT API at 0x60b3e4
    sub_60CFF4(...); // call internal at 0x60b3f4
    _ZNSt6__ndk16threadD1Ev(...); // call PLT API at 0x60b410
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x60b438
    const char* str = "thread constructor failed";
    _ZNSt6__ndk120__throw_system_errorEiPKc(...); // call PLT API at 0x60b444
    _ZSt9terminatev(...); // call PLT API at 0x60b448
}
