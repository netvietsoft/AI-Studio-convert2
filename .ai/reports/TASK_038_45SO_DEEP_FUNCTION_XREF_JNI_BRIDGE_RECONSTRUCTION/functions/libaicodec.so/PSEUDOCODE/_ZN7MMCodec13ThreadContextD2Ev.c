// Function: MMCodec::ThreadContext::~ThreadContext()
// RVA: 0x127360, Size: 364 bytes
int64_t _ZN7MMCodec13ThreadContextD2Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x127394
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8462a = "[%s(%d)]:> [ThreadContext(%p)](%ld):> "; // string xref
    const char* s_823a3 = "~ThreadContext"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1273c0
    pthread_self(...); // call imported API via PLT at 0x1273e4
    const char* s_71a4f = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadContext(%p)](%ld):> 
"; // string xref
    const char* s_823a3 = "~ThreadContext"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12740c
    pthread_self(...); // call imported API via PLT at 0x127428
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ec24 = "[%s(%d)]:> [ThreadContext(%p)](%ld):> end"; // string xref
    const char* s_823a3 = "~ThreadContext"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x127454
    pthread_self(...); // call imported API via PLT at 0x127470
    const char* s_67b14 = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadContext(%p)](%ld):> end
"; // string xref
    const char* s_823a3 = "~ThreadContext"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x127498
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x1274c4
    sub_CEBC4(...); // call internal func at 0x1274c8
}
