// Function: MMCodec::androidMediaDecodeThread(void*)
// RVA: 0x160fc4, Size: 7788 bytes
int64_t _ZN7MMCodec24androidMediaDecodeThreadEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x161078
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0x16107c
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x16108c
    _ZN7MMCodec14AICodecContext12acquireFrameEv(...); // call imported API via PLT at 0x161090
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x1610a4
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x1610b4
    pthread_self(...); // call imported API via PLT at 0x1610e4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_81474 = "[%s(%d)]:> (%ld):> [>>>start]index:%dMediaHandleContext:%p, stream:%p, frame queue:%p, packet queue:%p"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x161124
    pthread_self(...); // call imported API via PLT at 0x161140
    const char* s_6dd21 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [>>>start]index:%dMediaHandleContext:%p, stream:%p, frame queue:%p, packet queue:%p
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x16117c
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x161184
    _ZN7MMCodec14AICodecContext18getSharedGLContextEv(...); // call imported API via PLT at 0x161188
    (*x8)(...); // indirect call at 0x16119c
    pthread_self(...); // call imported API via PLT at 0x1611c4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8f227 = "[%s(%d)]:> (%ld):> MediaCodec codecOpen error"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1611ec
    const char* s_8dc96 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> MediaCodec codecOpen error
"; // string xref
    pthread_self(...); // call imported API via PLT at 0x161234
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_734b4 = "[%s(%d)]:> (%ld):> input parameter is null"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16125c
    pthread_self(...); // call imported API via PLT at 0x161278
    const char* s_6ee14 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> input parameter is null
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x16129c
    pthread_self(...); // call imported API via PLT at 0x1612c4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90718 = "[%s(%d)]:> (%ld):> decode thread parameter is error!"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1612ec
    const char* s_813e7 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> decode thread parameter is error!
"; // string xref
    pthread_self(...); // call imported API via PLT at 0x161324
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90786 = "[%s(%d)]:> (%ld):> FormatContext is null!"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16134c
    const char* s_68099 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> FormatContext is null!
"; // string xref
    pthread_self(...); // call imported API via PLT at 0x161374
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x161394
    _ZN7MMCodec16ThreadITCContext5condVEv(...); // call imported API via PLT at 0x1613b0
    (*x8)(...); // indirect call at 0x1613cc
    (*x8)(...); // indirect call at 0x1613dc
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x1613f0
    _ZN7MMCodec14AICodecContext12releaseFrameEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x1613f8
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x161404
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0x16140c
    _ZN7MMCodec13ThreadContext8markOverEv(...); // call imported API via PLT at 0x161418
    pthread_self(...); // call imported API via PLT at 0x16143c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6ff34 = "[%s(%d)]:> (%ld):> [%d]Media decode thread exit! thread stat %d deal frame %lld"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16147c
    pthread_self(...); // call imported API via PLT at 0x161498
    const char* s_6a438 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [%d]Media decode thread exit! thread stat %d deal frame %lld
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1614d4
    _ZdlPv(...); // call imported API via PLT at 0x1614f4
    void* g_201008 = (void*)0x201008; // global ref
    _ZdlPv(...); // call imported API via PLT at 0x161540
    void* g_201007 = (void*)0x201007; // global ref
    void* g_2010e3 = (void*)0x2010e3; // global ref
    _ZdlPv(...); // call imported API via PLT at 0x161574
    return a0;
    pthread_self(...); // call imported API via PLT at 0x1615d0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_81207 = "[%s(%d)]:> (%ld):> allocAVFrame is null"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1615f8
    const char* s_782d1 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> allocAVFrame is null
"; // string xref
    pthread_self(...); // call imported API via PLT at 0x161630
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x161650
    pthread_self(...); // call imported API via PLT at 0x16168c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_813bc = "[%s(%d)]:> (%ld):> acquireAVPacket is null"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1616b4
    pthread_self(...); // call imported API via PLT at 0x1616d0
    const char* s_734df = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> acquireAVPacket is null
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1616f4
    pthread_self(...); // call imported API via PLT at 0x161710
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_680d5 = "[%s(%d)]:> (%ld):> packet queue is null!"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x161738
    const char* s_756a6 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packet queue is null!
