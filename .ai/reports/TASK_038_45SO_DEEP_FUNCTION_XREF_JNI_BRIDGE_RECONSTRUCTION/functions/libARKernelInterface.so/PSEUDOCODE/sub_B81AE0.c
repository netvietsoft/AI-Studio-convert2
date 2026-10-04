// Function: sub_B81AE0
// RVA: 0xb81ae0, Size: 152 bytes
int64_t sub_B81AE0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0xb81b0c
    _ZNSt6__ndk115__thread_structC1Ev(...); // call PLT API at 0xb81b14
    _Znwm(...); // call PLT API at 0xb81b1c
    pthread_create(...); // call PLT API at 0xb81b50
    return a0;
    const char* str = "thread constructor failed";
    _ZNSt6__ndk120__throw_system_errorEiPKc(...); // call PLT API at 0xb81b74
}
