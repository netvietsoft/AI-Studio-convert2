// Function: MMCodec::MediaHandleContext::markSeekRequest(long, MMCodec::SeekMode_t)
// RVA: 0x146aa8, Size: 432 bytes
int64_t _ZN7MMCodec18MediaHandleContext15markSeekRequestElNS_10SeekMode_tE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x146ad4
    _ZN7MMCodec18MediaHandleContext12needSeekFileEli(...); // call imported API via PLT at 0x146b34
    _ZN7MMCodec11PacketQueue6setEofEb(...); // call imported API via PLT at 0x146b44
    _ZN7MMCodec11PacketQueue8tagFlushEv(...); // call imported API via PLT at 0x146b4c
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x146b68
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x146b80
    pthread_self(...); // call imported API via PLT at 0x146ba4
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7be32 = "[%s(%d)]:> [MediaHandleContext(%p)](%ld):> avformat context is null"; // string xref
    const char* s_769ea = "markSeekRequest"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x146bd0
    pthread_self(...); // call imported API via PLT at 0x146bf4
    const char* s_8bc91 = "%s/MTMV_AICodec: [%s(%d)]:> [MediaHandleContext(%p)](%ld):> avformat context is null
"; // string xref
    const char* s_769ea = "markSeekRequest"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x146c2c
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x146c4c
}
