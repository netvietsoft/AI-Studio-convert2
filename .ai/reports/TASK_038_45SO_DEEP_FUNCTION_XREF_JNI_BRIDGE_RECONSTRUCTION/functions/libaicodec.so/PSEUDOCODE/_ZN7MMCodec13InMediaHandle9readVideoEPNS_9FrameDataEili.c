// Function: MMCodec::InMediaHandle::readVideo(MMCodec::FrameData*, int, long, int)
// RVA: 0x142754, Size: 584 bytes
int64_t _ZN7MMCodec13InMediaHandle9readVideoEPNS_9FrameDataEili(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x14279c
    return a0;
    pthread_self(...); // call imported API via PLT at 0x1427d8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7abd9 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]
"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x142808
    pthread_self(...); // call imported API via PLT at 0x14282c
    const char* s_7d210 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]

"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x142858
    return a0;
    _ZN7MMCodec13ThreadContext7isValidEv(...); // call imported API via PLT at 0x142888
    return a0;
    pthread_self(...); // call imported API via PLT at 0x1428c8
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0x1428dc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7696c = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> read data failed: %d, read thread is invalid state %d, return eof"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x142914
    pthread_self(...); // call imported API via PLT at 0x142938
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0x14294c
    const char* s_83804 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> read data failed: %d, read thread is invalid state %d, return eof
"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x142980
    return a0;
}
