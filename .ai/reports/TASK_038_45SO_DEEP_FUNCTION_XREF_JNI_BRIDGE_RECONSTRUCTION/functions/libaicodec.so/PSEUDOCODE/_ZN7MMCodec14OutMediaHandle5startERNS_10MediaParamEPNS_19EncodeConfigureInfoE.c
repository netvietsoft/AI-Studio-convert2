// Function: MMCodec::OutMediaHandle::start(MMCodec::MediaParam&, MMCodec::EncodeConfigureInfo*)
// RVA: 0xe87cc, Size: 8192 bytes
int64_t _ZN7MMCodec14OutMediaHandle5startERNS_10MediaParamEPNS_19EncodeConfigureInfoE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_dict_set(...); // call imported API via PLT at 0xe8888
    pthread_self(...); // call imported API via PLT at 0xe88b8
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xe88e4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8caf2 = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> Set AVFormatContext metadata error !(%s:%s)[%s]"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe8918
    pthread_self(...); // call imported API via PLT at 0xe893c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xe8968
    const char* s_7b3b0 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> Set AVFormatContext metadata error !(%s:%s)[%s]
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe899c
    _ZN7MMCodec10MediaParam14getAudioTSPathEv(...); // call imported API via PLT at 0xe89ac
    _ZN7MMCodec10MediaParam14getVideoTSPathEv(...); // call imported API via PLT at 0xe89b8
    av_mallocz(...); // call imported API via PLT at 0xe89cc
    _ZN7MMCodec10MediaParam20getTSSegmentDurationEv(...); // call imported API via PLT at 0xe89d8
    _ZN7MMCodec10MediaParam8hasVideoEv(...); // call imported API via PLT at 0xe89f8
    _ZN7MMCodec10MediaParam8hasAudioEv(...); // call imported API via PLT at 0xe8a04
    _ZN7MMCodec19ExportStreamFactory9newStreamEPNS_14OutMediaHandleENS_11MediaType_tENS_12StreamType_tE(...); // call imported API via PLT at 0xe8a18
    (*x8)(...); // indirect call at 0xe8a2c
    pthread_self(...); // call imported API via PLT at 0xe8a48
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_85893 = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> audio export stream address %p "; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe8a7c
    pthread_self(...); // call imported API via PLT at 0xe8aa0
    const char* s_8ae12 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> audio export stream address %p 
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe8ad0
    (*x8)(...); // indirect call at 0xe8af4
    (*x8)(...); // indirect call at 0xe8b10
    void* g_2010ed = (void*)0x2010ed; // global ref
    const char* s_8a018 = "d)]:> find m_jReleaseOutputBufferID failed"; // string xref
    (*x8)(...); // indirect call at 0xe8b5c
    void* g_201030 = (void*)0x201030; // global ref
    (*x8)(...); // indirect call at 0xe8b7c
    (*x8)(...); // indirect call at 0xe8b94
    pthread_self(...); // call imported API via PLT at 0xe8bd8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6f434 = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> _avFormatCtx is null"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe8c08
    pthread_self(...); // call imported API via PLT at 0xe8c30
    const char* s_6e2e4 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> _avFormatCtx is null
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe8c58
    pthread_self(...); // call imported API via PLT at 0xe8c84
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8580d = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> disable TS generating."; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe8cb4
    pthread_self(...); // call imported API via PLT at 0xe8cd8
    const char* s_8837b = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> disable TS generating.
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe8d04
    _ZN7MMCodec10MediaParam8hasVideoEv(...); // call imported API via PLT at 0xe8d10
    _ZN7MMCodec19ExportStreamFactory9newStreamEPNS_14OutMediaHandleENS_11MediaType_tENS_12StreamType_tE(...); // call imported API via PLT at 0xe8d30
    pthread_self(...); // call imported API via PLT at 0xe8d68
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7a12e = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> new video export stream error"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe8d98
    pthread_self(...); // call imported API via PLT at 0xe8dc4
    const char* s_7c779 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> new video export stream error
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe8dec
    _ZN7MMCodec19ExportStreamFactory9newStreamEPNS_14OutMediaHandleENS_11MediaType_tENS_12StreamType_tE(...); // call imported API via PLT at 0xe8e04
    (*x8)(...); // indirect call at 0xe8e18
    pthread_self(...); // call imported API via PLT at 0xe8e40
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8584b = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> video export stream address: %p "; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe8e74
    pthread_self(...); // call imported API via PLT at 0xe8e98
    const char* s_81a66 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> video export stream address: %p 
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe8ec8
    (*x8)(...); // indirect call at 0xe8eec
    void* g_2010ed = (void*)0x2010ed; // global ref
    const char* s_81018 = "ld):> resamper is null"; // string xref
    (*x8)(...); // indirect call at 0xe8f38
    void* g_201030 = (void*)0x201030; // global ref
    (*x8)(...); // indirect call at 0xe8f58
    (*x8)(...); // indirect call at 0xe8f70
    (*x8)(...); // indirect call at 0xe8f8c
    (*x8)(...); // indirect call at 0xe8f9c
    (*x8)(...); // indirect call at 0xe8fc4
    _ZN7MMCodec10MediaParam14setVideoOutFmtENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xe8fd0
    _ZN7MMCodec10MediaParam13setVideoInFmtENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0xe8fdc
    _Znwm(...); // call imported API via PLT at 0xe9000
    const char* s_8e42a = "Set video parameter error!"; // string xref
    pthread_self(...); // call imported API via PLT at 0xe904c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7261b = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe907c
    pthread_self(...); // call imported API via PLT at 0xe90a0
    const char* s_86de7 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe90cc
    (*x8)(...); // indirect call at 0xe913c
    (*x8)(...); // indirect call at 0xe914c
    _ZdlPv(...); // call imported API via PLT at 0xe915c
    pthread_self(...); // call imported API via PLT at 0xe9180
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86e23 = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> Set audio parameter error! "; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe91b0
    pthread_self(...); // call imported API via PLT at 0xe91dc
    const char* s_69831 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> Set audio parameter error! 
