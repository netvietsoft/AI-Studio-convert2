// Function: MMCodec::mediaDecodeThread(void*)
// RVA: 0x15f624, Size: 6356 bytes
int64_t _ZN7MMCodec17mediaDecodeThreadEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x15f6d4
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0x15f6d8
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x15f6ec
    _ZN7MMCodec14AICodecContext12acquireFrameEv(...); // call imported API via PLT at 0x15f6f0
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x15f700
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x15f714
    av_get_media_type_string(...); // call imported API via PLT at 0x15f728
    pthread_self(...); // call imported API via PLT at 0x15f758
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_76dab = "[%s(%d)]:> (%ld):> [>>>start]index:%d, type:%sMediaHandleContext:%p, stream:%p, frame queue:%p, packet queue:%p"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15f798
    pthread_self(...); // call imported API via PLT at 0x15f7bc
    const char* s_8bf5b = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [>>>start]index:%d, type:%sMediaHandleContext:%p, stream:%p, frame queue:%p, packet queue:%p"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15f7f8
    pthread_self(...); // call imported API via PLT at 0x15f848
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_734b4 = "[%s(%d)]:> (%ld):> input parameter is null"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15f870
    pthread_self(...); // call imported API via PLT at 0x15f894
    const char* s_6ee14 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> input parameter is null
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15f8b8
    pthread_self(...); // call imported API via PLT at 0x15f8e4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90718 = "[%s(%d)]:> (%ld):> decode thread parameter is error!"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15f90c
    pthread_self(...); // call imported API via PLT at 0x15f930
    const char* s_813e7 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> decode thread parameter is error!
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15f954
    pthread_self(...); // call imported API via PLT at 0x15f97c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72160 = "[%s(%d)]:> (%ld):> FormatContext is null"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15f9a4
    pthread_self(...); // call imported API via PLT at 0x15f9c8
    const char* s_6dccd = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> FormatContext is null
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15f9ec
    pthread_self(...); // call imported API via PLT at 0x15fa20
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_81207 = "[%s(%d)]:> (%ld):> allocAVFrame is null"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15fa4c
    const char* s_782d1 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> allocAVFrame is null
