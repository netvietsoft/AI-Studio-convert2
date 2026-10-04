// Function: MMCodec::ThreadContext::ThreadContext()
// RVA: 0x12727c, Size: 228 bytes
int64_t _ZN7MMCodec13ThreadContextC1Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x1272bc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8462a = "[%s(%d)]:> [ThreadContext(%p)](%ld):> "; // string xref
    const char* s_78095 = "ThreadContext"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1272e8
    pthread_self(...); // call imported API via PLT at 0x12730c
    const char* s_71a4f = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadContext(%p)](%ld):> 
"; // string xref
    const char* s_78095 = "ThreadContext"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x127334
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x127354
}