"; // string xref
    const char* s_67200 = "start"; // string xref
    pthread_self(...); // call imported API via PLT at 0xe9224
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7d9d5 = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> Set file handle error!"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe9254
    pthread_self(...); // call imported API via PLT at 0xe9280
    const char* s_7a173 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> Set file handle error!
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe92a8
    (*x8)(...); // indirect call at 0xe92b8
    pthread_self(...); // call imported API via PLT at 0xe92dc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_71262 = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> Set audio codec error!"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe930c
    pthread_self(...); // call imported API via PLT at 0xe9338
    const char* s_7b419 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> Set audio codec error!
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe9360
    (*x8)(...); // indirect call at 0xe9370
    _Znwm(...); // call imported API via PLT at 0xe93c4
    pthread_self(...); // call imported API via PLT at 0xe9424
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7d9d5 = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> Set file handle error!"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe9454
    pthread_self(...); // call imported API via PLT at 0xe947c
    const char* s_7a173 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> Set file handle error!
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe94a4
    (*x8)(...); // indirect call at 0xe94b4
    _Znwm(...); // call imported API via PLT at 0xe9504
    void* g_66001 = (void*)0x66001; // global ref
    _ZdlPv(...); // call imported API via PLT at 0xe95c8
    _ZN7MMCodec10MediaParam8hasAudioEv(...); // call imported API via PLT at 0xe95d8
    _ZN7MMCodec14OutMediaHandle12_writeHeaderEv(...); // call imported API via PLT at 0xe95ec
    _ZN7MMCodec13ThreadContext5startEv(...); // call imported API via PLT at 0xe9638
    void* g_660f3 = (void*)0x660f3; // global ref
    (*x8)(...); // indirect call at 0xe9698
    _ZN7MMCodec18getFFmpegMediaTypeENS_11MediaType_tE(...); // call imported API via PLT at 0xe969c
    void* g_2010f5 = (void*)0x2010f5; // global ref
    void* g_2010f3 = (void*)0x2010f3; // global ref
    void* g_660f3 = (void*)0x660f3; // global ref
    void* g_660f5 = (void*)0x660f5; // global ref
    (*x8)(...); // indirect call at 0xe974c
    (*x8)(...); // indirect call at 0xe977c
    void* g_2010f3 = (void*)0x2010f3; // global ref
    strlen(...); // call imported API via PLT at 0xe97a4
    void* g_2010f5 = (void*)0x2010f5; // global ref
    (*x8)(...); // indirect call at 0xe97c8
    (*x8)(...); // indirect call at 0xe97dc
    _ZnwmRKSt9nothrow_t(...); // call imported API via PLT at 0xe97f4
    _ZN7MMCodec13ThreadContextC1Ev(...); // call imported API via PLT at 0xe9800
    _ZN7MMCodec18AndroidVideoStream14getEncoderTypeEv(...); // call imported API via PLT at 0xe980c
    const char* s_8f827 = "AndroidVideoEncodePixelThread"; // string xref
    _ZN7MMCodec13ThreadContext11setFunctionEPFPvS1_ES1_PKc(...); // call imported API via PLT at 0xe982c
    _ZnwmRKSt9nothrow_t(...); // call imported API via PLT at 0xe984c
    _ZN7MMCodec13ThreadContextC1Ev(...); // call imported API via PLT at 0xe9858
    const char* s_7da69 = "EncodeThread"; // string xref
    (*x8)(...); // indirect call at 0xe9894
    const char* s_67430 = "Audio"; // string xref
    _ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_(...); // call imported API via PLT at 0xe98b0
    (*x8)(...); // indirect call at 0xe98c4
    const char* s_86e66 = "Video"; // string xref
    _ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_(...); // call imported API via PLT at 0xe98e0
    _ZdlPv(...); // call imported API via PLT at 0xe98f0
    _ZN7MMCodec13ThreadContext11setFunctionEPFPvS1_ES1_PKc(...); // call imported API via PLT at 0xe9924
    pthread_self(...); // call imported API via PLT at 0xe9948
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89eac = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> Encode thread start:[%p]! stream:[%p] "; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe997c
    pthread_self(...); // call imported API via PLT at 0xe99a0
    const char* s_78d37 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> Encode thread start:[%p]! stream:[%p] 
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe99d0
    _ZN7MMCodec13ThreadContext5startEv(...); // call imported API via PLT at 0xe99d8
    pthread_self(...); // call imported API via PLT at 0xe9a0c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82e7d = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> thread setFunction failed"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe9a38
    pthread_self(...); // call imported API via PLT at 0xe9a5c
    const char* s_7da76 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> thread setFunction failed
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe9a84
    const char* s_7a22b = "AndroidVideoEncodeThread"; // string xref
    _ZN7MMCodec13ThreadContext11setFunctionEPFPvS1_ES1_PKc(...); // call imported API via PLT at 0xe9aa4
    pthread_self(...); // call imported API via PLT at 0xe9ac8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89eac = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> Encode thread start:[%p]! stream:[%p] "; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe9afc
    pthread_self(...); // call imported API via PLT at 0xe9b38
    const char* s_78d37 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> Encode thread start:[%p]! stream:[%p] 
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe9b68
    const char* s_90b58 = "thread start failed"; // string xref
    pthread_self(...); // call imported API via PLT at 0xe9bbc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7261b = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe9bec
    pthread_self(...); // call imported API via PLT at 0xe9c14
    const char* s_86de7 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe9c4c
    (*x8)(...); // indirect call at 0xe9cb4
    _ZdlPv(...); // call imported API via PLT at 0xe9cc4
    _ZdlPv(...); // call imported API via PLT at 0xe9cdc
    pthread_self(...); // call imported API via PLT at 0xe9d08
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7da13 = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> [%p] [file %s] export stream number is invalid"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe9d40
    pthread_self(...); // call imported API via PLT at 0xe9d64
    const char* s_6f470 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> [%p] [file %s] export stream number is invalid
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe9d98
    _ZN7MMCodec13ThreadContextD1Ev(...); // call imported API via PLT at 0xe9db4
    _ZdlPv(...); // call imported API via PLT at 0xe9dbc
    _ZN7MMCodec13ThreadContextD1Ev(...); // call imported API via PLT at 0xe9dcc
    _ZdlPv(...); // call imported API via PLT at 0xe9dd4
    pthread_self(...); // call imported API via PLT at 0xe9e0c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7ebe7 = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> one of export stream is nullptr in stream list"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe9e38
    pthread_self(...); // call imported API via PLT at 0xe9e5c
    const char* s_7a1c3 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> one of export stream is nullptr in stream list
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe9e84
    _Znwm(...); // call imported API via PLT at 0xe9eb8
    _ZN7MMCodec8HLSMuxerC1Ev(...); // call imported API via PLT at 0xe9ec0
    void* g_2010b0 = (void*)0x2010b0; // global ref
    sub_EAF28(...); // call internal func at 0xe9edc
    _ZN7MMCodec8HLSMuxer29setTSSaveSegmentReadyListenerENSt6__ndk18functionIFvPKcEEE(...); // call imported API via PLT at 0xe9ee8
    const char* s_860f4 = "                     
