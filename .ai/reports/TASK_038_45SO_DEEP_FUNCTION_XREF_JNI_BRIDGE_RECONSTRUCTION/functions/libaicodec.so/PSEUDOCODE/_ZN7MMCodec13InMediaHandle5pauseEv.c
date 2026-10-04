// Function: MMCodec::InMediaHandle::pause()
// RVA: 0x1436a0, Size: 348 bytes
int64_t _ZN7MMCodec13InMediaHandle5pauseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x1436d0
    const char* s_88f22 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Stream index=%d needn't deal
"; // string xref
    const char* s_8ef9d = "pause"; // string xref
    const char* s_6ea7a = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Stream index=%d needn't deal

"; // string xref
    pthread_self(...); // call imported API via PLT at 0x14375c
    const char* s_7d752 = "MTMV_AICodec";
    __android_log_print(...); // call imported API via PLT at 0x143784
    pthread_self(...); // call imported API via PLT at 0x143798
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1437bc
    (*x8)(...); // indirect call at 0x1437d8
    return a0;
}
