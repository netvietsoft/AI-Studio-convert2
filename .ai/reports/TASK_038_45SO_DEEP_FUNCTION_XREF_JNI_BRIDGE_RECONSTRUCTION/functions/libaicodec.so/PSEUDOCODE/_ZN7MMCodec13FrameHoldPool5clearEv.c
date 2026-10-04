// Function: MMCodec::FrameHoldPool::clear()
// RVA: 0x156f00, Size: 496 bytes
int64_t _ZN7MMCodec13FrameHoldPool5clearEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x156f28
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_84af0 = "[%s(%d)]:> [FrameHoldPool(%p)](%ld):> un ref frame %p:%p failed"; // string xref
    const char* s_7e538 = "clear"; // string xref
    const char* s_8682e = "%s/MTMV_AICodec: [%s(%d)]:> [FrameHoldPool(%p)](%ld):> un ref frame %p:%p failed
"; // string xref
    (*x8)(...); // indirect call at 0x156f8c
    pthread_self(...); // call imported API via PLT at 0x156fac
    __android_log_print(...); // call imported API via PLT at 0x156fd8
    pthread_self(...); // call imported API via PLT at 0x156fec
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x157018
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x157078
    _ZdlPv(...); // call imported API via PLT at 0x157080
    const char* s_84008 = "r(%p)](%ld):> fail to send frame to RecorderHandle::audio %d
"; // string xref
    (*x8)(...); // indirect call at 0x1570b4
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0x1570bc
    sub_D867C(...); // call internal func at 0x1570c4
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1570d0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1570e4
}
