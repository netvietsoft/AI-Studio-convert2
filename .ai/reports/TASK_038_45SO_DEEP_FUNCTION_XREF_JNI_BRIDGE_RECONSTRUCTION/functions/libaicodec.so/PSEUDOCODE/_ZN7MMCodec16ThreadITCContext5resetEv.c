// Function: MMCodec::ThreadITCContext::reset()
// RVA: 0x128460, Size: 228 bytes
int64_t _ZN7MMCodec16ThreadITCContext5resetEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x128470
    pthread_self(...); // call imported API via PLT at 0x128494
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8d13a = "[%s(%d)]:> [ThreadITCContext(%p)](%ld):> "; // string xref
    const char* s_7bba1 = "reset"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1284c0
    pthread_self(...); // call imported API via PLT at 0x1284e4
    const char* s_72e95 = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadITCContext(%p)](%ld):> 
"; // string xref
    const char* s_7bba1 = "reset"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12850c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x12851c
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x128538
}
