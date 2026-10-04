// Function: MMCodec::ThreadITCContext::ThreadITCContext(int)
// RVA: 0x1279c8, Size: 244 bytes
int64_t _ZN7MMCodec16ThreadITCContextC2Ei(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x127a18
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8d13a = "[%s(%d)]:> [ThreadITCContext(%p)](%ld):> "; // string xref
    const char* s_7a899 = "ThreadITCContext"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x127a44
    pthread_self(...); // call imported API via PLT at 0x127a68
    const char* s_72e95 = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadITCContext(%p)](%ld):> 
"; // string xref
    const char* s_7a899 = "ThreadITCContext"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x127a90
    return a0;
    _ZNSt6__ndk118condition_variableD1Ev(...); // call imported API via PLT at 0x127aa8
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x127ab0
}
