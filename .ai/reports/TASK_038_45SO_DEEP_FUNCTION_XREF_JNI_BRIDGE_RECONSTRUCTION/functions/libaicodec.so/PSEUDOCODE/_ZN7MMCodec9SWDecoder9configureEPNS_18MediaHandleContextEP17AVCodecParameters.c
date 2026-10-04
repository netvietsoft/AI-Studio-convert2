// Function: MMCodec::SWDecoder::configure(MMCodec::MediaHandleContext*, AVCodecParameters*)
// RVA: 0x148018, Size: 4008 bytes
int64_t _ZN7MMCodec9SWDecoder9configureEPNS_18MediaHandleContextEP17AVCodecParameters(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x148088
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89020 = "[%s(%d)]:> [SWDecoder(%p)](%ld):> already configure!"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1480b4
    pthread_self(...); // call imported API via PLT at 0x1480d8
    const char* s_6a25f = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> already configure!
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x148100
    pthread_self(...); // call imported API via PLT at 0x14812c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_903cc = "[%s(%d)]:> [SWDecoder(%p)](%ld):> input parameter is invalid"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x148158
    pthread_self(...); // call imported API via PLT at 0x14817c
    const char* s_797ab = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> input parameter is invalid
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1481a4
    return a0;
    const char* s_794d0 = "audio track
"; // string xref
    _ZNKSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE4findIS7_EENS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEERKT_(...); // call imported API via PLT at 0x148224
    _ZdlPv(...); // call imported API via PLT at 0x148240
    void* g_2014d0 = (void*)0x2014d0; // global ref
    sub_148FC0(...); // call internal func at 0x14826c
    sub_D2278(...); // call internal func at 0x14829c
    _ZdlPv(...); // call imported API via PLT at 0x1482ac
    _ZdlPv(...); // call imported API via PLT at 0x1482bc
    const char* s_6b935 = "hw_cpu_frame"; // string xref
    void* g_2014d0 = (void*)0x2014d0; // global ref
    _ZNKSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE4findIS7_EENS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEERKT_(...); // call imported API via PLT at 0x1482f4
    _ZdlPv(...); // call imported API via PLT at 0x148308
    sub_148FC0(...); // call internal func at 0x148338
    sub_D2278(...); // call internal func at 0x148360
    _ZdlPv(...); // call imported API via PLT at 0x148370
    _ZdlPv(...); // call imported API via PLT at 0x1483c4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7f530 = "[%s(%d)]:> _avMediaType=%d _mediaHandle->_codecStrategyConfig=%u
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x148410
    avcodec_alloc_context3(...); // call imported API via PLT at 0x148434
    avcodec_parameters_to_context(...); // call imported API via PLT at 0x148444
    const char* s_72616 = "webp"; // string xref
    strcmp(...); // call imported API via PLT at 0x148470
    avcodec_find_decoder(...); // call imported API via PLT at 0x148480
    const char* s_71dd6 = "%s/MTMV_AICodec: [%s(%d)]:> _avMediaType=%d _mediaHandle->_codecStrategyConfig=%u

"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1484f0
    avcodec_alloc_context3(...); // call imported API via PLT at 0x148500
    pthread_self(...); // call imported API via PLT at 0x148524
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_826f5 = "[%s(%d)]:> [SWDecoder(%p)](%ld):> alloc decoder error!"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x148550
    pthread_self(...); // call imported API via PLT at 0x14856c
    const char* s_7be76 = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> alloc decoder error!
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x148594
    pthread_self(...); // call imported API via PLT at 0x1485bc
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x1485c8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8efd1 = "[%s(%d)]:> [SWDecoder(%p)](%ld):> Copy parameter to codec context error! %s"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1485f8
    pthread_self(...); // call imported API via PLT at 0x148614
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x148620
    const char* s_90409 = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> Copy parameter to codec context error! %s
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14864c
    const char* s_81279 = "libwebp"; // string xref
    avcodec_find_decoder_by_name(...); // call imported API via PLT at 0x148668
    const char* s_7bebf = "mpeg4_mediacodec"; // string xref
    pthread_self(...); // call imported API via PLT at 0x1486e0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7f572 = "[%s(%d)]:> [SWDecoder(%p)](%ld):> Cannot support this media type"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14870c
    pthread_self(...); // call imported API via PLT at 0x148728
    const char* s_68e8d = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> Cannot support this media type
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x148750
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7f5b3 = "[%s(%d)]:> Find decode by name %s
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x148790
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7f5b3 = "[%s(%d)]:> Find decode by name %s
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1487dc
    pthread_self(...); // call imported API via PLT at 0x148804
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_75454 = "[%s(%d)]:> [SWDecoder(%p)](%ld):> Find decode by name %s"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x148834
    avcodec_find_decoder_by_name(...); // call imported API via PLT at 0x148848
    const char* s_90467 = "%s/MTMV_AICodec: [%s(%d)]:> Find decode by name %s

"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14888c
    pthread_self(...); // call imported API via PLT at 0x1488b0
    avcodec_get_name(...); // call imported API via PLT at 0x1488c4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7ac83 = "[%s(%d)]:> [SWDecoder(%p)](%ld):> No codec could be found with id '%s'"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1488f4
    pthread_self(...); // call imported API via PLT at 0x148910
    avcodec_get_name(...); // call imported API via PLT at 0x148924
    const char* s_8a70c = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> No codec could be found with id '%s'
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    const char* s_90467 = "%s/MTMV_AICodec: [%s(%d)]:> Find decode by name %s

"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x148980
    pthread_self(...); // call imported API via PLT at 0x1489a8
    const char* s_6eb99 = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> Find decode by name %s
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1489d4
    avcodec_find_decoder_by_name(...); // call imported API via PLT at 0x1489dc
    pthread_self(...); // call imported API via PLT at 0x148a00
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_91763 = "[%s(%d)]:> [SWDecoder(%p)](%ld):> No codec could be found with name '%s'"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x148a30
    avcodec_find_decoder(...); // call imported API via PLT at 0x148a48
    pthread_self(...); // call imported API via PLT at 0x148a8c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_81281 = "[%s(%d)]:> [SWDecoder(%p)](%ld):> The maximum value for lowres supported by the decoder is %d"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x148abc
    pthread_self(...); // call imported API via PLT at 0x148adc
    const char* s_9049c = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> The maximum value for lowres supported by the decoder is %d
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x148b08
    _ZN7MMCodec17filter_codec_optsEP12AVDictionary9AVCodecIDP15AVFormatContextP8AVStreamPK7AVCodec(...); // call imported API via PLT at 0x148b38
    const char* s_6f31c = "threads"; // string xref
    av_dict_get(...); // call imported API via PLT at 0x148b50
    sub_1490A8(...); // call internal func at 0x148b74
    const char* s_6f31c = "threads"; // string xref
    pthread_self(...); // call imported API via PLT at 0x148ba4
    const char* s_7548d = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> No codec could be found with name '%s'
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x148bd0
    avcodec_find_decoder(...); // call imported API via PLT at 0x148bdc
    pthread_self(...); // call imported API via PLT at 0x148c00
    avcodec_get_name(...); // call imported API via PLT at 0x148c14
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7ac83 = "[%s(%d)]:> [SWDecoder(%p)](%ld):> No codec could be found with id '%s'"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x148c44
    pthread_self(...); // call imported API via PLT at 0x148c60
    avcodec_get_name(...); // call imported API via PLT at 0x148c74
    const char* s_8a70c = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> No codec could be found with id '%s'
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x148ca0
    const char* s_6f31c = "threads"; // string xref
    const char* s_69602 = "auto"; // string xref
    av_dict_set(...); // call imported API via PLT at 0x148cc4
    const char* s_6b373 = "lowres"; // string xref
    av_dict_set_int(...); // call imported API via PLT at 0x148ce0
    const char* s_7f5d6 = "refcounted_frames"; // string xref
    void* g_7e345 = (void*)0x7e345; // global ref
    av_dict_set(...); // call imported API via PLT at 0x148d08
    avcodec_open2(...); // call imported API via PLT at 0x148d18
    _ZN7MMCodec18MediaHandleContext9isPictureEi(...); // call imported API via PLT at 0x148d34
    avcodec_get_name(...); // call imported API via PLT at 0x148d40
    strlen(...); // call imported API via PLT at 0x148d4c
    const char* s_81001 = "CurveSpeedEffect(%p)](%ld):> resamper is null"; // string xref
    av_strlcpy(...); // call imported API via PLT at 0x148d68
    void* g_6fc01 = (void*)0x6fc01; // global ref
    av_dict_get(...); // call imported API via PLT at 0x148d80
    pthread_self(...); // call imported API via PLT at 0x148da4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67f0d = "[%s(%d)]:> [SWDecoder(%p)](%ld):> Option %s not found."; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x148dd4
    pthread_self(...); // call imported API via PLT at 0x148df0
    const char* s_84aa7 = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> Option %s not found.
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x148e1c
    pthread_self(...); // call imported API via PLT at 0x148e44
    avcodec_get_name(...); // call imported API via PLT at 0x148e58
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x148e68
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_9050c = "[%s(%d)]:> [SWDecoder(%p)](%ld):> Open codec %s error return %d %s !"; // string xref
    const char* s_840a6 = "configure"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x148ea0
    pthread_self(...); // call imported API via PLT at 0x148ebc
    avcodec_get_name(...); // call imported API via PLT at 0x148ed0
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x148ee0
    const char* s_86629 = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> Open codec %s error return %d %s !
"; // string xref
    const char* s_840a6 = "configure"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x148f14
    av_dict_free(...); // call imported API via PLT at 0x148f2c
    avcodec_close(...); // call imported API via PLT at 0x148f48
    avcodec_free_context(...); // call imported API via PLT at 0x148f50
    const char* s_8d76d = "h264_mediacodec"; // string xref
    const char* s_84a97 = "hevc_mediacodec"; // string xref
    _ZdlPv(...); // call imported API via PLT at 0x148fa0
    __stack_chk_fail(...); // call imported API via PLT at 0x148fbc
}
