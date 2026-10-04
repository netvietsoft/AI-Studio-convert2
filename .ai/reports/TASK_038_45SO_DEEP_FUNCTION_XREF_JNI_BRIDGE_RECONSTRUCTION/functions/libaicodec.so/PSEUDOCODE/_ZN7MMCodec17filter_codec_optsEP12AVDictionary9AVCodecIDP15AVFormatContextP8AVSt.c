// Function: MMCodec::filter_codec_opts(AVDictionary*, AVCodecID, AVFormatContext*, AVStream*, AVCodec const*)
// RVA: 0x1633dc, Size: 736 bytes
int64_t _ZN7MMCodec17filter_codec_optsEP12AVDictionary9AVCodecIDP15AVFormatContextP8AVStreamPK7AVCodec(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    avcodec_get_class(...); // call imported API via PLT at 0x163430
    avcodec_find_encoder(...); // call imported API via PLT at 0x163470
    avcodec_find_decoder(...); // call imported API via PLT at 0x1634a4
    void* g_6fc01 = (void*)0x6fc01; // global ref
    av_dict_get(...); // call imported API via PLT at 0x1634dc
    void* g_6fc01 = (void*)0x6fc01; // global ref
    av_dict_get(...); // call imported API via PLT at 0x16350c
    strchr(...); // call imported API via PLT at 0x163520
    avformat_match_stream_specifier(...); // call imported API via PLT at 0x163538
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_721c5 = "[%s(%d)]:> Invalid stream specifier: %s."; // string xref
    const char* s_680fe = "check_stream_specifier"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x163584
    const char* s_91990 = "%s/MTMV_AICodec: [%s(%d)]:> Invalid stream specifier: %s.
"; // string xref
    const char* s_680fe = "check_stream_specifier"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1635c4
    av_opt_find(...); // call imported API via PLT at 0x1635ec
    av_dict_set(...); // call imported API via PLT at 0x163600
    av_opt_find(...); // call imported API via PLT at 0x163630
    void* g_201001 = (void*)0x201001; // global ref
    av_opt_find(...); // call imported API via PLT at 0x163660
    void* g_201001 = (void*)0x201001; // global ref
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1636b8
}