"; // string xref
    _ZN7MMCodec16ThreadITCContext5condVEv(...); // call imported API via PLT at 0x16177c
    sub_13DBC8(...); // call internal func at 0x1617d8
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x161808
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x16181c
    _ZN7MMCodec10FrameQueue12peekWritableERPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x16182c
    (*x8)(...); // indirect call at 0x161858
    void* g_2010e5 = (void*)0x2010e5; // global ref
    _ZdlPv(...); // call imported API via PLT at 0x1618fc
    void* g_201008 = (void*)0x201008; // global ref
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x16193c
    void* g_201020 = (void*)0x201020; // global ref
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x161954
    _ZN7MMCodec10StreamBase9getFilterEv(...); // call imported API via PLT at 0x161960
    _ZN7MMCodec11MediaFilter16filterVideoFrameEP7AVFramelRKNS_11PacketQueue10PacketInfoERb(...); // call imported API via PLT at 0x161988
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x161998
    const char* s_68020 = ")]:> (%ld):> read eof, sleep wait for seek end _mediaHandle:%p
"; // string xref
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1619b0
    (*x8)(...); // indirect call at 0x1619c4
    _ZN7MMCodec10FrameQueue12peekWritableERPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x1619d4
    _ZN7MMCodec11MediaFilter29filterVideoFrameAfterWritableEPNS_12MMCodecFrameERb(...); // call imported API via PLT at 0x161a04
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x161a14
    const char* s_68020 = ")]:> (%ld):> read eof, sleep wait for seek end _mediaHandle:%p
