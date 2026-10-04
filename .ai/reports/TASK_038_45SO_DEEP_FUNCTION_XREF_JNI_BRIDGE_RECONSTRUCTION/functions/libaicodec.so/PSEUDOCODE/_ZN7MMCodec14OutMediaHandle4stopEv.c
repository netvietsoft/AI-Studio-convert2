// Function: MMCodec::OutMediaHandle::stop()
// RVA: 0xe7610, Size: 548 bytes
int64_t _ZN7MMCodec14OutMediaHandle4stopEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13ThreadContext4stopEv(...); // call imported API via PLT at 0xe7638
    _ZN7MMCodec13ThreadContext4stopEv(...); // call imported API via PLT at 0xe7660
    _ZN7MMCodec13ThreadContext4joinEv(...); // call imported API via PLT at 0xe7670
    const char* s_89f04 = "stop"; // string xref
    const char* s_883cb = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> force quit frameQueue %p
"; // string xref
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xe76ac
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xe76b8
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xe76c0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xe76c8
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xe76d4
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xe76e0
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xe76e8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xe76f0
    _ZN7MMCodec13ThreadContext4joinEv(...); // call imported API via PLT at 0xe76fc
    pthread_self(...); // call imported API via PLT at 0xe773c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7a244 = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> force quit frameQueue %p"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe7768
    pthread_self(...); // call imported API via PLT at 0xe7788
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe77ac
    _ZN7MMCodec13ThreadContextD1Ev(...); // call imported API via PLT at 0xe77e0
    _ZdlPv(...); // call imported API via PLT at 0xe77e8
    _ZN7MMCodec13ThreadContextD1Ev(...); // call imported API via PLT at 0xe7804
    _ZdlPv(...); // call imported API via PLT at 0xe780c
    _ZN7MMCodec14OutMediaHandle13_writeTrailerEv(...); // call imported API via PLT at 0xe7830
}