"; // string xref
    pthread_self(...); // call imported API via PLT at 0x15fa7c
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15fa9c
    pthread_self(...); // call imported API via PLT at 0x15fac8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_813bc = "[%s(%d)]:> (%ld):> acquireAVPacket is null"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15faf4
    pthread_self(...); // call imported API via PLT at 0x15fb18
    const char* s_734df = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> acquireAVPacket is null
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15fb40
    (*x8)(...); // indirect call at 0x15fb60
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x15fb6c
    _ZN7MMCodec14AICodecContext12releaseFrameEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x15fb74
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x15fb80
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0x15fb88
    _ZN7MMCodec13ThreadContext8markOverEv(...); // call imported API via PLT at 0x15fb94
    pthread_self(...); // call imported API via PLT at 0x15fbb8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8f16d = "[%s(%d)]:> (%ld):> [%d][%s]Media decode thread exit! thread stat %d deal frame %lld"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15fc00
    pthread_self(...); // call imported API via PLT at 0x15fc24
    const char* s_8f1c1 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [%d][%s]Media decode thread exit! thread stat %d deal frame %lld
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15fc68
    _ZdlPv(...); // call imported API via PLT at 0x15fc88
    void* g_201008 = (void*)0x201008; // global ref
    _ZdlPv(...); // call imported API via PLT at 0x15fcd4
    void* g_201007 = (void*)0x201007; // global ref
    void* g_2010e3 = (void*)0x2010e3; // global ref
    _ZdlPv(...); // call imported API via PLT at 0x15fd08
    return a0;
    av_frame_unref(...); // call imported API via PLT at 0x15fd48
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x15fd58
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x15fd6c
    (*x8)(...); // indirect call at 0x15fd8c
    void* g_201001 = (void*)0x201001; // global ref
    av_gettime_relative(...); // call imported API via PLT at 0x15fdb8
    void* g_2010e5 = (void*)0x2010e5; // global ref
    _ZdlPv(...); // call imported API via PLT at 0x15fe64
    void* g_201008 = (void*)0x201008; // global ref
    _ZN7MMCodec10StreamBase9getFilterEv(...); // call imported API via PLT at 0x15fea0
    _ZN7MMCodec11MediaFilter16filterAudioFrameEP7AVFramelliRb(...); // call imported API via PLT at 0x15fed8
    _ZN7MMCodec11MediaFilter16filterVideoFrameEP7AVFramelRKNS_11PacketQueue10PacketInfoERb(...); // call imported API via PLT at 0x15fef8
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15ff08
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15ff1c
    (*x8)(...); // indirect call at 0x15ff30
    _ZN7MMCodec10FrameQueue12peekWritableERPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x15ff40
    _ZN7MMCodec11MediaFilter29filterVideoFrameAfterWritableEPNS_12MMCodecFrameERb(...); // call imported API via PLT at 0x15ff78
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15ff88
    void* g_201020 = (void*)0x201020; // global ref
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15ffa0
    (*x8)(...); // indirect call at 0x15ffb4
    av_frame_unref(...); // call imported API via PLT at 0x15ffc8
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15ffd4
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15ffe8
    (*x8)(...); // indirect call at 0x15fffc
    pthread_self(...); // call imported API via PLT at 0x160028
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90105 = "[%s(%d)]:> (%ld):> get null frame from decode frame queue, drop %lld %s frame"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x160058
    pthread_self(...); // call imported API via PLT at 0x16007c
    const char* s_825e6 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> get null frame from decode frame queue, drop %lld %s frame
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1600a8
    av_gettime_relative(...); // call imported API via PLT at 0x1600d4
    _ZN7MMCodec18MediaHandleContext8callbackEiidPv(...); // call imported API via PLT at 0x16011c
    av_frame_unref(...); // call imported API via PLT at 0x160138
    _ZN7MMCodec12MMCodecFrame7moveRefEPS0_S1_(...); // call imported API via PLT at 0x160144
    (*x8)(...); // indirect call at 0x160158
    _ZN7MMCodec10FrameQueue3putEv(...); // call imported API via PLT at 0x160174
    pthread_self(...); // call imported API via PLT at 0x1601a0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_81207 = "[%s(%d)]:> (%ld):> allocAVFrame is null"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1601c8
    pthread_self(...); // call imported API via PLT at 0x1601ec
    const char* s_782d1 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> allocAVFrame is null
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x160210
    (*x8)(...); // indirect call at 0x160228
    _ZN7MMCodec11PacketQueue9nbPacketsEv(...); // call imported API via PLT at 0x160230
    _ZN7MMCodec11PacketQueue5isEofEv(...); // call imported API via PLT at 0x16023c
    _ZN7MMCodec10FrameQueue10setEofFlagEb(...); // call imported API via PLT at 0x16024c
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x16025c
    pthread_self(...); // call imported API via PLT at 0x160280
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8938e = "[%s(%d)]:> (%ld):> [%s]receive_frame decode eof, sleep wait for seek... pStreamCtx:%p"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1602b0
    pthread_self(...); // call imported API via PLT at 0x1602d4
    const char* s_83ac5 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [%s]receive_frame decode eof, sleep wait for seek... pStreamCtx:%p
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x160300
    (*x8)(...); // indirect call at 0x160310
    pthread_self(...); // call imported API via PLT at 0x160334
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6a3ac = "[%s(%d)]:> (%ld):> [%s]receive_frame decode eof, sleep wait for seek end pStreamCtx:%p"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x160364
    pthread_self(...); // call imported API via PLT at 0x160388
    const char* s_83b2d = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [%s]receive_frame decode eof, sleep wait for seek end pStreamCtx:%p
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1603b4
    _ZN7MMCodec11PacketQueue9nbPacketsEv(...); // call imported API via PLT at 0x1603bc
    _ZN7MMCodec11PacketQueue5isEofEv(...); // call imported API via PLT at 0x1603c8
    _ZN7MMCodec10FrameQueue10setEofFlagEb(...); // call imported API via PLT at 0x1603d8
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x1603e8
    _ZN7MMCodec11PacketQueue9nbPacketsEv(...); // call imported API via PLT at 0x1603f0
    _ZN7MMCodec11PacketQueue5isEofEv(...); // call imported API via PLT at 0x160400
    _ZN7MMCodec10FrameQueue10setEofFlagEb(...); // call imported API via PLT at 0x160410
    av_packet_move_ref(...); // call imported API via PLT at 0x160420
    _ZN7MMCodec11PacketQueue3getEP8AVPacketbRNS0_10PacketInfoE(...); // call imported API via PLT at 0x160438
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x160450
    av_packet_unref(...); // call imported API via PLT at 0x160470
    _ZN7MMCodec11PacketQueue9nbPacketsEv(...); // call imported API via PLT at 0x160478
    _ZN7MMCodec11PacketQueue5isEofEv(...); // call imported API via PLT at 0x160484
    _ZN7MMCodec10FrameQueue10setEofFlagEb(...); // call imported API via PLT at 0x160494
    _ZN7MMCodec11PacketQueue3getEP8AVPacketbRNS0_10PacketInfoE(...); // call imported API via PLT at 0x1604a8
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x1604b8
    av_packet_unref(...); // call imported API via PLT at 0x1604cc
    av_packet_unref(...); // call imported API via PLT at 0x1604ec
    _ZN7MMCodec13AICodecGlobal11getInstanceEv(...); // call imported API via PLT at 0x1604f4
    _ZN7MMCodec13AICodecGlobal10skipPacketEv(...); // call imported API via PLT at 0x1604f8
    _ZN7MMCodec13AICodecGlobal11getInstanceEv(...); // call imported API via PLT at 0x160510
    _ZN7MMCodec13AICodecGlobal11flushPacketEv(...); // call imported API via PLT at 0x160514
    _ZN7MMCodec10StreamBase9getFilterEv(...); // call imported API via PLT at 0x160528
    av_get_time_base_q(...); // call imported API via PLT at 0x16054c
    av_rescale_q(...); // call imported API via PLT at 0x16055c
    _ZN7MMCodec11MediaFilter17filterVideoPacketEP8AVPacketlb(...); // call imported API via PLT at 0x160574
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x160584
    av_packet_unref(...); // call imported API via PLT at 0x160598
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1605a0
    pthread_self(...); // call imported API via PLT at 0x1605dc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8bba2 = "[%s(%d)]:> (%ld):> peek decode frame queue writable error! drop %lld %s frame"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16060c
    const char* s_79738 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> peek decode frame queue writable error! drop %lld %s frame
