// Function: MMCodec::mediaReadThread(void*)
// RVA: 0x15ccf0, Size: 5528 bytes
int64_t _ZN7MMCodec15mediaReadThreadEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x15cd60
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0x15cd64
    pthread_self(...); // call imported API via PLT at 0x15ce2c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_734b4 = "[%s(%d)]:> (%ld):> input parameter is null"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15ce54
    pthread_self(...); // call imported API via PLT at 0x15ce70
    const char* s_6ee14 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> input parameter is null
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15ce94
    pthread_self(...); // call imported API via PLT at 0x15cec8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6dc11 = "[%s(%d)]:> (%ld):> input self thread id is null"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15cef0
    pthread_self(...); // call imported API via PLT at 0x15cf0c
    const char* s_7850c = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> input self thread id is null
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15cf30
    pthread_self(...); // call imported API via PLT at 0x15cf64
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_813bc = "[%s(%d)]:> (%ld):> acquireAVPacket is null"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15cf8c
    pthread_self(...); // call imported API via PLT at 0x15cfa8
    const char* s_734df = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> acquireAVPacket is null
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15cfcc
    _ZN7MMCodec13ThreadContext8markOverEv(...); // call imported API via PLT at 0x15cfd4
    pthread_self(...); // call imported API via PLT at 0x15cff8
    void* g_6fc01 = (void*)0x6fc01; // global ref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_76c59 = "[%s(%d)]:> (%ld):> Media %s read thread exit! read packet cnt %lld"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15d038
    pthread_self(...); // call imported API via PLT at 0x15d074
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_828c3 = "[%s(%d)]:> (%ld):> avformat is null"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15d09c
    pthread_self(...); // call imported API via PLT at 0x15d0c0
    const char* s_67fd3 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> avformat is null
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    pthread_self(...); // call imported API via PLT at 0x15d13c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_892f9 = "[%s(%d)]:> (%ld):> [>>>start]Media:%s, MediaHandleContext:%p, video:%d, audio:%d"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15d174
    pthread_self(...); // call imported API via PLT at 0x15d1a8
    const char* s_84b85 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [>>>start]Media:%s, MediaHandleContext:%p, video:%d, audio:%d
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15d1e4
    av_packet_unref(...); // call imported API via PLT at 0x15d270
    _ZN7MMCodec18MediaHandleContext18processSeekRequestEPl(...); // call imported API via PLT at 0x15d298
    void* g_201001 = (void*)0x201001; // global ref
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x15d31c
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x15d33c
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x15d354
    pthread_self(...); // call imported API via PLT at 0x15d390
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7854e = "[%s(%d)]:> (%ld):> !!! process seek failed !!!"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15d3bc
    pthread_self(...); // call imported API via PLT at 0x15d3e4
    const char* s_828e7 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> !!! process seek failed !!!
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15d40c
    av_packet_unref(...); // call imported API via PLT at 0x15d414
    (*x8)(...); // indirect call at 0x15d450
    avformat_index_get_entries_count(...); // call imported API via PLT at 0x15d470
    pthread_self(...); // call imported API via PLT at 0x15d4d0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6dc41 = "[%s(%d)]:> (%ld):> reset video end of pts %lld -> %lld"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15d504
    pthread_self(...); // call imported API via PLT at 0x15d524
    const char* s_86880 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> reset video end of pts %lld -> %lld
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15d554
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x15d57c
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x15d5c0
    _ZN7MMCodec11PacketQueue7isFlushEv(...); // call imported API via PLT at 0x15d5cc
    _ZN7MMCodec11PacketQueue13putNullPacketEi(...); // call imported API via PLT at 0x15d5dc
    _ZN7MMCodec11PacketQueue6setEofEb(...); // call imported API via PLT at 0x15d5e8
    avformat_index_get_entries_count(...); // call imported API via PLT at 0x15d654
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x15d668
    sub_15E288(...); // call internal func at 0x15d688
    avformat_index_get_entry(...); // call imported API via PLT at 0x15d69c
    av_seek_frame(...); // call imported API via PLT at 0x15d6b0
    void* g_201001 = (void*)0x201001; // global ref
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x15d6f0
    _ZN7MMCodec11PacketQueue3putEP8AVPacketbbi(...); // call imported API via PLT at 0x15d714
    _ZN7MMCodec12initAVPacketEP8AVPacket(...); // call imported API via PLT at 0x15d720
    av_get_time_base_q(...); // call imported API via PLT at 0x15d744
    av_rescale_q(...); // call imported API via PLT at 0x15d754
    av_get_time_base_q(...); // call imported API via PLT at 0x15d768
    av_rescale_q(...); // call imported API via PLT at 0x15d778
    av_get_time_base_q(...); // call imported API via PLT at 0x15d7c0
    av_rescale_q(...); // call imported API via PLT at 0x15d7d0
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15d7ec
    _Znwm(...); // call imported API via PLT at 0x15d83c
    void* g_201001 = (void*)0x201001; // global ref
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15d880
    pthread_self(...); // call imported API via PLT at 0x15d8c4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8dbf9 = "[%s(%d)]:> (%ld):> read eof, sleep wait for seek... _mediaHandle:%p"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15d8f0
    _ZN7MMCodec18MediaHandleContext15waitSeekRequestEv(...); // call imported API via PLT at 0x15d904
    pthread_self(...); // call imported API via PLT at 0x15d920
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_91868 = "[%s(%d)]:> (%ld):> read eof, sleep wait for seek end _mediaHandle:%p"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15d94c
    pthread_self(...); // call imported API via PLT at 0x15d978
    const char* s_6fea0 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> read eof, sleep wait for seek... _mediaHandle:%p
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15d9a0
    _ZN7MMCodec18MediaHandleContext15waitSeekRequestEv(...); // call imported API via PLT at 0x15d9a8
    pthread_self(...); // call imported API via PLT at 0x15d9d0
    const char* s_68009 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> read eof, sleep wait for seek end _mediaHandle:%p
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15d9f8
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15da24
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15da48
    pthread_self(...); // call imported API via PLT at 0x15dac0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72160 = "[%s(%d)]:> (%ld):> FormatContext is null"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15dae8
    pthread_self(...); // call imported API via PLT at 0x15db0c
    const char* s_6dccd = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> FormatContext is null
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15db34
    _ZN7MMCodec13ThreadContext8markOverEv(...); // call imported API via PLT at 0x15db40
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x15db48
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0x15db50
    pthread_self(...); // call imported API via PLT at 0x15db90
    void* g_6fc01 = (void*)0x6fc01; // global ref
    const char* s_6dc78 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Media %s read thread exit! read packet cnt %lld
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15dbcc
    return a0;
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x15dc2c
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x15dc6c
    _ZN7MMCodec11PacketQueue13putNullPacketEi(...); // call imported API via PLT at 0x15dc7c
    _ZN7MMCodec11PacketQueue6setEofEb(...); // call imported API via PLT at 0x15dc88
    _ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_(...); // call imported API via PLT at 0x15dcac
    const char* s_87655 = "ReadPacket failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0x15dcc0
    const char* s_68cca = "; from "; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc(...); // call imported API via PLT at 0x15dce8
    strlen(...); // call imported API via PLT at 0x15dd0c
    void* g_201001 = (void*)0x201001; // global ref
    _Znwm(...); // call imported API via PLT at 0x15dd48
    memmove(...); // call imported API via PLT at 0x15dd68
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm(...); // call imported API via PLT at 0x15dd94
    _ZdlPv(...); // call imported API via PLT at 0x15ddd4
    _ZN7MMCodec18MediaHandleContext12addErrorInfoEPKc(...); // call imported API via PLT at 0x15ddf8
    _ZN7MMCodec18MediaHandleContext8callbackEiidPv(...); // call imported API via PLT at 0x15de10
    _ZdlPv(...); // call imported API via PLT at 0x15de20
    pthread_self(...); // call imported API via PLT at 0x15de48
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_76c9c = "[%s(%d)]:> (%ld):> Read frame exit! EOF"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15de74
    pthread_self(...); // call imported API via PLT at 0x15de90
    const char* s_6eeb0 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Read frame exit! EOF
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15deb8
    pthread_self(...); // call imported API via PLT at 0x15ded8
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x15dee4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_918ad = "[%s(%d)]:> (%ld):> Read frame exit with error [%s] ! ! !"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15df14
    pthread_self(...); // call imported API via PLT at 0x15df30
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x15df3c
    const char* s_7bfc3 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> Read frame exit with error [%s] ! ! !
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15df68
    _ZdlPv(...); // call imported API via PLT at 0x15df74
    _ZdlPv(...); // call imported API via PLT at 0x15df84
    _ZdlPv(...); // call imported API via PLT at 0x15df94
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x15dfa4
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x15dfb0
    const char* s_7d42e = "SeekFrame failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0x15dfc4
    const char* s_67e57 = "; for "; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc(...); // call imported API via PLT at 0x15dfec
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x15e024
    sub_1158F8(...); // call internal func at 0x15e034
    _ZdlPv(...); // call imported API via PLT at 0x15e05c
    _ZN7MMCodec18MediaHandleContext12addErrorInfoEPKc(...); // call imported API via PLT at 0x15e080
    pthread_self(...); // call imported API via PLT at 0x15e09c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86d0f = "[%s(%d)]:> (%ld):> %s!"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15e0c8
    pthread_self(...); // call imported API via PLT at 0x15e0e4
    const char* s_86d26 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> %s!
"; // string xref
    const char* s_72150 = "mediaReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15e10c
    _ZdlPv(...); // call imported API via PLT at 0x15e11c
    _ZdlPv(...); // call imported API via PLT at 0x15e12c
    _ZdlPv(...); // call imported API via PLT at 0x15e13c
    _ZdlPv(...); // call imported API via PLT at 0x15e14c
    sub_D22F8(...); // call internal func at 0x15e174
    _ZdlPv(...); // call imported API via PLT at 0x15e1dc
    _ZdlPv(...); // call imported API via PLT at 0x15e21c
    _ZdlPv(...); // call imported API via PLT at 0x15e22c
    _ZdlPv(...); // call imported API via PLT at 0x15e23c
    _ZdlPv(...); // call imported API via PLT at 0x15e254
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15e264
    __stack_chk_fail(...); // call imported API via PLT at 0x15e284
}
