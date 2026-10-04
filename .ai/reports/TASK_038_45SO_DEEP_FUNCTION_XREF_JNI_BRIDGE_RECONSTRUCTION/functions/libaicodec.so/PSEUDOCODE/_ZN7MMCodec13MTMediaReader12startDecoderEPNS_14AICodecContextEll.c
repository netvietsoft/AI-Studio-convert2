// Function: MMCodec::MTMediaReader::startDecoder(MMCodec::AICodecContext*, long, long)
// RVA: 0x1316d8, Size: 2744 bytes
int64_t _ZN7MMCodec13MTMediaReader12startDecoderEPNS_14AICodecContextEll(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x131714
    pthread_self(...); // call imported API via PLT at 0x131748
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67c87 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> has started"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x131774
    pthread_self(...); // call imported API via PLT at 0x131798
    const char* s_68bc1 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> has started
"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1317c0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1317cc
    pthread_self(...); // call imported API via PLT at 0x131804
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7cf61 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> didn't open"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x131830
    pthread_self(...); // call imported API via PLT at 0x131854
    const char* s_6a008 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> didn't open
"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13187c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x131888
    return a0;
    _ZN7MMCodec6AVIRef7releaseEv(...); // call imported API via PLT at 0x1318cc
    _ZN7MMCodec6AVIRef6retainEv(...); // call imported API via PLT at 0x1318d8
    pthread_self(...); // call imported API via PLT at 0x13193c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6c21c = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> start with AICodecContext %p . in startPos: %lld (us); limited duration: %lld (us); reques"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x131978
    pthread_self(...); // call imported API via PLT at 0x13199c
    const char* s_7bcb5 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> start with AICodecContext %p . in startPos: %lld (us); limited duration: "; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1319d8
    _ZN7MMCodec17createDemuxConfigEv(...); // call imported API via PLT at 0x131a88
    pthread_self(...); // call imported API via PLT at 0x131b44
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7e0ca = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> create demux config failed"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x131b70
    pthread_self(...); // call imported API via PLT at 0x131b8c
    const char* s_874cc = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> create demux config failed
"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x131bb4
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x131bc0
    void* g_2010f8 = (void*)0x2010f8; // global ref
    (*x8)(...); // indirect call at 0x131c50
    (*x8)(...); // indirect call at 0x131c68
    (*x8)(...); // indirect call at 0x131c80
    (*x8)(...); // indirect call at 0x131c98
    (*x8)(...); // indirect call at 0x131cb4
    (*x8)(...); // indirect call at 0x131ccc
    (*x8)(...); // indirect call at 0x131d8c
    pthread_self(...); // call imported API via PLT at 0x131dc0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6b016 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> AICodecContext didn't be set"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x131dec
    pthread_self(...); // call imported API via PLT at 0x131e10
    const char* s_7e075 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> AICodecContext didn't be set
"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x131e38
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x131e44
    _ZN7MMCodec13AICodecGlobal11getInstanceEv(...); // call imported API via PLT at 0x131e6c
    _ZN7MMCodec13AICodecGlobal13isBlacklistedEv(...); // call imported API via PLT at 0x131e70
    _ZN7MMCodec13InMediaHandle13setAttributesERKNSt6__ndk13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES8_NS1_4lessIS8_EENS6_INS1_4pairIKS8_S8_EEEEEE(...); // call imported API via PLT at 0x131e80
    (*x8)(...); // indirect call at 0x131e98
    pthread_self(...); // call imported API via PLT at 0x131ed4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8b8b6 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> MediaHandleBase prepare failed! trying using software decoder"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x131f00
    pthread_self(...); // call imported API via PLT at 0x131f1c
    const char* s_7a913 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> MediaHandleBase prepare failed! trying using software decoder
"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x131f44
    (*x8)(...); // indirect call at 0x131f64
    sub_12F5DC(...); // call internal func at 0x131f88
    void* g_201018 = (void*)0x201018; // global ref
    _ZN7MMCodec15freeDemuxConfigEPPNS_13DemuxConfig_tE(...); // call imported API via PLT at 0x131f98
    (*x8)(...); // indirect call at 0x131fd0
    pthread_self(...); // call imported API via PLT at 0x131fec
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_88c85 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> MediaHandle prepare failed!"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x132018
    pthread_self(...); // call imported API via PLT at 0x132034
    const char* s_913ef = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> MediaHandle prepare failed!
"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13205c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x132068
    pthread_self(...); // call imported API via PLT at 0x1320b0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ed8b = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> started"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1320dc
    pthread_self(...); // call imported API via PLT at 0x1320f8
    const char* s_7ceea = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> started
"; // string xref
    const char* s_8d40e = "startDecoder"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x132120
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x13212c
    __stack_chk_fail(...); // call imported API via PLT at 0x132140
    _ZNK7MMCodec13MTMediaReader10isHDRMediaEv(...); // call imported API via PLT at 0x132148
    _ZN7MMCodec13AICodecGlobal11getInstanceEv(...); // call imported API via PLT at 0x132150
    _ZN7MMCodec13AICodecGlobal16isHDRBlacklistedEv(...); // call imported API via PLT at 0x132154
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x132174
}
