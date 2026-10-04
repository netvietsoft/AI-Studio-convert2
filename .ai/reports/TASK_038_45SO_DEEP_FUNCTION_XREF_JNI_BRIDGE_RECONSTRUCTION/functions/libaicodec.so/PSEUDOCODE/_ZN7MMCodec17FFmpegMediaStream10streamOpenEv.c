// Function: MMCodec::FFmpegMediaStream::streamOpen()
// RVA: 0x138f28, Size: 3440 bytes
int64_t _ZN7MMCodec17FFmpegMediaStream10streamOpenEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13ThreadContext5abortEv(...); // call imported API via PLT at 0x138f68
    _ZN7MMCodec13ThreadContextD1Ev(...); // call imported API via PLT at 0x138f78
    _ZdlPv(...); // call imported API via PLT at 0x138f80
    _Znwm(...); // call imported API via PLT at 0x138f98
    _ZN7MMCodec13ThreadContextC1Ev(...); // call imported API via PLT at 0x138fa0
    _Znwm(...); // call imported API via PLT at 0x138fb0
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x138fbc
    _ZN7MMCodec10FrameQueueC1EPNS_14AICodecContextE(...); // call imported API via PLT at 0x138fc8
    avcodec_get_name(...); // call imported API via PLT at 0x138ffc
    const char* s_85c03 = "avcodec"; // string xref
    _ZN7MMCodec18MediaHandleContext12setCodecInfoENS_16CODEC_INFO_INDEXEPKcS3_(...); // call imported API via PLT at 0x139014
    _ZN7MMCodec10FrameQueue4initEPNS_11PacketQueueEi(...); // call imported API via PLT at 0x139030
    const char* s_6fcff = "MTAudioDecodeThread(%p)-%d"; // string xref
    sub_139C98(...); // call internal func at 0x139050
    _ZN7MMCodec13ThreadContext11setFunctionEPFPvS1_ES1_PKc(...); // call imported API via PLT at 0x139074
    av_audio_fifo_alloc(...); // call imported API via PLT at 0x139094
    _Znwm(...); // call imported API via PLT at 0x1390ac
    (*x9)(...); // indirect call at 0x1390c8
    _ZN7MMCodec11MediaFilterC1EPNS_18MediaHandleContextEPNS_10StreamBaseEP14AVCodecContext(...); // call imported API via PLT at 0x1390dc
    _ZN7MMCodec13ThreadContext5startEv(...); // call imported API via PLT at 0x1390fc
    pthread_self(...); // call imported API via PLT at 0x139128
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ba09 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> thread start failed"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x139154
    pthread_self(...); // call imported API via PLT at 0x139178
    const char* s_7cf9d = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> thread start failed
"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    avcodec_get_name(...); // call imported API via PLT at 0x1391b4
    const char* s_85c03 = "avcodec"; // string xref
    _ZN7MMCodec18MediaHandleContext12setCodecInfoENS_16CODEC_INFO_INDEXEPKcS3_(...); // call imported API via PLT at 0x1391cc
    _ZN7MMCodec18MediaHandleContext16getTotalDurationEib(...); // call imported API via PLT at 0x1391dc
    pthread_self(...); // call imported API via PLT at 0x139228
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d838 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Init decode frame queue error!"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x139254
    pthread_self(...); // call imported API via PLT at 0x139278
    const char* s_6b0a7 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Init decode frame queue error!