uniform sampler2D uTexture1;                             
uniform mat3 uColorConversionMatrix;            "; // string xref
    const char* s_860f5 = "                    
uniform sampler2D uTexture1;                             
uniform mat3 uColorConversionMatrix;             "; // string xref
    (*x8)(...); // indirect call at 0xe9f60
    void* g_2010e0 = (void*)0x2010e0; // global ref
    sub_EAF98(...); // call internal func at 0xe9f80
    _ZN7MMCodec8HLSMuxer32setTSSaveSegmentCompleteListenerENSt6__ndk18functionIFvvEEE(...); // call imported API via PLT at 0xe9f8c
    (*x8)(...); // indirect call at 0xe9fbc
    _ZN7MMCodec8HLSMuxer5setupEPNS_8HLSParamE(...); // call imported API via PLT at 0xe9fcc
    _ZnwmRKSt9nothrow_t(...); // call imported API via PLT at 0xe9fe4
    _ZN7MMCodec13ThreadContextC1Ev(...); // call imported API via PLT at 0xe9ff0
    const char* s_89efa = "MuxThread"; // string xref
    _ZN7MMCodec13ThreadContext11setFunctionEPFPvS1_ES1_PKc(...); // call imported API via PLT at 0xea014
    _ZN7MMCodec13ThreadContext5startEv(...); // call imported API via PLT at 0xea020
    const char* s_68547 = "mux thread start failed"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0xea040
    pthread_self(...); // call imported API via PLT at 0xea064
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7261b = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xea0a4
    pthread_self(...); // call imported API via PLT at 0xea0c8
    const char* s_86de7 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xea108
    sub_D6E08(...); // call internal func at 0xea14c
    pthread_self(...); // call imported API via PLT at 0xea180
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_75e18 = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> fail to setup tsMuxer"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xea1ac
    pthread_self(...); // call imported API via PLT at 0xea1d0
    const char* s_6cf18 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> fail to setup tsMuxer
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xea1f8
    const char* s_6a902 = "mux ThreadContext new failed"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0xea21c
    pthread_self(...); // call imported API via PLT at 0xea240
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7261b = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xea280
    pthread_self(...); // call imported API via PLT at 0xea2a4
    const char* s_86de7 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xea2e4
    sub_D6E08(...); // call internal func at 0xea324
    _ZdlPv(...); // call imported API via PLT at 0xea334
    pthread_self(...); // call imported API via PLT at 0xea364
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ae6b = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> create mux thread error!"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xea390
    pthread_self(...); // call imported API via PLT at 0xea3b4
    const char* s_698d8 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> create mux thread error!
