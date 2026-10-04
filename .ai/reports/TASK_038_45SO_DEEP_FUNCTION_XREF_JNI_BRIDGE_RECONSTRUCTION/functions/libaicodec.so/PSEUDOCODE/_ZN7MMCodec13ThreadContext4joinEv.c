// Function: MMCodec::ThreadContext::join()
// RVA: 0x127814, Size: 436 bytes
int64_t _ZN7MMCodec13ThreadContext4joinEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_join(...); // call imported API via PLT at 0x127840
    pthread_self(...); // call imported API via PLT at 0x12786c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_84651 = "[%s(%d)]:> [ThreadContext(%p)](%ld):> pthread_join failed"; // string xref
    const char* s_7efe5 = "join"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x127898
    pthread_self(...); // call imported API via PLT at 0x1278c4
    const char* s_72e49 = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadContext(%p)](%ld):> pthread_join failed
"; // string xref
    const char* s_7efe5 = "join"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1278ec
    return a0;
    pthread_self(...); // call imported API via PLT at 0x127938
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7bb67 = "[%s(%d)]:> [ThreadContext(%p)](%ld):> thread did't create"; // string xref
    const char* s_7efe5 = "join"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x127964
    pthread_self(...); // call imported API via PLT at 0x127988
    const char* s_6afbc = "%s/MTMV_AICodec: [%s(%d)]:> [ThreadContext(%p)](%ld):> thread did't create
"; // string xref
    const char* s_7efe5 = "join"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1279b0
    return a0;
}
