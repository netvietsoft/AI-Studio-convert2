// Function: MMCodec::InMediaHandle::getBufferFrameNextPts(int)
// RVA: 0x14316c, Size: 444 bytes
int64_t _ZN7MMCodec13InMediaHandle21getBufferFrameNextPtsEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x1431d8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_71d16 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]"; // string xref
    const char* s_769d4 = "getBufferFrameNextPts"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x143208
    pthread_self(...); // call imported API via PLT at 0x14322c
    const char* s_8776a = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]
"; // string xref
    const char* s_769d4 = "getBufferFrameNextPts"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x143258
    return a0;
    pthread_self(...); // call imported API via PLT at 0x143290
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d94b = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Stream %d is null, no data have found!"; // string xref
    const char* s_769d4 = "getBufferFrameNextPts"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1432c0
    pthread_self(...); // call imported API via PLT at 0x1432e4
    const char* s_84a15 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Stream %d is null, no data have found!
"; // string xref
    const char* s_769d4 = "getBufferFrameNextPts"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x143310
    return a0;
}
