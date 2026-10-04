// Function: MMCodec::FFmpegMediaStream::decode()
// RVA: 0x13b8b8, Size: 6040 bytes
int64_t _ZN7MMCodec17FFmpegMediaStream6decodeEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec10StreamBase9getFilterEv(...); // call imported API via PLT at 0x13b900
    const char* s_83759 = "audio"; // string xref
    const char* s_6ea58 = "video"; // string xref
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x13b928
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0x13b92c
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x13b93c
    _ZN7MMCodec14AICodecContext12acquireFrameEv(...); // call imported API via PLT at 0x13b940
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x13b950
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x13b970
    _ZN7MMCodec18MediaHandleContext18processSeekRequestEPl(...); // call imported API via PLT at 0x13b998
    (*x8)(...); // indirect call at 0x13b9c0
    _ZN7MMCodec10FrameQueue5flushEv(...); // call imported API via PLT at 0x13b9c8
    sub_13DBC8(...); // call internal func at 0x13b9f4
    av_packet_unref(...); // call imported API via PLT at 0x13b9fc
    pthread_self(...); // call imported API via PLT at 0x13ba2c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_81207 = "[%s(%d)]:> (%ld):> allocAVFrame is null"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13ba54
    pthread_self(...); // call imported API via PLT at 0x13ba78
    const char* s_782d1 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> allocAVFrame is null
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13ba9c
    pthread_self(...); // call imported API via PLT at 0x13bac4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_84896 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> acquireAVPacket is null"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13baf0
    pthread_self(...); // call imported API via PLT at 0x13bb14
    const char* s_7d0d9 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> acquireAVPacket is null
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13bb3c
    pthread_self(...); // call imported API via PLT at 0x13bb68
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_75368 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> FormatContext is null"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13bb94
    pthread_self(...); // call imported API via PLT at 0x13bbb8
    const char* s_71b6c = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> FormatContext is null
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    pthread_self(...); // call imported API via PLT at 0x13bc00
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_91585 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> getPacketQueue is null"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13bc2c
    pthread_self(...); // call imported API via PLT at 0x13bc50
    const char* s_8375f = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> getPacketQueue is null
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13bc78
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x13bc84
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0x13bc8c
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x13bc98
    _ZN7MMCodec14AICodecContext12releaseFrameEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x13bca0
    return a0;
    pthread_self(...); // call imported API via PLT at 0x13bcf8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8647d = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> !!! process seek failed !!!"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13bd24
    pthread_self(...); // call imported API via PLT at 0x13bd48
    const char* s_7684b = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> !!! process seek failed !!!
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13bd70
    av_packet_unref(...); // call imported API via PLT at 0x13bd78
    av_packet_move_ref(...); // call imported API via PLT at 0x13bd90
    (*x8)(...); // indirect call at 0x13bdc8
    pthread_self(...); // call imported API via PLT at 0x13bdfc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8bb06 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> readPacket failed %d"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13be2c
    pthread_self(...); // call imported API via PLT at 0x13be70
    const char* s_7e266 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> readPacket failed %d
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13be9c
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x13bedc
    _ZN7MMCodec11PacketQueue7isFlushEv(...); // call imported API via PLT at 0x13bee4
    _ZN7MMCodec11PacketQueue6setEofEb(...); // call imported API via PLT at 0x13bef4
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0x13bf00
    const char* s_87655 = "ReadPacket failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0x13bf14
    const char* s_68cca = "; from "; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc(...); // call imported API via PLT at 0x13bf3c
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x13bf60
    sub_1158F8(...); // call internal func at 0x13bf70
    _ZdlPv(...); // call imported API via PLT at 0x13bf98
    _ZN7MMCodec18MediaHandleContext12addErrorInfoEPKc(...); // call imported API via PLT at 0x13bfbc
    _ZN7MMCodec18MediaHandleContext8callbackEiidPv(...); // call imported API via PLT at 0x13bfd4
    pthread_self(...); // call imported API via PLT at 0x13bff8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_91617 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> [%s] ! ! !"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13c028
    pthread_self(...); // call imported API via PLT at 0x13c04c
    const char* s_86523 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> [%s] ! ! !
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13c078
    _ZdlPv(...); // call imported API via PLT at 0x13c088
    _ZdlPv(...); // call imported API via PLT at 0x13c09c
    _ZdlPv(...); // call imported API via PLT at 0x13c0ac
    _ZdlPv(...); // call imported API via PLT at 0x13c0bc
    pthread_self(...); // call imported API via PLT at 0x13c108
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7e2b7 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> reset video end of pts %lld -> %lld"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13c13c
    pthread_self(...); // call imported API via PLT at 0x13c15c
    const char* s_864c3 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> reset video end of pts %lld -> %lld
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13c18c
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x13c1b4
    _ZN7MMCodec11PacketQueue7isFlushEv(...); // call imported API via PLT at 0x13c1bc
    pthread_self(...); // call imported API via PLT at 0x13c1e4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7bdf0 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Read frame exit! EOF"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13c210
    _ZN7MMCodec11PacketQueue6setEofEb(...); // call imported API via PLT at 0x13c22c
    pthread_self(...); // call imported API via PLT at 0x13c25c
    const char* s_915c6 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Read frame exit! EOF
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13c284
    av_packet_unref(...); // call imported API via PLT at 0x13c290
    av_get_time_base_q(...); // call imported API via PLT at 0x13c2c4
    av_rescale_q(...); // call imported API via PLT at 0x13c2d4
    _ZN7MMCodec11MediaFilter17filterVideoPacketEP8AVPacketlb(...); // call imported API via PLT at 0x13c2e8
    (*x8)(...); // indirect call at 0x13c304
    pthread_self(...); // call imported API via PLT at 0x13c334
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_88ea9 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> send_packet %lld returned EAGAIN"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13c364
    pthread_self(...); // call imported API via PLT at 0x13c388
    const char* s_8bb45 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> send_packet %lld returned EAGAIN
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13c3b4
    av_packet_move_ref(...); // call imported API via PLT at 0x13c3c8
    av_packet_unref(...); // call imported API via PLT at 0x13c3d0
    _ZN7MMCodec10FrameQueue15leftBufferFrameEv(...); // call imported API via PLT at 0x13c3d8
    av_get_time_base_q(...); // call imported API via PLT at 0x13c424
    av_get_time_base_q(...); // call imported API via PLT at 0x13c434
    av_rescale_q(...); // call imported API via PLT at 0x13c444
    av_rescale_q(...); // call imported API via PLT at 0x13c464
    av_get_time_base_q(...); // call imported API via PLT at 0x13c480
    av_rescale_q(...); // call imported API via PLT at 0x13c490
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x13c4ac
    _ZNSt6__ndk13mapIllNS_4lessIlEENS_9allocatorINS_4pairIKllEEEEE6insertB8ne180000INS4_IllEEvEENS4_INS_14__map_iteratorINS_15__tree_iteratorINS_12__value_typeIllEEPNS_11__tree_nodeISE_PvEElEEEEbEEOT_(...); // call imported API via PLT at 0x13c4bc
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x13c4c4
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x13c4d8
    sub_13DB08(...); // call internal func at 0x13c4e8
    _ZdlPv(...); // call imported API via PLT at 0x13c508
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x13c510
    (*x8)(...); // indirect call at 0x13c524
    _ZN7MMCodec10FrameQueue15leftBufferFrameEv(...); // call imported API via PLT at 0x13c52c
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x13c53c
    (*x8)(...); // indirect call at 0x13c558
    const char* s_830e5 = ": [%s(%d)]:> [AndroidMediaStream(%p)](%ld):> decode thread state is invalid %d, return eof
