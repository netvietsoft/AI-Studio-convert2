// Function: MMCodec::InMediaHandle::seek_V2(long, MMCodec::SeekMode_t)
// RVA: 0x142b3c, Size: 580 bytes
int64_t _ZN7MMCodec13InMediaHandle7seek_V2ElNS_10SeekMode_tE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x142b90
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_84937 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> time:%lld mode:%d video:%d audio:%d, hold MediaHandleContext %p"; // string xref
    const char* s_6eada = "seek_V2"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x142bd8
    pthread_self(...); // call imported API via PLT at 0x142c00
    const char* s_8499d = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> time:%lld mode:%d video:%d audio:%d, hold MediaHandleContext %p
"; // string xref
    const char* s_6eada = "seek_V2"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x142c44
    _ZN7MMCodec18MediaHandleContext15markSeekRequestElNS_10SeekMode_tE(...); // call imported API via PLT at 0x142c58
    (*x8)(...); // indirect call at 0x142ca0
    pthread_self(...); // call imported API via PLT at 0x142ccc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6b292 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> state invalid:no initialized"; // string xref
    const char* s_6eada = "seek_V2"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x142cf8
    pthread_self(...); // call imported API via PLT at 0x142d1c
    const char* s_68d51 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> state invalid:no initialized
"; // string xref
    const char* s_6eada = "seek_V2"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x142d44
    return a0;
    return a0;
}
