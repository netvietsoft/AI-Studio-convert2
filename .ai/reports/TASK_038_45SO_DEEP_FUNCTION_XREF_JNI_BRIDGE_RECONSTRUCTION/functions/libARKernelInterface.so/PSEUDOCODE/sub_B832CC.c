// Function: sub_B832CC
// RVA: 0xb832cc, Size: 152 bytes
int64_t sub_B832CC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0xb832f8
    _ZNSt6__ndk115__thread_structC1Ev(...); // call PLT API at 0xb83300
    _Znwm(...); // call PLT API at 0xb83308
    pthread_create(...); // call PLT API at 0xb8333c
    return a0;
    const char* str = "thread constructor failed";
    _ZNSt6__ndk120__throw_system_errorEiPKc(...); // call PLT API at 0xb83360
}
