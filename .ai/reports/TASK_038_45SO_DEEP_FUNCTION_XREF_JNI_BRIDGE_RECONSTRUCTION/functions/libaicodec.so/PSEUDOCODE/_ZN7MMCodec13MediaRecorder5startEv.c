// Function: MMCodec::MediaRecorder::start()
// RVA: 0xe3f40, Size: 2140 bytes
int64_t _ZN7MMCodec13MediaRecorder5startEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_(...); // call imported API via PLT at 0xe3fa4
    const char* s_7eb90 = "gif";
    av_match_ext(...); // call imported API via PLT at 0xe3fc4
    _ZN7MMCodec10MediaParam20setEnableVideoOutputEb(...); // call imported API via PLT at 0xe4000
    _ZN7MMCodec10MediaParam20setEnableAudioOutputEb(...); // call imported API via PLT at 0xe4014
    void* g_201010 = (void*)0x201010; // global ref
    _ZN7MMCodec14OutMediaHandle5closeEPNS_21EncodePerformanceInfoE(...); // call imported API via PLT at 0xe406c
    _ZN7MMCodec14OutMediaHandleD1Ev(...); // call imported API via PLT at 0xe407c
    _ZdlPv(...); // call imported API via PLT at 0xe4084
    _Znwm(...); // call imported API via PLT at 0xe408c
    _ZN7MMCodec14OutMediaHandleC1EPNS_14AICodecContextE(...); // call imported API via PLT at 0xe4098
    _ZN7MMCodec14OutMediaHandle11setHardModeEb(...); // call imported API via PLT at 0xe40a8
    _ZN7MMCodec14OutMediaHandle20enableAsyncSendVideoEb(...); // call imported API via PLT at 0xe40b4
    _ZN7MMCodec14OutMediaHandle15enableFastStartEb(...); // call imported API via PLT at 0xe40c0
    _ZN7MMCodec14OutMediaHandle29setTSSaveSegmentReadyListenerENSt6__ndk18functionIFvPKcEEE(...); // call imported API via PLT at 0xe4110
    (*x8)(...); // indirect call at 0xe4140
    (*x8)(...); // indirect call at 0xe4164
    _ZN7MMCodec14OutMediaHandle29setTSSaveSegmentReadyListenerENSt6__ndk18functionIFvPKcEEE(...); // call imported API via PLT at 0xe4170
    (*x8)(...); // indirect call at 0xe41a0
    (*x8)(...); // indirect call at 0xe41c8
    (*x8)(...); // indirect call at 0xe41ec
    _ZN7MMCodec14OutMediaHandle32setTSSaveSegmentCompleteListenerENSt6__ndk18functionIFvvEEE(...); // call imported API via PLT at 0xe41f8
    (*x8)(...); // indirect call at 0xe4228
    (*x8)(...); // indirect call at 0xe4248
    (*x8)(...); // indirect call at 0xe4274
    _ZN7MMCodec14OutMediaHandle11setCallbackEPNS_13MediaRecorderENSt6__ndk18functionIFvS2_NS_14RecorderModuleENS_20RecorderCallbackTypeEddPvEEE(...); // call imported API via PLT at 0xe4284
    (*x8)(...); // indirect call at 0xe42b4
    _ZN7MMCodec14OutMediaHandle4openEPhmPKc(...); // call imported API via PLT at 0xe42dc
    _ZN7MMCodec14OutMediaHandle4openEPKc(...); // call imported API via PLT at 0xe42fc
    _ZN7MMCodec14OutMediaHandle11addMetaDataEPKcS2_NS_12CONTEXT_TYPEE(...); // call imported API via PLT at 0xe4340
    _ZN7MMCodec14OutMediaHandle11addMetaDataEPKcS2_NS_12CONTEXT_TYPEE(...); // call imported API via PLT at 0xe438c
    _ZN7MMCodec14OutMediaHandle11addMetaDataEPKcS2_NS_12CONTEXT_TYPEE(...); // call imported API via PLT at 0xe43d8
    _ZN7MMCodec14OutMediaHandle13setAttributesERKNSt6__ndk13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES8_NS1_4lessIS8_EENS6_INS1_4pairIKS8_S8_EEEEEE(...); // call imported API via PLT at 0xe43f0
    _ZN7MMCodec14OutMediaHandle5startERNS_10MediaParamEPNS_19EncodeConfigureInfoE(...); // call imported API via PLT at 0xe4400
    pthread_self(...); // call imported API via PLT at 0xe4438
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_86d95 = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> hardware encoder start failed, try software"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe4464
    pthread_self(...); // call imported API via PLT at 0xe44b8
    const char* s_8571c = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> hardware encoder start failed, try software
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe44e0
    pthread_self(...); // call imported API via PLT at 0xe451c
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8f772 = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> Media recorder prepare failed !"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe4548
    pthread_self(...); // call imported API via PLT at 0xe4574
    const char* s_7116a = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> Media recorder prepare failed !
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe459c
    pthread_self(...); // call imported API via PLT at 0xe45c0
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8ad76 = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> Open %s file error!"; // string xref
    const char* s_67200 = "start"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe45fc
    pthread_self(...); // call imported API via PLT at 0xe4628
    const char* s_90b0c = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> Open %s file error!
"; // string xref
    const char* s_67200 = "start"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe4660
    _ZN7MMCodec14OutMediaHandle5closeEPNS_21EncodePerformanceInfoE(...); // call imported API via PLT at 0xe467c
    _ZN7MMCodec14OutMediaHandleD1Ev(...); // call imported API via PLT at 0xe468c
    _ZdlPv(...); // call imported API via PLT at 0xe4694
    return a0;
    (*x9)(...); // indirect call at 0xe476c
    _ZdlPv(...); // call imported API via PLT at 0xe477c
    __stack_chk_fail(...); // call imported API via PLT at 0xe4798
}
