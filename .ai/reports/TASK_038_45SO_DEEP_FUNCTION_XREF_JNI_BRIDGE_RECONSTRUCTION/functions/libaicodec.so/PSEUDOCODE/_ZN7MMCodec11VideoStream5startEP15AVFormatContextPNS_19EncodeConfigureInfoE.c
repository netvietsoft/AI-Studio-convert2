// Function: MMCodec::VideoStream::start(AVFormatContext*, MMCodec::EncodeConfigureInfo*)
// RVA: 0xd566c, Size: 5812 bytes
int64_t _ZN7MMCodec11VideoStream5startEP15AVFormatContextPNS_19EncodeConfigureInfoE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE4findIS7_EENS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEERKT_(...); // call imported API via PLT at 0xd56cc
    _ZdlPv(...); // call imported API via PLT at 0xd56e4
    sub_D6D20(...); // call internal func at 0xd570c
    pthread_self(...); // call imported API via PLT at 0xd574c
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_695c3 = "[%s(%d)]:> [VideoStream(%p)](%ld):> input parameter is invalid"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd5778
    pthread_self(...); // call imported API via PLT at 0xd579c
    const char* s_78bb7 = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> input parameter is invalid
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd57c4
    sub_D2278(...); // call internal func at 0xd57e8
    _ZdlPv(...); // call imported API via PLT at 0xd57f8
    _ZdlPv(...); // call imported API via PLT at 0xd5808
    const char* s_6b935 = "hw_cpu_frame"; // string xref
    _ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE4findIS7_EENS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEERKT_(...); // call imported API via PLT at 0xd583c
    _ZdlPv(...); // call imported API via PLT at 0xd5850
    sub_D6D20(...); // call internal func at 0xd5880
    sub_D2278(...); // call internal func at 0xd58a8
    _ZdlPv(...); // call imported API via PLT at 0xd58b8
    _ZdlPv(...); // call imported API via PLT at 0xd590c
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xd5914
    avformat_new_stream(...); // call imported API via PLT at 0xd5928
    av_stream_new_side_data(...); // call imported API via PLT at 0xd596c
    sub_D6E9C(...); // call internal func at 0xd5978
    _ZN7MMCodec27flip_rotation_transfer_exifEii(...); // call imported API via PLT at 0xd5980
    _ZN7MMCodec27exif_transfer_displaymatrixEiPi(...); // call imported API via PLT at 0xd5988
    const char* s_6b001 = "reate