"; // string xref
    void* g_201028 = (void*)0x201028; // global ref
    (*x8)(...); // indirect call at 0x16065c
    pthread_self(...); // call imported API via PLT at 0x160690
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_87b25 = "[%s(%d)]:> (%ld):> send_packet returned EAGAIN"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1606b8
    pthread_self(...); // call imported API via PLT at 0x1606dc
    const char* s_785a4 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> send_packet returned EAGAIN
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x160700
    av_packet_move_ref(...); // call imported API via PLT at 0x16070c
    pthread_self(...); // call imported API via PLT at 0x160728
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_87668 = "[%s(%d)]:> (%ld):> decode frame queue abort -> thread abort, drop %lld %s frame"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x160758
    const char* s_796d6 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> decode frame queue abort -> thread abort, drop %lld %s frame
"; // string xref
    void* g_201018 = (void*)0x201018; // global ref
    pthread_self(...); // call imported API via PLT at 0x160794
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1607bc
    _ZN7MMCodec10FrameQueue11nbRemainingEv(...); // call imported API via PLT at 0x1607c8
    _ZN7MMCodec10FrameQueue5flushEv(...); // call imported API via PLT at 0x1607ec
    (*x8)(...); // indirect call at 0x160804
    _ZN7MMCodec10FrameQueue5flushEv(...); // call imported API via PLT at 0x16080c
    sub_13DBC8(...); // call internal func at 0x16083c
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x160864
    av_get_time_base_q(...); // call imported API via PLT at 0x160878
    av_rescale_q(...); // call imported API via PLT at 0x160888
    av_packet_unref(...); // call imported API via PLT at 0x1608a0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1608a8
    av_packet_unref(...); // call imported API via PLT at 0x1608b0
    av_gettime_relative(...); // call imported API via PLT at 0x1608e4
    sub_13DB08(...); // call internal func at 0x1608f4
    av_packet_unref(...); // call imported API via PLT at 0x160914
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0x160928
    const char* s_8296e = "Software sendPacket failed::"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0x16093c
    const char* s_67e57 = "; for "; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc(...); // call imported API via PLT at 0x160964
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x160990
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1609b4
    void* g_201008 = (void*)0x201008; // global ref
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1609cc
    void* g_6fc01 = (void*)0x6fc01; // global ref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x1609e0
    sub_1158F8(...); // call internal func at 0x1609f0
    _ZdlPv(...); // call imported API via PLT at 0x160a18
    _ZN7MMCodec18MediaHandleContext12addErrorInfoEPKc(...); // call imported API via PLT at 0x160a38
    pthread_self(...); // call imported API via PLT at 0x160a5c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86d0f = "[%s(%d)]:> (%ld):> %s!"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x160a88
    pthread_self(...); // call imported API via PLT at 0x160aac
    const char* s_86d26 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s!
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x160ad4
    _ZN7MMCodec18MediaHandleContext8callbackEiidPv(...); // call imported API via PLT at 0x160af8
    _ZdlPv(...); // call imported API via PLT at 0x160b08
    _ZdlPv(...); // call imported API via PLT at 0x160b14
    _ZdlPv(...); // call imported API via PLT at 0x160b24
    _ZdlPv(...); // call imported API via PLT at 0x160b34
    pthread_self(...); // call imported API via PLT at 0x160b64
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90718 = "[%s(%d)]:> (%ld):> decode thread parameter is error!"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x160b90
    const char* s_813e7 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> decode thread parameter is error!
