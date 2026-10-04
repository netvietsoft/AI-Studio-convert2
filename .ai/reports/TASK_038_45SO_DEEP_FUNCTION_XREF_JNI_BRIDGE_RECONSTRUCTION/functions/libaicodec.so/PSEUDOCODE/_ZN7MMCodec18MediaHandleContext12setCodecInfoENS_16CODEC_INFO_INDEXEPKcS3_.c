// Function: MMCodec::MediaHandleContext::setCodecInfo(MMCodec::CODEC_INFO_INDEX, char const*, char const*)
// RVA: 0x147794, Size: 336 bytes
int64_t _ZN7MMCodec18MediaHandleContext12setCodecInfoENS_16CODEC_INFO_INDEXEPKcS3_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_freep(...); // call imported API via PLT at 0x1477e4
    void* g_6fc01 = (void*)0x6fc01; // global ref
    const char* s_71dcf = "%s, %s"; // string xref
    av_asprintf(...); // call imported API via PLT at 0x147808
    pthread_self(...); // call imported API via PLT at 0x147834
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7e450 = "[%s(%d)]:> [MediaHandleContext(%p)](%ld):> Codec: %s
"; // string xref
    const char* s_903b4 = "setCodecInfo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x147864
    pthread_self(...); // call imported API via PLT at 0x147888
    const char* s_6b32b = "%s/MTMV_AICodec: [%s(%d)]:> [MediaHandleContext(%p)](%ld):> Codec: %s

"; // string xref
    const char* s_903b4 = "setCodecInfo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1478c0
    return a0;
}
