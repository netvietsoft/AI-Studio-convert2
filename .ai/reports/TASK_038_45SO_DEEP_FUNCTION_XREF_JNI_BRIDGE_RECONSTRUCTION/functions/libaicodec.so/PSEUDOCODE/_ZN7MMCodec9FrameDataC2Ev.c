// Function: MMCodec::FrameData::FrameData()
// RVA: 0x1263d0, Size: 224 bytes
int64_t _ZN7MMCodec9FrameDataC2Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x126420
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67af1 = "[%s(%d)]:> [FrameData(%p)](%ld):> "; // string xref
    const char* s_6c17e = "FrameData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12644c
    pthread_self(...); // call imported API via PLT at 0x126470
    const char* s_8b74a = "%s/MTMV_AICodec: [%s(%d)]:> [FrameData(%p)](%ld):> 
"; // string xref
    const char* s_6c17e = "FrameData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1264a0
    return a0;
}
