// Function: MMCodec::AndroidMediaStream::streamOpen()
// RVA: 0x102cc0, Size: 2336 bytes
int64_t _ZN7MMCodec18AndroidMediaStream10streamOpenEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x102d48
    _ZN7MMCodec13ThreadContext5abortEv(...); // call imported API via PLT at 0x102d54
    _ZN7MMCodec13ThreadContextD1Ev(...); // call imported API via PLT at 0x102d64
    _ZdlPv(...); // call imported API via PLT at 0x102d6c
    _Znwm(...); // call imported API via PLT at 0x102d74
    _ZN7MMCodec13ThreadContextC1Ev(...); // call imported API via PLT at 0x102d7c
    _Znwm(...); // call imported API via PLT at 0x102d90
    _ZN7MMCodec13ThreadContextC1Ev(...); // call imported API via PLT at 0x102d98
    _Znwm(...); // call imported API via PLT at 0x102da4
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x102db4
    _ZN7MMCodec10FrameQueueC1EPNS_14AICodecContextE(...); // call imported API via PLT at 0x102dc0
    const char* s_85c03 = "avcodec"; // string xref
    const char* s_7b80f = "MediaCodec"; // string xref
    _ZN7MMCodec17setVideoCodecInfoEPNS_18MediaHandleContextEPKcS3_(...); // call imported API via PLT at 0x102de8
    _ZN7MMCodec18MediaHandleContext16getTotalDurationEib(...); // call imported API via PLT at 0x102df8
    (*x8)(...); // indirect call at 0x102ea0
    (*x8)(...); // indirect call at 0x102f90
    _ZN7MMCodec10FrameQueue4initEPNS_11PacketQueueEi(...); // call imported API via PLT at 0x102fb4
    sub_1035E0(...); // call internal func at 0x102fc8
    _ZN7MMCodec13ThreadContext11setFunctionEPFPvS1_ES1_PKc(...); // call imported API via PLT at 0x102fe0
    _Znwm(...); // call imported API via PLT at 0x103020
    _ZN7MMCodec16ThreadITCContextC1Ei(...); // call imported API via PLT at 0x10302c
    pthread_self(...); // call imported API via PLT at 0x10306c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_761a7 = "[%s(%d)]:> [AndroidMediaStream(%p)](%ld):> Init decode frame queue error!"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x103098
    pthread_self(...); // call imported API via PLT at 0x1030c4
    const char* s_87121 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidMediaStream(%p)](%ld):> Init decode frame queue error!
"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    pthread_self(...); // call imported API via PLT at 0x103110
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82ff3 = "[%s(%d)]:> [AndroidMediaStream(%p)](%ld):> Set decode thread error!"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10313c
    pthread_self(...); // call imported API via PLT at 0x103168
    const char* s_7ca2f = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidMediaStream(%p)](%ld):> Set decode thread error!
"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    _Znwm(...); // call imported API via PLT at 0x103194
    _ZN7MMCodec11MediaFilterC1EPNS_18MediaHandleContextEPNS_10StreamBaseEP14AVCodecContext(...); // call imported API via PLT at 0x1031a8
    _Znwm(...); // call imported API via PLT at 0x1031c4
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x1031d4
    void* g_1fe978 = (void*)0x1fe978; // global ref
    void* g_1fea08 = (void*)0x1fea08; // global ref
    _ZN7MMCodec13FrameHoldPoolC1EPNS_14AICodecContextENSt6__ndk18functionIFiRNS_12MMCodecFrameES6_EEENS4_IFiS6_EEE(...); // call imported API via PLT at 0x103210
    (*x8)(...); // indirect call at 0x103240
    (*x8)(...); // indirect call at 0x103270
    _Znwm(...); // call imported API via PLT at 0x10332c
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x103338
    void* g_1fea98 = (void*)0x1fea98; // global ref
    void* g_1feb18 = (void*)0x1feb18; // global ref
    _ZN7MMCodec14FrameCachePoolC1EPNS_14AICodecContextEddiNSt6__ndk18functionIFiRNS_12MMCodecFrameES6_EEENS4_IFiS6_EEEl(...); // call imported API via PLT at 0x10338c
    (*x8)(...); // indirect call at 0x1033bc
    (*x8)(...); // indirect call at 0x1033ec
    (*x8)(...); // indirect call at 0x103400
    _ZN7MMCodec13ThreadContext5startEv(...); // call imported API via PLT at 0x103408
    pthread_self(...); // call imported API via PLT at 0x103434
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7160e = "[%s(%d)]:> [AndroidMediaStream(%p)](%ld):> thread start failed"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x103460
    pthread_self(...); // call imported API via PLT at 0x10348c
    const char* s_7a4f3 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidMediaStream(%p)](%ld):> thread start failed
"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1034b4
    return a0;
    (*x9)(...); // indirect call at 0x103518
    (*x9)(...); // indirect call at 0x10356c
    (*x8)(...); // indirect call at 0x10359c
    _ZdlPv(...); // call imported API via PLT at 0x1035c0
    __stack_chk_fail(...); // call imported API via PLT at 0x1035dc
}
