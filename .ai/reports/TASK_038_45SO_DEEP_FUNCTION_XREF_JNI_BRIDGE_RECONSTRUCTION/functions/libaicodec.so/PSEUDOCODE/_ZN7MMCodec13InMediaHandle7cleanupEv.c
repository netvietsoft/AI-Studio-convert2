// Function: MMCodec::InMediaHandle::cleanup()
// RVA: 0x143958, Size: 268 bytes
int64_t _ZN7MMCodec13InMediaHandle7cleanupEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x1439ac
    pthread_self(...); // call imported API via PLT at 0x1439d4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6c3df = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> HandleCtx is null!"; // string xref
    const char* s_7f519 = "cleanup"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x143a00
    pthread_self(...); // call imported API via PLT at 0x143a24
    const char* s_83883 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> HandleCtx is null!
"; // string xref
    const char* s_7f519 = "cleanup"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x143a54
    return a0;
}
