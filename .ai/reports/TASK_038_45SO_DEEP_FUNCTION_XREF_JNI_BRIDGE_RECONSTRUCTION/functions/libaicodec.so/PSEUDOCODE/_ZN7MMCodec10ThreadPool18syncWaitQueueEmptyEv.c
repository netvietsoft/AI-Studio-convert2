// Function: MMCodec::ThreadPool::syncWaitQueueEmpty()
// RVA: 0x1698d8, Size: 176 bytes
int64_t _ZN7MMCodec10ThreadPool18syncWaitQueueEmptyEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x169900
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x169910
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x169920
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0x169938
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x169948
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x169950
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x16995c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x169984
}
