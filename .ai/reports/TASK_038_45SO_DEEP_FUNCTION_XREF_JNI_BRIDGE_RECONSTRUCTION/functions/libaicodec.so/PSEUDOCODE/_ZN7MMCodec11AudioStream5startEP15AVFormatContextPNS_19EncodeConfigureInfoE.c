// Function: MMCodec::AudioStream::start(AVFormatContext*, MMCodec::EncodeConfigureInfo*)
// RVA: 0xcefd4, Size: 2808 bytes
int64_t _ZN7MMCodec11AudioStream5startEP15AVFormatContextPNS_19EncodeConfigureInfoE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    avformat_new_stream(...); // call imported API via PLT at 0xcf010
    av_dict_set(...); // call imported API via PLT at 0xcf074
    pthread_self(...); // call imported API via PLT at 0xcf098
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xcf0cc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7d764 = "[%s(%d)]:> [AudioStream(%p)](%ld):> av_dict_set metadata error!(%s:%s)[%s]"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcf108
    pthread_self(...); // call imported API via PLT at 0xcf124
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xcf150
    const char* s_90a0e = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> av_dict_set metadata error!(%s:%s)[%s]
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xcf180
    pthread_self(...); // call imported API via PLT at 0xcf1a8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6f1f4 = "[%s(%d)]:> [AudioStream(%p)](%ld):> input parameter is invalid"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcf1d4
    pthread_self(...); // call imported API via PLT at 0xcf1f8
    const char* s_6831c = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> input parameter is invalid
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xcf220
    const char* s_7e9c8 = "libfdk_aac"; // string xref
    avcodec_find_encoder_by_name(...); // call imported API via PLT at 0xcf234
    avformat_new_stream(...); // call imported API via PLT at 0xcf24c
    pthread_self(...); // call imported API via PLT at 0xcf278
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7b1f2 = "[%s(%d)]:> [AudioStream(%p)](%ld):> new audio stream error!"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcf2a4
    pthread_self(...); // call imported API via PLT at 0xcf2c8
    const char* s_75b73 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> new audio stream error!
"; // string xref
    const char* s_67200 = "start"; // string xref
    pthread_self(...); // call imported API via PLT at 0xcf324
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7e9d3 = "[%s(%d)]:> [AudioStream(%p)](%ld):> create audio stream index %d"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcf354
    avcodec_alloc_context3(...); // call imported API via PLT at 0xcf370
    av_channel_layout_uninit(...); // call imported API via PLT at 0xcf3ac
    void* g_201160 = (void*)0x201160; // global ref
    av_channel_layout_default(...); // call imported API via PLT at 0xcf3bc
    _ZN7MMCodec19getAudioOuterFormatE14AVSampleFormat(...); // call imported API via PLT at 0xcf3c8
    avcodec_open2(...); // call imported API via PLT at 0xcf404
    avcodec_parameters_from_context(...); // call imported API via PLT at 0xcf418
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xcf430
    _ZN7MMCodec8initFifoEPP11AVAudioFifo14AVSampleFormatii(...); // call imported API via PLT at 0xcf444
    _Znwm(...); // call imported API via PLT at 0xcf484
    _ZN7MMCodec14FFmpegResampleC1Ev(...); // call imported API via PLT at 0xcf48c
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xcf498
    _ZN7MMCodec14FFmpegResample20setTargetAudioParamsE14AVSampleFormatii(...); // call imported API via PLT at 0xcf4ac
    pthread_self(...); // call imported API via PLT at 0xcf4d4
    const char* s_8c6cb = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> create audio stream index %d
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xcf504
    avcodec_alloc_context3(...); // call imported API via PLT at 0xcf50c
    pthread_self(...); // call imported API via PLT at 0xcf530
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7b22e = "[%s(%d)]:> [AudioStream(%p)](%ld):> alloc audio codec context error!"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcf55c
    pthread_self(...); // call imported API via PLT at 0xcf578
    const char* s_7ea14 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> alloc audio codec context error!
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xcf5a0
    pthread_self(...); // call imported API via PLT at 0xcf5d4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6955a = "[%s(%d)]:> [AudioStream(%p)](%ld):> Cannot find encoder libfdk_aac "; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcf600
    pthread_self(...); // call imported API via PLT at 0xcf624
    const char* s_817e7 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> Cannot find encoder libfdk_aac 
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xcf64c
    pthread_self(...); // call imported API via PLT at 0xcf68c
    avcodec_get_name(...); // call imported API via PLT at 0xcf69c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_854f7 = "[%s(%d)]:> [AudioStream(%p)](%ld):> Open codec %s error!"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcf6cc
    pthread_self(...); // call imported API via PLT at 0xcf6e8
    avcodec_get_name(...); // call imported API via PLT at 0xcf6fc
    const char* s_80630 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> Open codec %s error!
"; // string xref
    const char* s_67200 = "start"; // string xref
    pthread_self(...); // call imported API via PLT at 0xcf738
    av_get_sample_fmt_name(...); // call imported API via PLT at 0xcf744
    av_get_sample_fmt_name(...); // call imported API via PLT at 0xcf75c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_70f02 = "[%s(%d)]:> [AudioStream(%p)](%ld):>  %s isn't supported, trying to using %s"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcf794
    pthread_self(...); // call imported API via PLT at 0xcf7b8
    av_get_sample_fmt_name(...); // call imported API via PLT at 0xcf7c8
    av_get_sample_fmt_name(...); // call imported API via PLT at 0xcf7e0
    const char* s_78abc = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):>  %s isn't supported, trying to using %s
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xcf814
    avcodec_open2(...); // call imported API via PLT at 0xcf848
    _ZN7MMCodec19getAudioOuterFormatE14AVSampleFormat(...); // call imported API via PLT at 0xcf858
    avcodec_parameters_from_context(...); // call imported API via PLT at 0xcf874
    pthread_self(...); // call imported API via PLT at 0xcf898
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67206 = "[%s(%d)]:> [AudioStream(%p)](%ld):> Copy context parameter error!"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcf8c4
    pthread_self(...); // call imported API via PLT at 0xcf8e0
    const char* s_79e92 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> Copy context parameter error!
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xcf908
    pthread_self(...); // call imported API via PLT at 0xcf928
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6f233 = "[%s(%d)]:> [AudioStream(%p)](%ld):> Init fifo error!"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcf954
    pthread_self(...); // call imported API via PLT at 0xcf970
    const char* s_77903 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> Init fifo error!
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xcf998
    pthread_self(...); // call imported API via PLT at 0xcf9c0
    avcodec_get_name(...); // call imported API via PLT at 0xcf9d4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_854f7 = "[%s(%d)]:> [AudioStream(%p)](%ld):> Open codec %s error!"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcfa04
    pthread_self(...); // call imported API via PLT at 0xcfa20
    avcodec_get_name(...); // call imported API via PLT at 0xcfa34
    const char* s_80630 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> Open codec %s error!
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xcfa60
    avcodec_close(...); // call imported API via PLT at 0xcfa70
    avcodec_free_context(...); // call imported API via PLT at 0xcfa78
    (*x8)(...); // indirect call at 0xcfa8c
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0xcfac0
}
