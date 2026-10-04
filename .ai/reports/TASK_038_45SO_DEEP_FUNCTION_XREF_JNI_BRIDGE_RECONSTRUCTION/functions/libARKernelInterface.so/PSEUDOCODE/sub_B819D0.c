// Function: sub_B819D0
// RVA: 0xb819d0, Size: 272 bytes
int64_t sub_B819D0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0xb819fc
    _ZNSt6__ndk115__thread_structC1Ev(...); // call PLT API at 0xb81a04
    _Znwm(...); // call PLT API at 0xb81a0c
    pthread_create(...); // call PLT API at 0xb81a40
    return a0;
    const char* str = "thread constructor failed";
    _ZNSt6__ndk120__throw_system_errorEiPKc(...); // call PLT API at 0xb81a64
    _ZNSt6__ndk119__thread_local_dataEv(...); // call PLT API at 0xb81a7c
    pthread_setspecific(...); // call PLT API at 0xb81a8c
    sub_B81720(...); // call internal at 0xb81aa8
    sub_60D1BC(...); // call internal at 0xb81ac0
    _ZdlPv(...); // call PLT API at 0xb81ac8
    return a0;
}
