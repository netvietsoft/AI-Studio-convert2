// Function: MMCodec::ThreadITCContext::~ThreadITCContext()
// RVA: 0x127abc, Size: 356 bytes
int64_t _ZN7MMCodec16ThreadITCContextD1Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x127af0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8d13a = "[%s(%d)]:> [ThreadITCContext(%p)](%ld):> "; // string xref
    const char* s_69e0a = "~ThreadITCContext"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x127b1c
    pthread_self(...); // call imported API via PLT at 0x127b40
    const char* s_72e95 = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadITCContext(%p)](%ld):> 
"; // string xref
    const char* s_69e0a = "~ThreadITCContext"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x127b68
    _ZN7MMCodec16ThreadITCContext7disableEv(...); // call imported API via PLT at 0x127b70
    pthread_self(...); // call imported API via PLT at 0x127b8c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8600c = "[%s(%d)]:> [ThreadITCContext(%p)](%ld):> end"; // string xref
    const char* s_69e0a = "~ThreadITCContext"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x127bb8
    pthread_self(...); // call imported API via PLT at 0x127bd4
    const char* s_7ce21 = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadITCContext(%p)](%ld):> end
"; // string xref
    const char* s_69e0a = "~ThreadITCContext"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x127bfc
    _ZNSt6__ndk118condition_variableD1Ev(...); // call imported API via PLT at 0x127c04
    _ZNSt6__ndk15mutexD1Ev(...); // call imported API via PLT at 0x127c18
    sub_CEBC4(...); // call internal func at 0x127c1c
}
