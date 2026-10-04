// Function: MMCodec::MediaHandleContext::waitSeekRequest()
// RVA: 0x146c74, Size: 148 bytes
int64_t _ZN7MMCodec18MediaHandleContext15waitSeekRequestEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x146ca4
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0x146cc0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x146ce0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x146d04
}
