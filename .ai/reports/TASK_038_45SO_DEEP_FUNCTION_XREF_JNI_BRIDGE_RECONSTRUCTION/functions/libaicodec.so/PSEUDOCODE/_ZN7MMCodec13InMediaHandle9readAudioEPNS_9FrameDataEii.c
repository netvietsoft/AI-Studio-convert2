// Function: MMCodec::InMediaHandle::readAudio(MMCodec::FrameData*, int, int)
// RVA: 0x142510, Size: 580 bytes
int64_t _ZN7MMCodec13InMediaHandle9readAudioEPNS_9FrameDataEii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x142554
    return a0;
    pthread_self(...); // call imported API via PLT at 0x142590
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7abd9 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1425c0
    pthread_self(...); // call imported API via PLT at 0x1425e4
    const char* s_7d210 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]

"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x142610
    return a0;
    _ZN7MMCodec13ThreadContext7isValidEv(...); // call imported API via PLT at 0x142640
    return a0;
    pthread_self(...); // call imported API via PLT at 0x142680
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0x142694
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7696c = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> read data failed: %d, read thread is invalid state %d, return eof"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1426cc
    pthread_self(...); // call imported API via PLT at 0x1426f0
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0x142704
    const char* s_83804 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> read data failed: %d, read thread is invalid state %d, return eof
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x142738
    return a0;
}
