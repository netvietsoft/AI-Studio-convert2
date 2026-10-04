// Function: MMCodec::MediaRecorder::finish(bool)
// RVA: 0xe62d8, Size: 268 bytes
int64_t _ZN7MMCodec13MediaRecorder6finishEb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec14OutMediaHandle6finishEPNS_21EncodePerformanceInfoE(...); // call imported API via PLT at 0xe62fc
    pthread_self(...); // call imported API via PLT at 0xe6328
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6a8c6 = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> handle finish error!
"; // string xref
    const char* s_88374 = "finish"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe6354
    pthread_self(...); // call imported API via PLT at 0xe6378
    const char* s_6e296 = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> handle finish error!

"; // string xref
    const char* s_88374 = "finish"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe63a0
    _ZN7MMCodec14OutMediaHandleD1Ev(...); // call imported API via PLT at 0xe63b0
    _ZdlPv(...); // call imported API via PLT at 0xe63b8
    return a0;
}