"; // string xref
    _ZdlPv(...); // call imported API via PLT at 0x13c5ec
    void* g_201008 = (void*)0x201008; // global ref
    _ZN7MMCodec11MediaFilter16filterVideoFrameEP7AVFramelRKNS_11PacketQueue10PacketInfoERb(...); // call imported API via PLT at 0x13c638
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x13c648
    _ZN7MMCodec11MediaFilter16filterAudioFrameEP7AVFramelliRb(...); // call imported API via PLT at 0x13c6d4
    av_frame_unref(...); // call imported API via PLT at 0x13c6e4
    _ZN7MMCodec10FrameQueue12peekWritableERPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x13c6f4
    _ZN7MMCodec11MediaFilter29filterVideoFrameAfterWritableEPNS_12MMCodecFrameERb(...); // call imported API via PLT at 0x13c728
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x13c738
    av_frame_unref(...); // call imported API via PLT at 0x13c7a8
    av_frame_unref(...); // call imported API via PLT at 0x13c7c0
    _ZN7MMCodec12MMCodecFrame7moveRefEPS0_S1_(...); // call imported API via PLT at 0x13c7cc
    (*x8)(...); // indirect call at 0x13c7e0
    void* g_2010e3 = (void*)0x2010e3; // global ref
    const char* s_830e4 = "c: [%s(%d)]:> [AndroidMediaStream(%p)](%ld):> decode thread state is invalid %d, return eof
