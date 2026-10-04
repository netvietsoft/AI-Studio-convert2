// Function: MMCodec::StreamBase::interruptWait()
// RVA: 0x151aac, Size: 244 bytes
int64_t _ZN7MMCodec10StreamBase13interruptWaitEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec10FrameQueue13interruptWaitEv(...); // call imported API via PLT at 0x151acc
    return a0;
    pthread_self(...); // call imported API via PLT at 0x151b14
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89161 = "[%s(%d)]:> [StreamBase(%p)](%ld):> no init"; // string xref
    const char* s_7e3dd = "interruptWait"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x151b40
    pthread_self(...); // call imported API via PLT at 0x151b64
    const char* s_87a0d = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> no init
"; // string xref
    const char* s_7e3dd = "interruptWait"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x151b8c
    return a0;
}
