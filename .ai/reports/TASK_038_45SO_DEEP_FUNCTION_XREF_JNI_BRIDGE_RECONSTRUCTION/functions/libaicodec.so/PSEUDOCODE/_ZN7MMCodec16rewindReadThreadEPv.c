// Function: MMCodec::rewindReadThread(void*)
// RVA: 0x15e768, Size: 3772 bytes
int64_t _ZN7MMCodec16rewindReadThreadEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x15e7b0
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0x15e7b4
    _ZN7MMCodec18MediaHandleContext15findKeyFramePosElli(...); // call imported API via PLT at 0x15e7f4
    avformat_index_get_entries_count(...); // call imported API via PLT at 0x15e808
    avformat_index_get_entry(...); // call imported API via PLT at 0x15e82c
    pthread_self(...); // call imported API via PLT at 0x15e878
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_734b4 = "[%s(%d)]:> (%ld):> input parameter is null"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15e8a0
    pthread_self(...); // call imported API via PLT at 0x15e8bc
    const char* s_6ee14 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> input parameter is null
"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15e8e0
    pthread_self(...); // call imported API via PLT at 0x15e90c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_813bc = "[%s(%d)]:> (%ld):> acquireAVPacket is null"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15e934
    pthread_self(...); // call imported API via PLT at 0x15e950
    const char* s_734df = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> acquireAVPacket is null
"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15e974
    pthread_self(...); // call imported API via PLT at 0x15e990
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7351c = "[%s(%d)]:> (%ld):> thread exit!"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15e9b8
    return a0;
    pthread_self(...); // call imported API via PLT at 0x15ea14
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8934a = "[%s(%d)]:> (%ld):> can't find key frame index entry, fail to rewind"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15ea3c
    pthread_self(...); // call imported API via PLT at 0x15ea5c
    const char* s_76cc4 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> can't find key frame index entry, fail to rewind
"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    av_seek_frame(...); // call imported API via PLT at 0x15eabc
    _ZN7MMCodec18MediaHandleContext17getKeyFrameTablesEi(...); // call imported API via PLT at 0x15eacc
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x15eadc
    av_get_time_base_q(...); // call imported API via PLT at 0x15eb18
    av_rescale_q(...); // call imported API via PLT at 0x15eb28
    pthread_self(...); // call imported API via PLT at 0x15eb6c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6eeea = "[%s(%d)]:> (%ld):> fail to seek frame
"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15eb94
    pthread_self(...); // call imported API via PLT at 0x15ebb0
    const char* s_76d1a = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> fail to seek frame

"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    pthread_self(...); // call imported API via PLT at 0x15ebfc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_83a7e = "[%s(%d)]:> (%ld):> [>>>start]Media:%s, MediaHandleContext:%p, video:%d"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15ec38
    pthread_self(...); // call imported API via PLT at 0x15ec84
    const char* s_8dc3d = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> [>>>start]Media:%s, MediaHandleContext:%p, video:%d
"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15ecbc
    av_packet_unref(...); // call imported API via PLT at 0x15ece8
    pthread_self(...); // call imported API via PLT at 0x15ed1c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82928 = "[%s(%d)]:> (%ld):> @@@Seek req mode=%d......seek time [%lld] nums %d
"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15ed54
    pthread_self(...); // call imported API via PLT at 0x15ed70
    const char* s_6c60d = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> @@@Seek req mode=%d......seek time [%lld] nums %d

