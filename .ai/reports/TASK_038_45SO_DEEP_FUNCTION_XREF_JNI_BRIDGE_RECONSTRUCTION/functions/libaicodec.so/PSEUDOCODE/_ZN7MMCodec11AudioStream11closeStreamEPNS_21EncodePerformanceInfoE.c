// Function: MMCodec::AudioStream::closeStream(MMCodec::EncodePerformanceInfo*)
// RVA: 0xd0bf8, Size: 644 bytes
int64_t _ZN7MMCodec11AudioStream11closeStreamEPNS_21EncodePerformanceInfoE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0xd0c30
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7eb08 = "[%s(%d)]:> [AudioStream(%p)](%ld):> write uncompressed video frame %ld"; // string xref
    const char* s_8067b = "closeStream"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd0c60
    pthread_self(...); // call imported API via PLT at 0xd0c84
    const char* s_881e6 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> write uncompressed video frame %ld
"; // string xref
    const char* s_8067b = "closeStream"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd0cb0
    avcodec_close(...); // call imported API via PLT at 0xd0cd4
    avcodec_free_context(...); // call imported API via PLT at 0xd0cdc
    av_audio_fifo_free(...); // call imported API via PLT at 0xd0ce8
    (*x8)(...); // indirect call at 0xd0d00
    (*x8)(...); // indirect call at 0xd0d18
    av_buffer_pool_uninit(...); // call imported API via PLT at 0xd0d3c
    return a0;
    pthread_self(...); // call imported API via PLT at 0xd0d74
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6b8d2 = "[%s(%d)]:> [AudioStream(%p)](%ld):> "; // string xref
    const char* s_8067b = "closeStream"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd0da0
    pthread_self(...); // call imported API via PLT at 0xd0db4
    const char* s_89b6f = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> 
"; // string xref
    const char* s_8067b = "closeStream"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd0ddc
    av_buffer_pool_uninit(...); // call imported API via PLT at 0xd0de4
    pthread_self(...); // call imported API via PLT at 0xd0df8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6b8d2 = "[%s(%d)]:> [AudioStream(%p)](%ld):> "; // string xref
    const char* s_8067b = "closeStream"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd0e24
    pthread_self(...); // call imported API via PLT at 0xd0e38
    const char* s_89b6f = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> 
"; // string xref
    const char* s_8067b = "closeStream"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd0e60
    return a0;
}