"; // string xref
    pthread_self(...); // call imported API via PLT at 0x160bcc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_9074d = "[%s(%d)]:> (%ld):> decode thread media type is error! %d"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x160bfc
    pthread_self(...); // call imported API via PLT at 0x160c20
    const char* s_8bf10 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> decode thread media type is error! %d
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x160c4c
    pthread_self(...); // call imported API via PLT at 0x160c74
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_84c14 = "[%s(%d)]:> (%ld):> packet queue abort! thread exit!"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x160ca0
    pthread_self(...); // call imported API via PLT at 0x160cc4
    const char* s_8142e = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packet queue abort! thread exit!
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x160cec
    pthread_self(...); // call imported API via PLT at 0x160d18
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_87aff = "[%s(%d)]:> (%ld):> exit decode thread"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x160d44
    pthread_self(...); // call imported API via PLT at 0x160d68
    const char* s_7c033 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> exit decode thread
"; // string xref
    const char* s_8befe = "mediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x160d90
    _ZdlPv(...); // call imported API via PLT at 0x160dd0
    _ZdlPv(...); // call imported API via PLT at 0x160df0
    _ZdlPv(...); // call imported API via PLT at 0x160e10
    _ZdlPv(...); // call imported API via PLT at 0x160e30
    _ZdlPv(...); // call imported API via PLT at 0x160e4c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x160eac
    sub_13DBC8(...); // call internal func at 0x160ed4
    __stack_chk_fail(...); // call imported API via PLT at 0x160ef4
}