"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    _ZN7MMCodec18MediaHandleContext9isPictureEi(...); // call imported API via PLT at 0x1393dc
    _ZN7MMCodec10FrameQueue4initEPNS_11PacketQueueEi(...); // call imported API via PLT at 0x1393fc
    const char* s_6bded = "MTVideoDecodeThread(%p)-%d"; // string xref
    sub_139C98(...); // call internal func at 0x13941c
    _ZN7MMCodec13ThreadContext11setFunctionEPFPvS1_ES1_PKc(...); // call imported API via PLT at 0x139440
    _Znwm(...); // call imported API via PLT at 0x139458
    (*x9)(...); // indirect call at 0x139474
    _ZN7MMCodec11MediaFilterC1EPNS_18MediaHandleContextEPNS_10StreamBaseEP14AVCodecContext(...); // call imported API via PLT at 0x139488
    _Znwm(...); // call imported API via PLT at 0x1394d8
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x1394e8
    void* g_1ffc20 = (void*)0x1ffc20; // global ref
    void* g_1ffca0 = (void*)0x1ffca0; // global ref
    _ZN7MMCodec13FrameHoldPoolC1EPNS_14AICodecContextENSt6__ndk18functionIFiRNS_12MMCodecFrameES6_EEENS4_IFiS6_EEE(...); // call imported API via PLT at 0x139524
    pthread_self(...); // call imported API via PLT at 0x139564
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d838 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Init decode frame queue error!"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x139590
    pthread_self(...); // call imported API via PLT at 0x1395b4
    const char* s_6b0a7 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Init decode frame queue error!
"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1395dc
    pthread_self(...); // call imported API via PLT at 0x139604
    av_get_sample_fmt_name(...); // call imported API via PLT at 0x13961c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ba47 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Create audio fifo error!(sample format=%s channels=%d)"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13965c
    pthread_self(...); // call imported API via PLT at 0x139680
    av_get_sample_fmt_name(...); // call imported API via PLT at 0x139698
    const char* s_82573 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Create audio fifo error!(sample format=%s channels=%d)
"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1396d4
    pthread_self(...); // call imported API via PLT at 0x1396fc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7f3f2 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Set decode thread error!"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x139728
    pthread_self(...); // call imported API via PLT at 0x13974c
    const char* s_8251e = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Set decode thread error!
"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x139774
    pthread_self(...); // call imported API via PLT at 0x13979c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7f3f2 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Set decode thread error!"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1397c8
    pthread_self(...); // call imported API via PLT at 0x1397ec
    const char* s_8251e = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Set decode thread error!
"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    (*x8)(...); // indirect call at 0x139824
    (*x8)(...); // indirect call at 0x139854
    av_image_get_buffer_size(...); // call imported API via PLT at 0x1398e4
    _Znwm(...); // call imported API via PLT at 0x139920
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x13992c
    void* g_1ffd20 = (void*)0x1ffd20; // global ref
    void* g_1ffda0 = (void*)0x1ffda0; // global ref
    _ZN7MMCodec14FrameCachePoolC1EPNS_14AICodecContextEddiNSt6__ndk18functionIFiRNS_12MMCodecFrameES6_EEENS4_IFiS6_EEEl(...); // call imported API via PLT at 0x139980
    (*x8)(...); // indirect call at 0x1399b0
    (*x8)(...); // indirect call at 0x1399e0
    (*x8)(...); // indirect call at 0x1399f4
    _ZN7MMCodec13ThreadContext5startEv(...); // call imported API via PLT at 0x139a08
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x139a20
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0x139a24
    pthread_self(...); // call imported API via PLT at 0x139a50
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7cfed = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> acquireAVPacket failed"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x139a7c
    pthread_self(...); // call imported API via PLT at 0x139aa0
    const char* s_7822e = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> acquireAVPacket failed
"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x139ac8
    return a0;
    pthread_self(...); // call imported API via PLT at 0x139b24
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ba09 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> thread start failed"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x139b50
    pthread_self(...); // call imported API via PLT at 0x139b74
    const char* s_7cf9d = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> thread start failed
"; // string xref
    const char* s_8b275 = "streamOpen"; // string xref
    (*x9)(...); // indirect call at 0x139bcc
    (*x9)(...); // indirect call at 0x139c20
    (*x8)(...); // indirect call at 0x139c50
    _ZdlPv(...); // call imported API via PLT at 0x139c78
    __stack_chk_fail(...); // call imported API via PLT at 0x139c94
}
