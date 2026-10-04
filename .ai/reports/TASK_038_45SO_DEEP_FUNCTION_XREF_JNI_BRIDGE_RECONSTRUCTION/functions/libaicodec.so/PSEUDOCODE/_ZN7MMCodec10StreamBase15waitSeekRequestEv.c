// Function: MMCodec::StreamBase::waitSeekRequest()
// RVA: 0x1516b0, Size: 216 bytes
int64_t _ZN7MMCodec10StreamBase15waitSeekRequestEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1516e0
    _ZN7MMCodec13ThreadContext7isValidEv(...); // call imported API via PLT at 0x151700
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0x151710
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x151734
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x151768
    __stack_chk_fail(...); // call imported API via PLT at 0x151784
}