"; // string xref
    const char* s_67200 = "start"; // string xref
    void* g_66001 = (void*)0x66001; // global ref
    _ZdlPv(...); // call imported API via PLT at 0xea478
    _ZN7MMCodec14OutMediaHandle12_writeHeaderEv(...); // call imported API via PLT at 0xea498
    pthread_self(...); // call imported API via PLT at 0xea4bc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82e3d = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> write file header error!"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xea4ec
    pthread_self(...); // call imported API via PLT at 0xea53c
    const char* s_69886 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> write file header error!
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xea568
    void* g_201008 = (void*)0x201008; // global ref
    (*x8)(...); // indirect call at 0xea59c
    return a0;
    _Znwm(...); // call imported API via PLT at 0xea5e8
    const char* s_7b469 = "create encode thread context error"; // string xref
    pthread_self(...); // call imported API via PLT at 0xea634
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7261b = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xea668
    _Znwm(...); // call imported API via PLT at 0xea688
    const char* s_72658 = "create android encode thread context error"; // string xref
    pthread_self(...); // call imported API via PLT at 0xea6d4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7261b = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xea708
    pthread_self(...); // call imported API via PLT at 0xea728
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82e7d = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> thread setFunction failed"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xea754
    pthread_self(...); // call imported API via PLT at 0xea778
    const char* s_7da76 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> thread setFunction failed
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xea7a0
    _Znwm(...); // call imported API via PLT at 0xea7b0
    const char* s_81ac0 = "android thread start failed"; // string xref
}
