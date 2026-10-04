// Function: MMCodec::AndroidVideoStream::start(AVFormatContext*, MMCodec::EncodeConfigureInfo*)
// RVA: 0xf75dc, Size: 3656 bytes
int64_t _ZN7MMCodec18AndroidVideoStream5startEP15AVFormatContextPNS_19EncodeConfigureInfoE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xf7624
    _ZN7MMCodec14AICodecContext18getSharedGLContextEv(...); // call imported API via PLT at 0xf7628
    avformat_new_stream(...); // call imported API via PLT at 0xf7640
    void* g_201010 = (void*)0x201010; // global ref
    _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev(...); // call imported API via PLT at 0xf76a0
    void* g_201008 = (void*)0x201008; // global ref
    _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED2Ev(...); // call imported API via PLT at 0xf76b4
    _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev(...); // call imported API via PLT at 0xf76bc
    _ZN7MMCodec27exif_transfer_displaymatrixEiPi(...); // call imported API via PLT at 0xf76c8
    void* g_201001 = (void*)0x201001; // global ref
    memcmp(...); // call imported API via PLT at 0xf7748
    void* g_201050 = (void*)0x201050; // global ref
    av_dict_set(...); // call imported API via PLT at 0xf7780
    pthread_self(...); // call imported API via PLT at 0xf77ac
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xf77d8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_75f64 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> av_dict_set metadata error!(%s:%s)[%s]"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf781c
    pthread_self(...); // call imported API via PLT at 0xf7838
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xf7864
    const char* s_90ce4 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> av_dict_set metadata error!(%s:%s)[%s]
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf78a4
    av_stream_new_side_data(...); // call imported API via PLT at 0xf78b8
    sub_D86D4(...); // call internal func at 0xf78cc
    _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERi(...); // call imported API via PLT at 0xf78d8
    _ZdlPv(...); // call imported API via PLT at 0xf7900
    pthread_self(...); // call imported API via PLT at 0xf7928
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_88509 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> in parameter is invalid"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf7954
    pthread_self(...); // call imported API via PLT at 0xf7978
    const char* s_713b8 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> in parameter is invalid
"; // string xref
    const char* s_67200 = "start"; // string xref
    pthread_self(...); // call imported API via PLT at 0xf79c0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8aff0 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> gl context not init"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf79ec
    pthread_self(...); // call imported API via PLT at 0xf7a10
    const char* s_86fcf = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> gl context not init
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf7a38
    return a0;
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xf7ae4
    (*x8)(...); // indirect call at 0xf7b48
    (*x8)(...); // indirect call at 0xf7b64
    pthread_self(...); // call imported API via PLT at 0xf7b8c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_74b91 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> AndroidMediaEncoder getAlignmentSize failed"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf7bb8
    pthread_self(...); // call imported API via PLT at 0xf7bd4
    const char* s_8b0a4 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> AndroidMediaEncoder getAlignmentSize failed
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf7bfc
    _ZNK7MMCodec14AndroidEncoder14getEncoderTypeEv(...); // call imported API via PLT at 0xf7c14
    (*x8)(...); // indirect call at 0xf7c2c
    (*x8)(...); // indirect call at 0xf7c40
    _ZN7MMCodec14AICodecContext18getSharedGLContextEv(...); // call imported API via PLT at 0xf7c44
    (*x8)(...); // indirect call at 0xf7c58
    pthread_self(...); // call imported API via PLT at 0xf7c84
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d133 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> Create video stream %d "; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf7cb8
    pthread_self(...); // call imported API via PLT at 0xf7cdc
    const char* s_7a3fa = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> Create video stream %d 
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf7d0c
    pthread_self(...); // call imported API via PLT at 0xf7d40
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_675ab = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> New stream error!"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf7d6c
    pthread_self(...); // call imported API via PLT at 0xf7d88
    const char* s_840f9 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> New stream error!
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf7db0
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0xf7dd0
    const char* s_7c922 = "AndroidMediaEncoder configure failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xf7de4
    _ZdlPv(...); // call imported API via PLT at 0xf7e0c
    pthread_self(...); // call imported API via PLT at 0xf7e30
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_859de = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> %s"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf7e74
    pthread_self(...); // call imported API via PLT at 0xf7e90
    const char* s_8e5b1 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> %s
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf7ed0
    (*x9)(...); // indirect call at 0xf7f4c
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0xf7f70
    const char* s_8b10d = "AndroidMediaEncoder codecOpen failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xf7f84
    _ZdlPv(...); // call imported API via PLT at 0xf7fac
    pthread_self(...); // call imported API via PLT at 0xf7fd0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_859de = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> %s"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf8014
    pthread_self(...); // call imported API via PLT at 0xf8030
    const char* s_8e5b1 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> %s
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf8070
    void* g_201010 = (void*)0x201010; // global ref
    sub_D6E08(...); // call internal func at 0xf80b4
    _ZdlPv(...); // call imported API via PLT at 0xf80c4
    pthread_self(...); // call imported API via PLT at 0xf80f0
    avcodec_get_name(...); // call imported API via PLT at 0xf8108
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7b658 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> AndroidMediaEncoder configure codec %s failed, try h264"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf813c
    const char* s_8854c = "hevc"; // string xref
    pthread_self(...); // call imported API via PLT at 0xf8178
    avcodec_get_name(...); // call imported API via PLT at 0xf8190
    const char* s_8b02f = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> AndroidMediaEncoder configure codec %s failed, try h264
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf81c0
    const char* s_8854c = "hevc"; // string xref
    _ZdlPv(...); // call imported API via PLT at 0xf81ec
    _ZdlPv(...); // call imported API via PLT at 0xf8208
    _ZNSt6__ndk119basic_istringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev(...); // call imported API via PLT at 0xf8218
    __stack_chk_fail(...); // call imported API via PLT at 0xf8238
    (*x8)(...); // indirect call at 0xf828c
    _ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xf82b4
    (*x8)(...); // indirect call at 0xf8318
    pthread_self(...); // call imported API via PLT at 0xf834c
    avcodec_get_name(...); // call imported API via PLT at 0xf8364
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7b658 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> AndroidMediaEncoder configure codec %s failed, try h264"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf8398
    pthread_self(...); // call imported API via PLT at 0xf83cc
    avcodec_get_name(...); // call imported API via PLT at 0xf83e4
    const char* s_8b02f = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> AndroidMediaEncoder configure codec %s failed, try h264
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf8414
}
