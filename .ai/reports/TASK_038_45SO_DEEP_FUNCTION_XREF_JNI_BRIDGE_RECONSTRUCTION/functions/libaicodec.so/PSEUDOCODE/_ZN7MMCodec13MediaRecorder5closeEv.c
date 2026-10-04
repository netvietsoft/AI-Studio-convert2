// Function: MMCodec::MediaRecorder::close()
// RVA: 0xe63e4, Size: 276 bytes
int64_t _ZN7MMCodec13MediaRecorder5closeEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec14OutMediaHandle5closeEPNS_21EncodePerformanceInfoE(...); // call imported API via PLT at 0xe6404
    pthread_self(...); // call imported API via PLT at 0xe6430
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_81a21 = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> m_pRecorderHandle close failed"; // string xref
    const char* s_75e12 = "close"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe645c
    pthread_self(...); // call imported API via PLT at 0xe6480
    const char* s_697da = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> m_pRecorderHandle close failed
"; // string xref
    const char* s_75e12 = "close"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe64a8
    (*x8)(...); // indirect call at 0xe64c4
    (*x8)(...); // indirect call at 0xe64dc
    return a0;
}
