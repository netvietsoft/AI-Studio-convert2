// Function: sub_4E3EC
// RVA: 0x4e3ec, Size: 196 bytes
int64_t sub_4E3EC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk119__thread_local_dataEv(...); // call imported API via PLT at 0x4e410
    pthread_setspecific(...); // call imported API via PLT at 0x4e420
    sub_4E640(...); // call internal func at 0x4e440
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x4e4ac
}