"; // string xref
    memcmp(...); // call imported API via PLT at 0xd5a58
    memcmp(...); // call imported API via PLT at 0xd5a6c
    void* g_201050 = (void*)0x201050; // global ref
    av_dict_set(...); // call imported API via PLT at 0xd5aa4
    pthread_self(...); // call imported API via PLT at 0xd5ad0
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xd5afc
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c47e = "[%s(%d)]:> [VideoStream(%p)](%ld):> av_dict_set metadata error!(%s:%s)[%s]"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd5b44
    pthread_self(...); // call imported API via PLT at 0xd5b68
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xd5b94
    const char* s_8abf4 = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> av_dict_set metadata error!(%s:%s)[%s]
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd5bd4
    av_stream_new_side_data(...); // call imported API via PLT at 0xd5be8
    sub_D6E9C(...); // call internal func at 0xd5bf4
    pthread_self(...); // call imported API via PLT at 0xd5c50
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8ac51 = "[%s(%d)]:> [VideoStream(%p)](%ld):> Create video stream %d "; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd5c80
    avcodec_alloc_context3(...); // call imported API via PLT at 0xd5c9c
    sub_D6F94(...); // call internal func at 0xd5d68
    const char* s_6a875 = "crf"; // string xref
    av_dict_set(...); // call imported API via PLT at 0xd5d80
    pthread_self(...); // call imported API via PLT at 0xd5da8
    const char* s_6f2ce = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> Create video stream %d 
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd5dd8
    avcodec_alloc_context3(...); // call imported API via PLT at 0xd5de0
    _Znwm(...); // call imported API via PLT at 0xd5df0
    const char* s_6e19e = "avcodec_alloc_context3 error!"; // string xref
    pthread_self(...); // call imported API via PLT at 0xd5e44
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8c7d9 = "[%s(%d)]:> [VideoStream(%p)](%ld):> %s"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd5e74
    pthread_self(...); // call imported API via PLT at 0xd5e98
    const char* s_6e165 = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> %s
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd5ed8
    (*x8)(...); // indirect call at 0xd5f44
    _ZN7MMCodec16getFFmpegCodecIDENS_11MT_CODEC_IDE(...); // call imported API via PLT at 0xd5f64
    avcodec_find_encoder(...); // call imported API via PLT at 0xd5f68
    const char* s_7d813 = "New stream error!"; // string xref
    pthread_self(...); // call imported API via PLT at 0xd5fc0
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8c7d9 = "[%s(%d)]:> [VideoStream(%p)](%ld):> %s"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd5ff0
    pthread_self(...); // call imported API via PLT at 0xd6014
    const char* s_6e165 = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> %s
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd604c
    (*x8)(...); // indirect call at 0xd60b0
    _ZdlPv(...); // call imported API via PLT at 0xd60c0
    const char* s_89cff = "libsvtav1"; // string xref
    avcodec_find_encoder_by_name(...); // call imported API via PLT at 0xd60e4
    _ZN7MMCodec16getFFmpegCodecIDENS_11MT_CODEC_IDE(...); // call imported API via PLT at 0xd60f4
    avcodec_find_encoder(...); // call imported API via PLT at 0xd60f8
    const char* s_89cff = "libsvtav1"; // string xref
    strcmp(...); // call imported API via PLT at 0xd611c
    void* g_660e2 = (void*)0x660e2; // global ref
    const char* s_82cc1 = "baseline"; // string xref
    const char* s_8c800 = "profile"; // string xref
    av_dict_set(...); // call imported API via PLT at 0xd61b8
    const char* s_79f2b = "tune"; // string xref
    av_opt_set(...); // call imported API via PLT at 0xd61dc
    pthread_self(...); // call imported API via PLT at 0xd6254
    const char* s_6e1bc = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> encode video bitrate:%d, profile:%d, crf:%f
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd6290
    const char* s_6f31c = "threads"; // string xref
    const char* s_69602 = "auto"; // string xref
    av_dict_set(...); // call imported API via PLT at 0xd62b8
    const char* s_683bd = "libwebp_anim"; // string xref
    avcodec_find_encoder_by_name(...); // call imported API via PLT at 0xd62c8
    pthread_self(...); // call imported API via PLT at 0xd6300
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_748f8 = "[%s(%d)]:> [VideoStream(%p)](%ld):> encode video bitrate:%d, profile:%d, crf:%f"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd6340
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0xd636c
    const char* s_6f31c = "threads"; // string xref
    av_dict_set(...); // call imported API via PLT at 0xd6394
    _ZdlPv(...); // call imported API via PLT at 0xd63a4
    const char* s_6e21e = "h264_nvenc"; // string xref
    const char* s_6b942 = "level"; // string xref
    const char* s_75c4f = "4.1"; // string xref
    const char* s_69607 = "av1_nvenc"; // string xref
    const char* s_89cff = "libsvtav1"; // string xref
    const char* s_79f30 = "hevc_nvenc"; // string xref
    const char* s_85538 = "h264_qsv"; // string xref
    _ZN7MMCodec16getFFmpegCodecIDENS_11MT_CODEC_IDE(...); // call imported API via PLT at 0xd63f8
    avcodec_find_encoder(...); // call imported API via PLT at 0xd63fc
    strcmp(...); // call imported API via PLT at 0xd6418
    strcmp(...); // call imported API via PLT at 0xd6428
    strcmp(...); // call imported API via PLT at 0xd6438
    strcmp(...); // call imported API via PLT at 0xd6448
    const char* s_74948 = "hevc_qsv"; // string xref
    strcmp(...); // call imported API via PLT at 0xd645c
    const char* s_83e30 = "av1_qsv"; // string xref
    strcmp(...); // call imported API via PLT at 0xd6470
    const char* s_6ce08 = "h264_amf"; // string xref
    strcmp(...); // call imported API via PLT at 0xd6484
    const char* s_6e229 = "hevc_amf"; // string xref
    strcmp(...); // call imported API via PLT at 0xd6498
    const char* s_6f324 = "av1_amf"; // string xref
    strcmp(...); // call imported API via PLT at 0xd64ac
    const char* s_6a879 = "preset"; // string xref
    av_opt_set(...); // call imported API via PLT at 0xd64d4
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xd64dc
    avcodec_open2(...); // call imported API via PLT at 0xd64f8
    strcmp(...); // call imported API via PLT at 0xd6518
    strcmp(...); // call imported API via PLT at 0xd6528
    strcmp(...); // call imported API via PLT at 0xd6538
    strcmp(...); // call imported API via PLT at 0xd6548
    const char* s_74948 = "hevc_qsv"; // string xref
    strcmp(...); // call imported API via PLT at 0xd655c
    const char* s_83e30 = "av1_qsv"; // string xref
    strcmp(...); // call imported API via PLT at 0xd6570
    const char* s_6ce08 = "h264_amf"; // string xref
    strcmp(...); // call imported API via PLT at 0xd6584
    const char* s_6e229 = "hevc_amf"; // string xref
    strcmp(...); // call imported API via PLT at 0xd6598
    const char* s_6f324 = "av1_amf"; // string xref
    strcmp(...); // call imported API via PLT at 0xd65ac
    av_opt_set(...); // call imported API via PLT at 0xd65c8
    void* g_201230 = (void*)0x201230; // global ref
    av_buffer_unref(...); // call imported API via PLT at 0xd65dc
    void* g_201228 = (void*)0x201228; // global ref
    av_buffer_unref(...); // call imported API via PLT at 0xd65f4
    const char* s_6f324 = "av1_amf"; // string xref
    strcmp(...); // call imported API via PLT at 0xd6614
    av_opt_set(...); // call imported API via PLT at 0xd6634
    void* g_201230 = (void*)0x201230; // global ref
    av_buffer_unref(...); // call imported API via PLT at 0xd6648
    void* g_201228 = (void*)0x201228; // global ref
    av_buffer_unref(...); // call imported API via PLT at 0xd6660
    strcmp(...); // call imported API via PLT at 0xd667c
    avcodec_find_encoder_by_name(...); // call imported API via PLT at 0xd6688
    av_opt_set(...); // call imported API via PLT at 0xd66a4
    void* g_201230 = (void*)0x201230; // global ref
    av_buffer_unref(...); // call imported API via PLT at 0xd66b8
    void* g_201228 = (void*)0x201228; // global ref
    av_buffer_unref(...); // call imported API via PLT at 0xd66d0
    const char* s_83e30 = "av1_qsv"; // string xref
    strcmp(...); // call imported API via PLT at 0xd66f0
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xd6700
    _ZN7MMCodec9to_stringIPcEENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEET_(...); // call imported API via PLT at 0xd6708
    const char* s_85541 = "avcodec_open2 error!"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xd671c
    _ZdlPv(...); // call imported API via PLT at 0xd6744
    pthread_self(...); // call imported API via PLT at 0xd6768
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8c7d9 = "[%s(%d)]:> [VideoStream(%p)](%ld):> %s"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd67a8
    pthread_self(...); // call imported API via PLT at 0xd67cc
    const char* s_6e165 = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> %s
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd6808
    (*x8)(...); // indirect call at 0xd6888
    _ZdlPv(...); // call imported API via PLT at 0xd689c
    _ZN7MMCodec19getVideoOuterFormatE13AVPixelFormat(...); // call imported API via PLT at 0xd68ac
    const char* s_6e21e = "h264_nvenc"; // string xref
    strcmp(...); // call imported API via PLT at 0xd68dc
    const char* s_79f30 = "hevc_nvenc"; // string xref
    strcmp(...); // call imported API via PLT at 0xd68f0
    const char* s_69607 = "av1_nvenc"; // string xref
    strcmp(...); // call imported API via PLT at 0xd6904
    const char* s_85538 = "h264_qsv"; // string xref
    strcmp(...); // call imported API via PLT at 0xd6918
    const char* s_74948 = "hevc_qsv"; // string xref
    strcmp(...); // call imported API via PLT at 0xd692c
    const char* s_83e30 = "av1_qsv"; // string xref
    strcmp(...); // call imported API via PLT at 0xd6940
    const char* s_6ce08 = "h264_amf"; // string xref
    strcmp(...); // call imported API via PLT at 0xd6954
    const char* s_6e229 = "hevc_amf"; // string xref
    strcmp(...); // call imported API via PLT at 0xd6968
    const char* s_6f324 = "av1_amf"; // string xref
    strcmp(...); // call imported API via PLT at 0xd697c
    avcodec_parameters_from_context(...); // call imported API via PLT at 0xd69a8
    avcodec_get_name(...); // call imported API via PLT at 0xd69c8
    strlen(...); // call imported API via PLT at 0xd69d0
    const char* s_68001 = "s null
