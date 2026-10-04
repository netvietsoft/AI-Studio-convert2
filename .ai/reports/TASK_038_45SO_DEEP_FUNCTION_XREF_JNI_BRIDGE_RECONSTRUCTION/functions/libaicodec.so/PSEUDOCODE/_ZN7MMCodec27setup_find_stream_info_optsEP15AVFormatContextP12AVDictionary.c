// Function: MMCodec::setup_find_stream_info_opts(AVFormatContext*, AVDictionary*)
// RVA: 0x1636bc, Size: 296 bytes
int64_t _ZN7MMCodec27setup_find_stream_info_optsEP15AVFormatContextP12AVDictionary(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_mallocz(...); // call imported API via PLT at 0x1636e4
    _ZN7MMCodec17filter_codec_optsEP12AVDictionary9AVCodecIDP15AVFormatContextP8AVStreamPK7AVCodec(...); // call imported API via PLT at 0x16371c
    return a0;
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8f255 = "[%s(%d)]:> Could not alloc memory for stream options."; // string xref
    const char* s_82a0c = "setup_find_stream_info_opts"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x163788
    const char* s_7aef1 = "%s/MTMV_AICodec: [%s(%d)]:> Could not alloc memory for stream options.
"; // string xref
    const char* s_82a0c = "setup_find_stream_info_opts"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1637c4
    return a0;
}
