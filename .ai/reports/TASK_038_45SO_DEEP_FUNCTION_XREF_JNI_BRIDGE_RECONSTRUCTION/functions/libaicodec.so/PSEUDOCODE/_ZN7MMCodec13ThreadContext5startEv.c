// Function: MMCodec::ThreadContext::start()
// RVA: 0x127508, Size: 676 bytes
int64_t _ZN7MMCodec13ThreadContext5startEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x12754c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_766ad = "[%s(%d)]:> [ThreadContext(%p)](%ld):> pthread_create"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x127578
    pthread_self(...); // call imported API via PLT at 0x12759c
    const char* s_8d0f3 = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadContext(%p)](%ld):> pthread_create
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1275c4
    pthread_create(...); // call imported API via PLT at 0x1275ec
    return a0;
    pthread_self(...); // call imported API via PLT at 0x127620
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67b50 = "[%s(%d)]:> [ThreadContext(%p)](%ld):> not init"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12764c
    pthread_self(...); // call imported API via PLT at 0x127670
    const char* s_7bb26 = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadContext(%p)](%ld):> not init
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x127698
    return a0;
    pthread_self(...); // call imported API via PLT at 0x1276e0
    const char* s_67200 = "start"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_88c0c = "[%s(%d)]:> [ThreadContext(%p)](%ld):> %s %d pthread_create failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x127718
    return a0;
    pthread_self(...); // call imported API via PLT at 0x12775c
    const char* s_67200 = "start"; // string xref
    const char* s_72df5 = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadContext(%p)](%ld):> %s %d pthread_create failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x127790
    return a0;
}