"; // string xref
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x161a2c
    (*x8)(...); // indirect call at 0x161a40
    av_gettime_relative(...); // call imported API via PLT at 0x161a6c
    _ZN7MMCodec18MediaHandleContext8callbackEiidPv(...); // call imported API via PLT at 0x161abc
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x161acc
    const char* s_75020 = "der$SurfaceTextureCallback"; // string xref
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x161ae4
    (*x8)(...); // indirect call at 0x161af8
    pthread_self(...); // call imported API via PLT at 0x161b24
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6ef57 = "[%s(%d)]:> (%ld):> get null frame from decode frame queue, drop %lld frame"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x161b54
    pthread_self(...); // call imported API via PLT at 0x161b78
    const char* s_79a32 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> get null frame from decode frame queue, drop %lld frame
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x161ba4
    (*x8)(...); // indirect call at 0x161bbc
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0x161bd0
    const char* s_84c48 = "Android receiveFrame failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0x161be4
    const char* s_67e57 = "; for "; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc(...); // call imported API via PLT at 0x161c14
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x161c40
    pthread_self(...); // call imported API via PLT at 0x161c68
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_81207 = "[%s(%d)]:> (%ld):> allocAVFrame is null"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x161c90
    pthread_self(...); // call imported API via PLT at 0x161cb4
    const char* s_782d1 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> allocAVFrame is null
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x161cd8
    pthread_self(...); // call imported API via PLT at 0x161d04
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_814db = "[%s(%d)]:> (%ld):> decode frame queue peekWritable %d %p"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x161d34
    pthread_self(...); // call imported API via PLT at 0x161d58
    const char* s_8a855 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> decode frame queue peekWritable %d %p
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x161d84
    (*x8)(...); // indirect call at 0x161da0
    _ZN7MMCodec12MMCodecFrame7moveRefEPS0_S1_(...); // call imported API via PLT at 0x161dac
    (*x8)(...); // indirect call at 0x161dc0
    _ZN7MMCodec10FrameQueue3putEv(...); // call imported API via PLT at 0x161ddc
    void* g_6fc01 = (void*)0x6fc01; // global ref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x161e10
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm(...); // call imported API via PLT at 0x161e34
    _ZdlPv(...); // call imported API via PLT at 0x161e74
    _ZN7MMCodec18MediaHandleContext12addErrorInfoEPKc(...); // call imported API via PLT at 0x161e94
    pthread_self(...); // call imported API via PLT at 0x161eb8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86d0f = "[%s(%d)]:> (%ld):> %s!"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x161ee4
    pthread_self(...); // call imported API via PLT at 0x161f00
    const char* s_86d26 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s!
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x161f28
    _ZN7MMCodec18MediaHandleContext8callbackEiidPv(...); // call imported API via PLT at 0x161f50
    _ZdlPv(...); // call imported API via PLT at 0x161f60
    _ZN7MMCodec11PacketQueue9nbPacketsEv(...); // call imported API via PLT at 0x161f68
    _ZN7MMCodec11PacketQueue5isEofEv(...); // call imported API via PLT at 0x161f74
    _ZN7MMCodec10FrameQueue10setEofFlagEb(...); // call imported API via PLT at 0x161f84
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x161f94
    pthread_self(...); // call imported API via PLT at 0x161fb8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6a403 = "[%s(%d)]:> (%ld):> decode eof, sleep... streamCtx:%p"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x161fe4
    pthread_self(...); // call imported API via PLT at 0x162008
    const char* s_87b54 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> decode eof, sleep... streamCtx:%p
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x162030
    (*x8)(...); // indirect call at 0x162040
    pthread_self(...); // call imported API via PLT at 0x162064
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_918e6 = "[%s(%d)]:> (%ld):> decode eof, sleep end streamCtx:%p"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x162090
    pthread_self(...); // call imported API via PLT at 0x1620b4
    const char* s_8298b = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> decode eof, sleep end streamCtx:%p
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1620dc
    _ZN7MMCodec11PacketQueue9nbPacketsEv(...); // call imported API via PLT at 0x1620e4
    _ZN7MMCodec11PacketQueue5isEofEv(...); // call imported API via PLT at 0x1620f0
    _ZN7MMCodec10FrameQueue10setEofFlagEb(...); // call imported API via PLT at 0x162100
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x162110
    _ZN7MMCodec11PacketQueue9nbPacketsEv(...); // call imported API via PLT at 0x162118
    _ZN7MMCodec11PacketQueue5isEofEv(...); // call imported API via PLT at 0x162130
    _ZN7MMCodec10FrameQueue10setEofFlagEb(...); // call imported API via PLT at 0x162140
    av_packet_move_ref(...); // call imported API via PLT at 0x162154
    _ZN7MMCodec11PacketQueue3getEP8AVPacketbRNS0_10PacketInfoE(...); // call imported API via PLT at 0x16216c
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x16218c
    _ZN7MMCodec13AICodecGlobal11getInstanceEv(...); // call imported API via PLT at 0x1621ac
    _ZN7MMCodec13AICodecGlobal10skipPacketEv(...); // call imported API via PLT at 0x1621b0
    _ZN7MMCodec13AICodecGlobal11getInstanceEv(...); // call imported API via PLT at 0x1621c4
    _ZN7MMCodec13AICodecGlobal11flushPacketEv(...); // call imported API via PLT at 0x1621c8
    _ZN7MMCodec10StreamBase9getFilterEv(...); // call imported API via PLT at 0x1621dc
    av_get_time_base_q(...); // call imported API via PLT at 0x1621f4
    av_rescale_q(...); // call imported API via PLT at 0x162204
    _ZN7MMCodec11MediaFilter17filterVideoPacketEP8AVPacketlb(...); // call imported API via PLT at 0x16221c
    av_packet_unref(...); // call imported API via PLT at 0x162230
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x162238
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x16224c
    av_packet_unref(...); // call imported API via PLT at 0x16225c
    pthread_self(...); // call imported API via PLT at 0x162280
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_829d3 = "[%s(%d)]:> (%ld):> [%d]This packet serial is out of date"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1622ac
    pthread_self(...); // call imported API via PLT at 0x1622c8
    const char* s_79a8f = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [%d]This packet serial is out of date
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1622f0
    _ZN7MMCodec11PacketQueue9nbPacketsEv(...); // call imported API via PLT at 0x1622f8
    _ZN7MMCodec11PacketQueue5isEofEv(...); // call imported API via PLT at 0x162304
    _ZN7MMCodec10FrameQueue10setEofFlagEb(...); // call imported API via PLT at 0x162314
    _ZN7MMCodec11PacketQueue3getEP8AVPacketbRNS0_10PacketInfoE(...); // call imported API via PLT at 0x162328
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x162338
    av_packet_unref(...); // call imported API via PLT at 0x16234c
    pthread_self(...); // call imported API via PLT at 0x162370
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_829d3 = "[%s(%d)]:> (%ld):> [%d]This packet serial is out of date"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16239c
    pthread_self(...); // call imported API via PLT at 0x1623b8
    const char* s_79a8f = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [%d]This packet serial is out of date
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1623e0
    _ZN7MMCodec10FrameQueue11nbRemainingEv(...); // call imported API via PLT at 0x1623ec
    _ZN7MMCodec10FrameQueue5flushEv(...); // call imported API via PLT at 0x162414
    (*x8)(...); // indirect call at 0x162434
    pthread_self(...); // call imported API via PLT at 0x16246c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_69184 = "[%s(%d)]:> (%ld):> Receive_frame and send_packet both returned EAGAIN, which is an API violation."; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x162494
    pthread_self(...); // call imported API via PLT at 0x1624b8
    const char* s_9191c = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Receive_frame and send_packet both returned EAGAIN, which is an API violation.
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1624dc
    usleep(...); // call imported API via PLT at 0x1624e4
    av_packet_move_ref(...); // call imported API via PLT at 0x1624f0
    av_packet_unref(...); // call imported API via PLT at 0x1624fc
    (*x8)(...); // indirect call at 0x162514
    _ZN7MMCodec10FrameQueue5flushEv(...); // call imported API via PLT at 0x16251c
    pthread_self(...); // call imported API via PLT at 0x162550
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8dd21 = "[%s(%d)]:> (%ld):> [%d]send packet error!"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16257c
    pthread_self(...); // call imported API via PLT at 0x1625a0
    const char* s_72189 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [%d]send packet error!
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1625c8
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0x1625e4
    const char* s_87b9b = "Android sendPacket failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0x1625f8
    const char* s_67e57 = "; for "; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc(...); // call imported API via PLT at 0x162620
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x16264c
    _ZdlPv(...); // call imported API via PLT at 0x162658
    _ZdlPv(...); // call imported API via PLT at 0x162668
    _ZdlPv(...); // call imported API via PLT at 0x162678
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1626a4
    av_get_time_base_q(...); // call imported API via PLT at 0x1626b0
    av_rescale_q(...); // call imported API via PLT at 0x1626c0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1626d8
    pthread_self(...); // call imported API via PLT at 0x162708
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8dcd6 = "[%s(%d)]:> (%ld):> peek decode frame queue writable error! drop %lld frame"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x162738
    const char* s_7f7c2 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> peek decode frame queue writable error! drop %lld frame
