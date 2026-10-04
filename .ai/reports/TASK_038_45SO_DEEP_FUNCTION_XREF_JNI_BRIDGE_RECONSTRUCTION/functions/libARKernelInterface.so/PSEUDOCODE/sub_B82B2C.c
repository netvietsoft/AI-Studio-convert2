// Function: sub_B82B2C
// RVA: 0xb82b2c, Size: 152 bytes
int64_t sub_B82B2C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0xb82b58
    _ZNSt6__ndk115__thread_structC1Ev(...); // call PLT API at 0xb82b60
    _Znwm(...); // call PLT API at 0xb82b68
    pthread_create(...); // call PLT API at 0xb82b9c
    return a0;
    const char* str = "thread constructor failed";
    _ZNSt6__ndk120__throw_system_errorEiPKc(...); // call PLT API at 0xb82bc0
}
