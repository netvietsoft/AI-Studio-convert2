// Function: MMCodec::mediaReadKeyThread(void*)
// RVA: 0x15b7b4, Size: 5436 bytes
int64_t _ZN7MMCodec18mediaReadKeyThreadEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x15b804
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0x15b808
    pthread_self(...); // call imported API via PLT at 0x15b864
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_892f9 = "[%s(%d)]:> (%ld):> [>>>start]Media:%s, MediaHandleContext:%p, video:%d, audio:%d"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15b8a0
    pthread_self(...); // call imported API via PLT at 0x15b8bc
    const char* s_84b85 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [>>>start]Media:%s, MediaHandleContext:%p, video:%d, audio:%d
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15b8f8
    avformat_seek_file(...); // call imported API via PLT at 0x15b920
    pthread_self(...); // call imported API via PLT at 0x15b96c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_734b4 = "[%s(%d)]:> (%ld):> input parameter is null"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15b994
    pthread_self(...); // call imported API via PLT at 0x15b9b0
    const char* s_6ee14 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> input parameter is null
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15b9d4
    pthread_self(...); // call imported API via PLT at 0x15ba08
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6dc11 = "[%s(%d)]:> (%ld):> input self thread id is null"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15ba30
    pthread_self(...); // call imported API via PLT at 0x15ba4c
    const char* s_7850c = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> input self thread id is null
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15ba70
    pthread_self(...); // call imported API via PLT at 0x15baa4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_813bc = "[%s(%d)]:> (%ld):> acquireAVPacket is null"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15bacc
    pthread_self(...); // call imported API via PLT at 0x15bae8
    const char* s_734df = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> acquireAVPacket is null
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15bb0c
    _ZN7MMCodec13ThreadContext8markOverEv(...); // call imported API via PLT at 0x15bb14
    pthread_self(...); // call imported API via PLT at 0x15bb38
    void* g_6fc01 = (void*)0x6fc01; // global ref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_76c59 = "[%s(%d)]:> (%ld):> Media %s read thread exit! read packet cnt %lld"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15bb78
    pthread_self(...); // call imported API via PLT at 0x15bbb4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7f775 = "[%s(%d)]:> (%ld):> counld not find video stream or counld not find key table"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15bbdc
    pthread_self(...); // call imported API via PLT at 0x15bbf8
    const char* s_6ee51 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> counld not find video stream or counld not find key table
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    av_packet_unref(...); // call imported API via PLT at 0x15bc24
    _ZN7MMCodec18MediaHandleContext18processSeekRequestEPl(...); // call imported API via PLT at 0x15bc50
    pthread_self(...); // call imported API via PLT at 0x15bc70
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7854e = "[%s(%d)]:> (%ld):> !!! process seek failed !!!"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15bc98
    pthread_self(...); // call imported API via PLT at 0x15bcb4
    const char* s_828e7 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> !!! process seek failed !!!
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15bcd8
    av_packet_unref(...); // call imported API via PLT at 0x15bce0
    av_read_frame(...); // call imported API via PLT at 0x15bcec
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x15bd08
    _ZN7MMCodec11PacketQueue3putEP8AVPacketbbi(...); // call imported API via PLT at 0x15bd34
    _ZN7MMCodec12initAVPacketEP8AVPacket(...); // call imported API via PLT at 0x15bd3c
    strlen(...); // call imported API via PLT at 0x15bd60
    pthread_self(...); // call imported API via PLT at 0x15bdd0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6dc41 = "[%s(%d)]:> (%ld):> reset video end of pts %lld -> %lld"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15be00
    pthread_self(...); // call imported API via PLT at 0x15be1c
    const char* s_86880 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> reset video end of pts %lld -> %lld
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15be48
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x15be70
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x15beac
    _ZN7MMCodec11PacketQueue7isFlushEv(...); // call imported API via PLT at 0x15beb8
    _ZN7MMCodec11PacketQueue13putNullPacketEi(...); // call imported API via PLT at 0x15bec8
    _ZN7MMCodec11PacketQueue6setEofEb(...); // call imported API via PLT at 0x15bed4
    pthread_self(...); // call imported API via PLT at 0x15bef4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8dbf9 = "[%s(%d)]:> (%ld):> read eof, sleep wait for seek... _mediaHandle:%p"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15bf20
    _ZN7MMCodec18MediaHandleContext15waitSeekRequestEv(...); // call imported API via PLT at 0x15bf34
    pthread_self(...); // call imported API via PLT at 0x15bf50
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_91868 = "[%s(%d)]:> (%ld):> read eof, sleep wait for seek end _mediaHandle:%p"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15bf7c
    pthread_self(...); // call imported API via PLT at 0x15bfa8
    const char* s_6fea0 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> read eof, sleep wait for seek... _mediaHandle:%p
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15bfd0
    _ZN7MMCodec18MediaHandleContext15waitSeekRequestEv(...); // call imported API via PLT at 0x15bfd8
    pthread_self(...); // call imported API via PLT at 0x15c000
    const char* s_68009 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> read eof, sleep wait for seek end _mediaHandle:%p
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15c028
    void* g_201001 = (void*)0x201001; // global ref
    _Znwm(...); // call imported API via PLT at 0x15c044
    void* g_201002 = (void*)0x201002; // global ref
    memmove(...); // call imported API via PLT at 0x15c064
    const char* s_6c5ea = "video packet dts is invalid; from "; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0x15c07c
    _ZdlPv(...); // call imported API via PLT at 0x15c0ac
    _ZN7MMCodec18MediaHandleContext8callbackEiidPv(...); // call imported API via PLT at 0x15c0dc
    _ZdlPv(...); // call imported API via PLT at 0x15c0f0
    av_get_time_base_q(...); // call imported API via PLT at 0x15c104
    av_rescale_q(...); // call imported API via PLT at 0x15c114
    av_get_time_base_q(...); // call imported API via PLT at 0x15c128
    av_rescale_q(...); // call imported API via PLT at 0x15c138
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15c168
    _Znwm(...); // call imported API via PLT at 0x15c1bc
    void* g_201001 = (void*)0x201001; // global ref
    _ZN7MMCodec13KeyFrameTable10queryEntryElPib(...); // call imported API via PLT at 0x15c220
    _ZN7MMCodec13KeyFrameTable12getEntrySizeEv(...); // call imported API via PLT at 0x15c244
    _ZN7MMCodec13KeyFrameTable12getEntrySizeEv(...); // call imported API via PLT at 0x15c258
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x15c274
    av_seek_frame(...); // call imported API via PLT at 0x15c28c
    pthread_self(...); // call imported API via PLT at 0x15c2b4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7c00e = "[%s(%d)]:> (%ld):> query %lld failed"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15c2e0
    pthread_self(...); // call imported API via PLT at 0x15c2fc
    const char* s_8bec7 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> query %lld failed
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15c324
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15c330
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15c33c
    pthread_self(...); // call imported API via PLT at 0x15c364
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_84be8 = "[%s(%d)]:> (%ld):> get next entry failed %d"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15c394
    pthread_self(...); // call imported API via PLT at 0x15c3b0
    const char* s_6fef6 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> get next entry failed %d
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15c3dc
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x15c3e4
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x15c3f0
    const char* s_7d42e = "SeekFrame failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0x15c404
    const char* s_67e57 = "; for "; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc(...); // call imported API via PLT at 0x15c42c
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x15c450
    sub_1158F8(...); // call internal func at 0x15c460
    _ZdlPv(...); // call imported API via PLT at 0x15c488
    _ZN7MMCodec18MediaHandleContext12addErrorInfoEPKc(...); // call imported API via PLT at 0x15c4ac
    pthread_self(...); // call imported API via PLT at 0x15c4c8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86d0f = "[%s(%d)]:> (%ld):> %s!"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15c4f4
    pthread_self(...); // call imported API via PLT at 0x15c510
    const char* s_86d26 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s!
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15c538
    _ZdlPv(...); // call imported API via PLT at 0x15c54c
    _ZdlPv(...); // call imported API via PLT at 0x15c55c
    _ZdlPv(...); // call imported API via PLT at 0x15c56c
    _ZdlPv(...); // call imported API via PLT at 0x15c57c
    pthread_self(...); // call imported API via PLT at 0x15c5a4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_828c3 = "[%s(%d)]:> (%ld):> avformat is null"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15c5cc
    pthread_self(...); // call imported API via PLT at 0x15c5e8
    const char* s_67fd3 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> avformat is null
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15c60c
    _ZN7MMCodec13ThreadContext8markOverEv(...); // call imported API via PLT at 0x15c618
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x15c620
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0x15c628
    pthread_self(...); // call imported API via PLT at 0x15c650
    void* g_6fc01 = (void*)0x6fc01; // global ref
    const char* s_6dc78 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Media %s read thread exit! read packet cnt %lld
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15c68c
    return a0;
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x15c6f0
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x15c72c
    _ZN7MMCodec11PacketQueue13putNullPacketEi(...); // call imported API via PLT at 0x15c73c
    _ZN7MMCodec11PacketQueue6setEofEb(...); // call imported API via PLT at 0x15c748
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x15c758
    strlen(...); // call imported API via PLT at 0x15c760
    void* g_201001 = (void*)0x201001; // global ref
    _Znwm(...); // call imported API via PLT at 0x15c798
    void* g_201002 = (void*)0x201002; // global ref
    memmove(...); // call imported API via PLT at 0x15c7c0
    const char* s_87655 = "ReadPacket failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0x15c7d8
    const char* s_68cca = "; from "; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc(...); // call imported API via PLT at 0x15c800
    strlen(...); // call imported API via PLT at 0x15c824
    void* g_201001 = (void*)0x201001; // global ref
    _Znwm(...); // call imported API via PLT at 0x15c860
    memmove(...); // call imported API via PLT at 0x15c888
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm(...); // call imported API via PLT at 0x15c8b4
    _ZdlPv(...); // call imported API via PLT at 0x15c8f8
    _ZN7MMCodec18MediaHandleContext12addErrorInfoEPKc(...); // call imported API via PLT at 0x15c920
    _ZN7MMCodec18MediaHandleContext8callbackEiidPv(...); // call imported API via PLT at 0x15c93c
    _ZdlPv(...); // call imported API via PLT at 0x15c950
    pthread_self(...); // call imported API via PLT at 0x15c994
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x15c9a0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_83a44 = "[%s(%d)]:> (%ld):> Read frame exit! [%s]"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15c9cc
    pthread_self(...); // call imported API via PLT at 0x15c9e8
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x15c9f4
    const char* s_7e5da = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Read frame exit! [%s]
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15ca1c
    _ZdlPv(...); // call imported API via PLT at 0x15ca28
    _ZdlPv(...); // call imported API via PLT at 0x15ca38
    _ZdlPv(...); // call imported API via PLT at 0x15ca48
    pthread_self(...); // call imported API via PLT at 0x15ca70
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x15ca7c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_918ad = "[%s(%d)]:> (%ld):> Read frame exit with error [%s] ! ! !"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15caa8
    pthread_self(...); // call imported API via PLT at 0x15cac4
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x15cad0
    const char* s_7bfc3 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Read frame exit with error [%s] ! ! !
"; // string xref
    const char* s_6a399 = "mediaReadKeyThread"; // string xref
    sub_D22F8(...); // call internal func at 0x15cb0c
    sub_D22F8(...); // call internal func at 0x15cb24
    sub_D22F8(...); // call internal func at 0x15cb3c
    _ZdlPv(...); // call imported API via PLT at 0x15cb6c
    _ZdlPv(...); // call imported API via PLT at 0x15cb8c
    _ZdlPv(...); // call imported API via PLT at 0x15cbac
    _ZdlPv(...); // call imported API via PLT at 0x15cbe4
    _ZdlPv(...); // call imported API via PLT at 0x15cc1c
    _ZdlPv(...); // call imported API via PLT at 0x15cc5c
    _ZdlPv(...); // call imported API via PLT at 0x15cc6c
    _ZdlPv(...); // call imported API via PLT at 0x15cc7c
    _ZdlPv(...); // call imported API via PLT at 0x15cca0
    _ZdlPv(...); // call imported API via PLT at 0x15ccb8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15cccc
    __stack_chk_fail(...); // call imported API via PLT at 0x15ccec
}
