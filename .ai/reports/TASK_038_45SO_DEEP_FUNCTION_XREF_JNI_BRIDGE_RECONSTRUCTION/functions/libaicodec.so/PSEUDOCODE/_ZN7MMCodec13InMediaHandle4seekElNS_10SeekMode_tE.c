// Function: MMCodec::InMediaHandle::seek(long, MMCodec::SeekMode_t)
// RVA: 0x14299c, Size: 416 bytes
int64_t _ZN7MMCodec13InMediaHandle4seekElNS_10SeekMode_tE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x1429e8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_84937 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> time:%lld mode:%d video:%d audio:%d, hold MediaHandleContext %p"; // string xref
    const char* s_8387e = "seek"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x142a30
    pthread_self(...); // call imported API via PLT at 0x142a58
    const char* s_8499d = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> time:%lld mode:%d video:%d audio:%d, hold MediaHandleContext %p
"; // string xref
    const char* s_8387e = "seek"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x142a9c
    _ZN7MMCodec18MediaHandleContext15markSeekRequestElNS_10SeekMode_tE(...); // call imported API via PLT at 0x142ab0
    (*x8)(...); // indirect call at 0x142af8
    return a0;
    return a0;
}
