// Function: MMCodec::ThreadITCContext::condV()
// RVA: 0x127d0c, Size: 436 bytes
int64_t _ZN7MMCodec16ThreadITCContext5condVEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x127d1c
    pthread_self(...); // call imported API via PLT at 0x127d54
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72ed1 = "[%s(%d)]:> [ThreadITCContext(%p)](%ld):> signal"; // string xref
    const char* s_8a59a = "condV"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x127d80
    pthread_self(...); // call imported API via PLT at 0x127da4
    const char* s_7f259 = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadITCContext(%p)](%ld):> signal
"; // string xref
    const char* s_8a59a = "condV"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x127dcc
    _ZNSt6__ndk118condition_variable10notify_oneEv(...); // call imported API via PLT at 0x127dd4
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x127de0
    return a0;
    pthread_self(...); // call imported API via PLT at 0x127e14
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6e8d1 = "[%s(%d)]:> [ThreadITCContext(%p)](%ld):> no available"; // string xref
    const char* s_8a59a = "condV"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x127e40
    pthread_self(...); // call imported API via PLT at 0x127e64
    const char* s_8468b = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadITCContext(%p)](%ld):> no available
"; // string xref
    const char* s_8a59a = "condV"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x127e8c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x127e98
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x127eb4
}