"; // string xref
    void* g_201028 = (void*)0x201028; // global ref
    sub_13DB08(...); // call internal func at 0x162794
    pthread_self(...); // call imported API via PLT at 0x1627b0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_907b0 = "[%s(%d)]:> (%ld):> decode frame queue abort -> thread abort, drop %lld frame"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1627e0
    const char* s_7353c = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> decode frame queue abort -> thread abort, drop %lld frame
"; // string xref
    void* g_201018 = (void*)0x201018; // global ref
    pthread_self(...); // call imported API via PLT at 0x16281c
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x162844
    void* g_6fc01 = (void*)0x6fc01; // global ref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x162858
    sub_1158F8(...); // call internal func at 0x162868
    _ZdlPv(...); // call imported API via PLT at 0x162894
    _ZN7MMCodec18MediaHandleContext12addErrorInfoEPKc(...); // call imported API via PLT at 0x1628b4
    pthread_self(...); // call imported API via PLT at 0x1628d8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86d0f = "[%s(%d)]:> (%ld):> %s!"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16290c
    pthread_self(...); // call imported API via PLT at 0x162928
    const char* s_86d26 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s!
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x162950
    _ZN7MMCodec18MediaHandleContext8callbackEiidPv(...); // call imported API via PLT at 0x162978
    _ZdlPv(...); // call imported API via PLT at 0x16298c
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1629a4
    av_get_time_base_q(...); // call imported API via PLT at 0x1629b0
    av_rescale_q(...); // call imported API via PLT at 0x1629c0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1629d8
    pthread_self(...); // call imported API via PLT at 0x1629fc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7c06b = "[%s(%d)]:> (%ld):> send packet error! sleep... streamCtx:%p"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x162a28
    pthread_self(...); // call imported API via PLT at 0x162a4c
    const char* s_79ada = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> send packet error! sleep... streamCtx:%p
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x162a74
    (*x8)(...); // indirect call at 0x162a84
    pthread_self(...); // call imported API via PLT at 0x162aa8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_893e4 = "[%s(%d)]:> (%ld):> send packet error! sleep end streamCtx:%p"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x162ad4
    pthread_self(...); // call imported API via PLT at 0x162af8
    const char* s_84c65 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> send packet error! sleep end streamCtx:%p
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x162b20
    _ZdlPv(...); // call imported API via PLT at 0x162b2c
    _ZdlPv(...); // call imported API via PLT at 0x162b3c
    _ZdlPv(...); // call imported API via PLT at 0x162b4c
    pthread_self(...); // call imported API via PLT at 0x162b80
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_84c14 = "[%s(%d)]:> (%ld):> packet queue abort! thread exit!"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x162ba8
    pthread_self(...); // call imported API via PLT at 0x162bc4
    const char* s_8142e = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> packet queue abort! thread exit!
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x162be8
    pthread_self(...); // call imported API via PLT at 0x162c1c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6c665 = "[%s(%d)]:> (%ld):> Exit decode thread"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x162c44
    pthread_self(...); // call imported API via PLT at 0x162c60
    const char* s_8a81d = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Exit decode thread
"; // string xref
    const char* s_6dd08 = "androidMediaDecodeThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x162c84
    _ZdlPv(...); // call imported API via PLT at 0x162d20
    _ZdlPv(...); // call imported API via PLT at 0x162d40
    _ZdlPv(...); // call imported API via PLT at 0x162d50
    _ZdlPv(...); // call imported API via PLT at 0x162d80
    _ZdlPv(...); // call imported API via PLT at 0x162da8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x162dd8
    sub_13DBC8(...); // call internal func at 0x162e0c
    __stack_chk_fail(...); // call imported API via PLT at 0x162e2c
}
