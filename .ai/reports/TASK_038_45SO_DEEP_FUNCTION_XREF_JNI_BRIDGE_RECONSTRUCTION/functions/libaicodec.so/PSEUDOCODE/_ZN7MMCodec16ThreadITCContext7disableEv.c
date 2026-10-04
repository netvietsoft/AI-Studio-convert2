// Function: MMCodec::ThreadITCContext::disable()
// RVA: 0x127c20, Size: 236 bytes
int64_t _ZN7MMCodec16ThreadITCContext7disableEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x127c30
    pthread_self(...); // call imported API via PLT at 0x127c54
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8d13a = "[%s(%d)]:> [ThreadITCContext(%p)](%ld):> "; // string xref
    const char* s_913d2 = "disable"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x127c80
    pthread_self(...); // call imported API via PLT at 0x127ca4
    const char* s_72e95 = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadITCContext(%p)](%ld):> 
"; // string xref
    const char* s_913d2 = "disable"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x127ccc
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x127cdc
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x127ce4
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x127d00
}