"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15eda4
    av_get_time_base_q(...); // call imported API via PLT at 0x15edd0
    av_rescale_q(...); // call imported API via PLT at 0x15ede0
    _ZN7MMCodec18MediaHandleContext15findKeyFramePosElli(...); // call imported API via PLT at 0x15ee00
    avformat_index_get_entries_count(...); // call imported API via PLT at 0x15ee0c
    avformat_index_get_entry(...); // call imported API via PLT at 0x15ee30
    av_seek_frame(...); // call imported API via PLT at 0x15ee94
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15eea8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15eecc
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x15eef0
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x15ef18
    _ZN7MMCodec11PacketQueue8tagFlushEv(...); // call imported API via PLT at 0x15ef24
    _ZN7MMCodec11PacketQueue5flushEv(...); // call imported API via PLT at 0x15ef2c
    _ZN7MMCodec11PacketQueue6setEofEb(...); // call imported API via PLT at 0x15ef38
    _ZN7MMCodec13AICodecGlobal11getInstanceEv(...); // call imported API via PLT at 0x15ef3c
    _ZN7MMCodec13AICodecGlobal11flushPacketEv(...); // call imported API via PLT at 0x15ef40
    _ZN7MMCodec11PacketQueue3putEP8AVPacketbbi(...); // call imported API via PLT at 0x15ef58
    av_packet_unref(...); // call imported API via PLT at 0x15ef88
    av_read_frame(...); // call imported API via PLT at 0x15ef94
    av_packet_unref(...); // call imported API via PLT at 0x15efe0
    av_get_time_base_q(...); // call imported API via PLT at 0x15f008
    av_rescale_q(...); // call imported API via PLT at 0x15f018
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x15f054
    _ZN7MMCodec11PacketQueue3putEP8AVPacketbbi(...); // call imported API via PLT at 0x15f0e0
    _ZN7MMCodec12initAVPacketEP8AVPacket(...); // call imported API via PLT at 0x15f0e8
    av_packet_unref(...); // call imported API via PLT at 0x15f0f8
    _ZN7MMCodec18MediaHandleContext9rewindEOFEi(...); // call imported API via PLT at 0x15f114
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x15f128
    _ZN7MMCodec11PacketQueue13putNullPacketEi(...); // call imported API via PLT at 0x15f134
    _ZN7MMCodec11PacketQueue6setEofEb(...); // call imported API via PLT at 0x15f140
    pthread_self(...); // call imported API via PLT at 0x15f164
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8dbf9 = "[%s(%d)]:> (%ld):> read eof, sleep wait for seek... _mediaHandle:%p"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15f190
    pthread_self(...); // call imported API via PLT at 0x15f1ac
    const char* s_6fea0 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> read eof, sleep wait for seek... _mediaHandle:%p
"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15f1d4
    _ZN7MMCodec18MediaHandleContext15waitSeekRequestEv(...); // call imported API via PLT at 0x15f1dc
    pthread_self(...); // call imported API via PLT at 0x15f200
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_91868 = "[%s(%d)]:> (%ld):> read eof, sleep wait for seek end _mediaHandle:%p"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15f22c
    pthread_self(...); // call imported API via PLT at 0x15f248
    const char* s_68009 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> read eof, sleep wait for seek end _mediaHandle:%p
"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15f270
    _ZN7MMCodec18MediaHandleContext15nextKeyFramePosERi(...); // call imported API via PLT at 0x15f27c
    av_seek_frame(...); // call imported API via PLT at 0x15f298
    av_packet_unref(...); // call imported API via PLT at 0x15f2d0
    av_packet_unref(...); // call imported API via PLT at 0x15f330
    pthread_self(...); // call imported API via PLT at 0x15f394
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6eeea = "[%s(%d)]:> (%ld):> fail to seek frame
"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15f3bc
    pthread_self(...); // call imported API via PLT at 0x15f3dc
    const char* s_76d1a = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> fail to seek frame

"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    pthread_self(...); // call imported API via PLT at 0x15f424
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7857d = "[%s(%d)]:> (%ld):> fail to read frame
"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15f44c
    pthread_self(...); // call imported API via PLT at 0x15f468
    const char* s_68060 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> fail to read frame

"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    pthread_self(...); // call imported API via PLT at 0x15f4b0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6ef11 = "[%s(%d)]:> (%ld):> didn't find key frame index entry, fail to rewind
"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15f4d8
    pthread_self(...); // call imported API via PLT at 0x15f4f4
    const char* s_76d53 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> didn't find key frame index entry, fail to rewind

"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    pthread_self(...); // call imported API via PLT at 0x15f53c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6eeea = "[%s(%d)]:> (%ld):> fail to seek frame
"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15f564
    pthread_self(...); // call imported API via PLT at 0x15f580
    const char* s_76d1a = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> fail to seek frame

"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15f5a4
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x15f5ac
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0x15f5b4
    pthread_self(...); // call imported API via PLT at 0x15f5e8
    const char* s_7d440 = "%s/MTMV_AICodec: [%s(%d)]:> (%ld):> thread exit!
"; // string xref
    const char* s_83a6d = "rewindReadThread"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15f60c
    __stack_chk_fail(...); // call imported API via PLT at 0x15f620
}