"; // string xref
    const char* s_69005 = "ffectFormatContext(%p)](%ld):> end of receiveFrame"; // string xref
    av_strlcpy(...); // call imported API via PLT at 0xd69ec
    _ZN7MMCodec14getProfileNameE9AVCodecIDi(...); // call imported API via PLT at 0xd6a04
    __strlen_chk(...); // call imported API via PLT at 0xd6a24
    const char* s_68001 = "s null
"; // string xref
    const char* s_69045 = "ec: [%s(%d)]:> [StreamBase(%p)](%ld):> hold MediaHandleContext %p: seek to %lld, mode %d
"; // string xref
    av_strlcpy(...); // call imported API via PLT at 0xd6a40
    __strlen_chk(...); // call imported API via PLT at 0xd6a6c
    const char* s_68001 = "s null
"; // string xref
    const char* s_690d8 = "number:%zu"; // string xref
    av_strlcpy(...); // call imported API via PLT at 0xd6a88
    _ZdlPv(...); // call imported API via PLT at 0xd6a98
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xd6aa4
    _ZN7MMCodec9to_stringIPcEENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEET_(...); // call imported API via PLT at 0xd6aac
    const char* s_672c8 = "opy context parameter error:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xd6ac0
    _ZdlPv(...); // call imported API via PLT at 0xd6ae8
    pthread_self(...); // call imported API via PLT at 0xd6b0c
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8c7d9 = "[%s(%d)]:> [VideoStream(%p)](%ld):> %s"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd6b50
    pthread_self(...); // call imported API via PLT at 0xd6b74
    const char* s_6e165 = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> %s
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd6bb4
    void* g_201010 = (void*)0x201010; // global ref
    sub_D6E08(...); // call internal func at 0xd6bf8
    _ZdlPv(...); // call imported API via PLT at 0xd6c08
    avcodec_close(...); // call imported API via PLT at 0xd6c14
    avcodec_free_context(...); // call imported API via PLT at 0xd6c1c
    av_dict_free(...); // call imported API via PLT at 0xd6c24
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xd6ca4
    _ZdlPv(...); // call imported API via PLT at 0xd6d00
}
