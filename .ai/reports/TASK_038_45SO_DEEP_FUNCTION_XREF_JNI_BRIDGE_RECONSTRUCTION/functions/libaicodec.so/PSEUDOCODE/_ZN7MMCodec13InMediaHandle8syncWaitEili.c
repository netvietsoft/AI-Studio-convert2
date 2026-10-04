// Function: MMCodec::InMediaHandle::syncWait(int, long, int)
// RVA: 0x142d80, Size: 280 bytes
int64_t _ZN7MMCodec13InMediaHandle8syncWaitEili(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec10StreamBase8syncWaitEli(...); // call imported API via PLT at 0x142dc8
    pthread_self(...); // call imported API via PLT at 0x142dec
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7abd9 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]
"; // string xref
    const char* s_7322f = "syncWait"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x142e1c
    pthread_self(...); // call imported API via PLT at 0x142e40
    const char* s_7d210 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]

"; // string xref
    const char* s_7322f = "syncWait"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x142e6c
    return a0;
    return a0;
}
