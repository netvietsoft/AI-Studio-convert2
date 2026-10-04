// Function: MMCodec::AndroidVideoStream::closeStream(MMCodec::EncodePerformanceInfo*)
// RVA: 0xf90dc, Size: 444 bytes
int64_t _ZN7MMCodec18AndroidVideoStream11closeStreamEPNS_21EncodePerformanceInfoE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xf911c
    pthread_self(...); // call imported API via PLT at 0xf913c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90d95 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> AndroidVideoStream close encoder failed"; // string xref
    const char* s_8067b = "closeStream"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf9168
    pthread_self(...); // call imported API via PLT at 0xf9184
    const char* s_88551 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> AndroidVideoStream close encoder failed
"; // string xref
    const char* s_8067b = "closeStream"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf91ac
    av_buffer_pool_uninit(...); // call imported API via PLT at 0xf91e4
    return a0;
    pthread_self(...); // call imported API via PLT at 0xf920c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d176 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> Write video frame %ld"; // string xref
    const char* s_8067b = "closeStream"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf923c
    pthread_self(...); // call imported API via PLT at 0xf9258
    const char* s_76008 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> Write video frame %ld
"; // string xref
    const char* s_8067b = "closeStream"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf9284
}
