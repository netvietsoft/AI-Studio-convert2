// Function: MMCodec::VideoStream::closeStream(MMCodec::EncodePerformanceInfo*)
// RVA: 0xd7e80, Size: 616 bytes
int64_t _ZN7MMCodec11VideoStream11closeStreamEPNS_21EncodePerformanceInfoE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0xd7ec0
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_85556 = "[%s(%d)]:> [VideoStream(%p)](%ld):> write uncompressed video frame %ld"; // string xref
    const char* s_8067b = "closeStream"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd7ef0
    pthread_self(...); // call imported API via PLT at 0xd7f14
    const char* s_7794a = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> write uncompressed video frame %ld
"; // string xref
    const char* s_8067b = "closeStream"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd7f40
    sws_freeContext(...); // call imported API via PLT at 0xd7f7c
    avcodec_close(...); // call imported API via PLT at 0xd7f90
    avcodec_free_context(...); // call imported API via PLT at 0xd7f98
    av_buffer_pool_uninit(...); // call imported API via PLT at 0xd7fb8
    pthread_self(...); // call imported API via PLT at 0xd7fd8
    const char* s_88256 = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> end
"; // string xref
    const char* s_8067b = "closeStream"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd8000
    return a0;
    pthread_self(...); // call imported API via PLT at 0xd8024
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6959e = "[%s(%d)]:> [VideoStream(%p)](%ld):> "; // string xref
    const char* s_8067b = "closeStream"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd8050
    pthread_self(...); // call imported API via PLT at 0xd8064
    const char* s_70f4e = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> 
"; // string xref
    const char* s_8067b = "closeStream"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd808c
    av_buffer_pool_uninit(...); // call imported API via PLT at 0xd8094
    pthread_self(...); // call imported API via PLT at 0xd80a8
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_79f8f = "[%s(%d)]:> [VideoStream(%p)](%ld):> end"; // string xref
    const char* s_8067b = "closeStream"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd80d4
}