"; // string xref
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x13c860
    _ZdlPv(...); // call imported API via PLT at 0x13c908
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x13c914
    (*x8)(...); // indirect call at 0x13c928
    pthread_self(...); // call imported API via PLT at 0x13c954
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90105 = "[%s(%d)]:> (%ld):> get null frame from decode frame queue, drop %lld %s frame"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13c984
    pthread_self(...); // call imported API via PLT at 0x13c9a8
    const char* s_825e6 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> get null frame from decode frame queue, drop %lld %s frame
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13c9d4
    _ZN7MMCodec10FrameQueue3putEv(...); // call imported API via PLT at 0x13c9f8
    _ZN7MMCodec18MediaHandleContext12needSeekFileEli(...); // call imported API via PLT at 0x13ca34
    void* g_2010e3 = (void*)0x2010e3; // global ref
    av_get_time_base_q(...); // call imported API via PLT at 0x13ca54
    av_rescale_q(...); // call imported API via PLT at 0x13ca68
    (*x8)(...); // indirect call at 0x13ca88
    pthread_self(...); // call imported API via PLT at 0x13cab0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_81207 = "[%s(%d)]:> (%ld):> allocAVFrame is null"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13cad8
    pthread_self(...); // call imported API via PLT at 0x13cafc
    const char* s_782d1 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> allocAVFrame is null
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13cb20
    (*x8)(...); // indirect call at 0x13cb38
    _ZN7MMCodec11PacketQueue9nbPacketsEv(...); // call imported API via PLT at 0x13cb44
    _ZN7MMCodec11PacketQueue5isEofEv(...); // call imported API via PLT at 0x13cb50
    _ZN7MMCodec10FrameQueue10setEofFlagEb(...); // call imported API via PLT at 0x13cb60
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x13cb70
    pthread_self(...); // call imported API via PLT at 0x13cba4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6a0c5 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> [%s]get packet error![%d]"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13cbd8
    pthread_self(...); // call imported API via PLT at 0x13cbfc
    const char* s_7f489 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> [%s]get packet error![%d]
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13cc2c
    av_packet_unref(...); // call imported API via PLT at 0x13cc34
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0x13cc40
    const char* s_6ea5e = "Software sendPacket failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0x13cc54
    const char* s_67e57 = "; for "; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc(...); // call imported API via PLT at 0x13cc7c
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x13cca8
    pthread_self(...); // call imported API via PLT at 0x13ccdc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8bba2 = "[%s(%d)]:> (%ld):> peek decode frame queue writable error! drop %lld %s frame"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13cd0c
    pthread_self(...); // call imported API via PLT at 0x13cd30
    const char* s_79738 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> peek decode frame queue writable error! drop %lld %s frame
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    void* g_6fc01 = (void*)0x6fc01; // global ref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x13cd68
    sub_1158F8(...); // call internal func at 0x13cd78
    _ZdlPv(...); // call imported API via PLT at 0x13cda0
    _ZN7MMCodec18MediaHandleContext12addErrorInfoEPKc(...); // call imported API via PLT at 0x13cdc4
    pthread_self(...); // call imported API via PLT at 0x13cde0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_88ef4 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> %s!"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13ce10
    pthread_self(...); // call imported API via PLT at 0x13ce34
    const char* s_7e305 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> %s!
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13ce60
    _ZdlPv(...); // call imported API via PLT at 0x13ce70
    _ZdlPv(...); // call imported API via PLT at 0x13ce7c
    _ZdlPv(...); // call imported API via PLT at 0x13ce8c
    _ZdlPv(...); // call imported API via PLT at 0x13ce9c
    pthread_self(...); // call imported API via PLT at 0x13cec0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_87668 = "[%s(%d)]:> (%ld):> decode frame queue abort -> thread abort, drop %lld %s frame"; // string xref
    const char* s_6b231 = "decode"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13cef0
    pthread_self(...); // call imported API via PLT at 0x13cf14
    const char* s_796d6 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> decode frame queue abort -> thread abort, drop %lld %s frame
"; // string xref
    const char* s_6b231 = "decode"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13cf40
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x13cf50
    _ZdlPv(...); // call imported API via PLT at 0x13cfb8
    _ZdlPv(...); // call imported API via PLT at 0x13cfd8
    _ZdlPv(...); // call imported API via PLT at 0x13cfe8
    _ZdlPv(...); // call imported API via PLT at 0x13d030
    __stack_chk_fail(...); // call imported API via PLT at 0x13d04c
}
