// Function: MMCodec::InMediaHandle::interruptWait(int)
// RVA: 0x142e98, Size: 272 bytes
int64_t _ZN7MMCodec13InMediaHandle13interruptWaitEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec10StreamBase13interruptWaitEv(...); // call imported API via PLT at 0x142ed8
    pthread_self(...); // call imported API via PLT at 0x142efc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7abd9 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]
"; // string xref
    const char* s_7e3dd = "interruptWait"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x142f2c
    pthread_self(...); // call imported API via PLT at 0x142f50
    const char* s_7d210 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]

"; // string xref
    const char* s_7e3dd = "interruptWait"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x142f7c
    return a0;
    return a0;
}
