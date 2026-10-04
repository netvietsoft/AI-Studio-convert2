// Function: MMCodec::FFmpegMediaStream::readAudio(MMCodec::FrameData*, int)
// RVA: 0x13a50c, Size: 5036 bytes
int64_t _ZN7MMCodec17FFmpegMediaStream9readAudioEPNS_9FrameDataEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x13a55c
    _ZN7MMCodec17FFmpegMediaStream6decodeEv(...); // call imported API via PLT at 0x13a578
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_79683 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> This is not same serial<%d--%d> pts %lld"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    const char* s_836f4 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> This is not same serial<%d--%d> pts %lld
"; // string xref
    (*x8)(...); // indirect call at 0x13a5cc
    _ZN7MMCodec10FrameQueue10getEofFlagEv(...); // call imported API via PLT at 0x13a5d8
    _ZN7MMCodec10FrameQueue11nbRemainingEv(...); // call imported API via PLT at 0x13a5e4
    _ZN7MMCodec10FrameQueue12peekReadableEii(...); // call imported API via PLT at 0x13a5fc
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x13a61c
    pthread_self(...); // call imported API via PLT at 0x13a648
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x13a660
    __android_log_print(...); // call imported API via PLT at 0x13a694
    pthread_self(...); // call imported API via PLT at 0x13a6b8
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x13a6d0
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13a704
    av_frame_unref(...); // call imported API via PLT at 0x13a728
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x13a730
    av_frame_ref(...); // call imported API via PLT at 0x13a744
    pthread_self(...); // call imported API via PLT at 0x13a7ec
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6fd1a = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> media type error %d"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13a81c
    pthread_self(...); // call imported API via PLT at 0x13a840
    const char* s_78281 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> media type error %d
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13a86c
    return a0;
    pthread_self(...); // call imported API via PLT at 0x13a8c4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7bdaf = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> can't get audio frame!"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13a8f0
    pthread_self(...); // call imported API via PLT at 0x13a918
    const char* s_87565 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> can't get audio frame!
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13a940
    _ZN7MMCodec13ThreadContext7isValidEv(...); // call imported API via PLT at 0x13a958
    pthread_self(...); // call imported API via PLT at 0x13a988
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0x13a998
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_68c72 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> decode thread state is invalid %d, return eof"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13a9c8
    pthread_self(...); // call imported API via PLT at 0x13a9ec
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0x13a9fc
    const char* s_6b130 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> decode thread state is invalid %d, return eof
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    pthread_self(...); // call imported API via PLT at 0x13aa50
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7bdaf = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> can't get audio frame!"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13aa7c
    pthread_self(...); // call imported API via PLT at 0x13aaa0
    const char* s_87565 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> can't get audio frame!
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13aac8
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x13aad4
    _ZN7MMCodec10FrameQueue10getEofFlagEv(...); // call imported API via PLT at 0x13aae4
    _ZN7MMCodec11PacketQueue5isEofEv(...); // call imported API via PLT at 0x13aafc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8641c = "[%s(%d)]:> audio stream eof"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13ab40
    const char* s_6b102 = "%s/MTMV_AICodec: [%s(%d)]:> audio stream eof
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13ab7c
    av_frame_unref(...); // call imported API via PLT at 0x13ab88
    _ZN7MMCodec9FrameData5writeEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x13ab98
    _ZN7MMCodec9FrameData8transferEv(...); // call imported API via PLT at 0x13aba0
    pthread_self(...); // call imported API via PLT at 0x13abcc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67e10 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> FrameData transfer error, %d"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13abfc
    pthread_self(...); // call imported API via PLT at 0x13ac20
    const char* s_9152c = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> FrameData transfer error, %d
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13ac4c
    _ZN7MMCodec19getAudioOuterFormatE14AVSampleFormat(...); // call imported API via PLT at 0x13ac8c
    _ZN7MMCodec9FrameData20setInAudioDataFormatERKNS_12AudioParam_tE(...); // call imported API via PLT at 0x13aca0
    av_samples_get_buffer_size(...); // call imported API via PLT at 0x13acc4
    pthread_self(...); // call imported API via PLT at 0x13acfc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_79638 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Realloc audio data buffer(%d-%d)"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13ad30
    pthread_self(...); // call imported API via PLT at 0x13ad54
    const char* s_83697 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Realloc audio data buffer(%d-%d)
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13ad84
    av_fast_malloc(...); // call imported API via PLT at 0x13ad98
    pthread_self(...); // call imported API via PLT at 0x13adc8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ee24 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Alloc media data error!"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13adf4
    pthread_self(...); // call imported API via PLT at 0x13ae18
    const char* s_88e55 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Alloc media data error!
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    pthread_self(...); // call imported API via PLT at 0x13ae60
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_71b33 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> get null frame"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13ae8c
    pthread_self(...); // call imported API via PLT at 0x13aeb4
    const char* s_875b8 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> get null frame
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    pthread_self(...); // call imported API via PLT at 0x13af00
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_900b4 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->setInAudioDataFormat failed"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13af2c
    pthread_self(...); // call imported API via PLT at 0x13af5c
    const char* s_88df2 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->setInAudioDataFormat failed
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    memset(...); // call imported API via PLT at 0x13af98
    av_frame_unref(...); // call imported API via PLT at 0x13afac
    _ZN7MMCodec17FFmpegMediaStream14findDelayIndexEP7AVFrame(...); // call imported API via PLT at 0x13afb8
    void* g_2010bb = (void*)0x2010bb; // global ref
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x13aff0
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x13b008
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x13b030
    av_samples_fill_arrays(...); // call imported API via PLT at 0x13b05c
    av_channel_layout_uninit(...); // call imported API via PLT at 0x13b080
    void* g_201198 = (void*)0x201198; // global ref
    av_channel_layout_copy(...); // call imported API via PLT at 0x13b09c
    const char* s_6fd58 = "Failed to copy channel layout.
"; // string xref
    void* g_202130 = (void*)0x202130; // global ref
    fwrite(...); // call imported API via PLT at 0x13b0c0
    _ZN7MMCodec9FrameData5writeEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x13b0f0
    _ZN7MMCodec9FrameData8transferEv(...); // call imported API via PLT at 0x13b0fc
    pthread_self(...); // call imported API via PLT at 0x13b130
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x13b13c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_68c27 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> av_samples_fill_arrays failed %s"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13b16c
    pthread_self(...); // call imported API via PLT at 0x13b190
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x13b19c
    const char* s_67d71 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> av_samples_fill_arrays failed %s
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13b1c8
    pthread_self(...); // call imported API via PLT at 0x13b1f4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_84858 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> allocAVFrame failed"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13b220
    pthread_self(...); // call imported API via PLT at 0x13b248
    const char* s_7e1b0 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> allocAVFrame failed
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    pthread_self(...); // call imported API via PLT at 0x13b294
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67dce = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->write failed"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13b2c0
    pthread_self(...); // call imported API via PLT at 0x13b2ec
    const char* s_7f435 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->write failed
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    pthread_self(...); // call imported API via PLT at 0x13b334
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_84858 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> allocAVFrame failed"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13b360
    pthread_self(...); // call imported API via PLT at 0x13b384
    const char* s_7e1b0 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> allocAVFrame failed
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13b3ac
    pthread_self(...); // call imported API via PLT at 0x13b3e4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67e10 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> FrameData transfer error, %d"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13b414
    pthread_self(...); // call imported API via PLT at 0x13b438
    const char* s_9152c = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> FrameData transfer error, %d
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    pthread_self(...); // call imported API via PLT at 0x13b484
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ee66 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> drop audio frame %lld"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13b4b4
    pthread_self(...); // call imported API via PLT at 0x13b4d8
    const char* s_8bab4 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> drop audio frame %lld
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13b508
    (*x8)(...); // indirect call at 0x13b51c
    av_get_time_base_q(...); // call imported API via PLT at 0x13b5f8
    av_rescale_q(...); // call imported API via PLT at 0x13b60c
    av_frame_unref(...); // call imported API via PLT at 0x13b628
    (*x8)(...); // indirect call at 0x13b63c
    _ZN7MMCodec19getAudioOuterFormatE14AVSampleFormat(...); // call imported API via PLT at 0x13b668
    _ZN7MMCodec9FrameData20setInAudioDataFormatERKNS_12AudioParam_tE(...); // call imported API via PLT at 0x13b67c
    _ZN7MMCodec9FrameData5writeEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x13b68c
    _ZN7MMCodec9FrameData8transferEv(...); // call imported API via PLT at 0x13b69c
    pthread_self(...); // call imported API via PLT at 0x13b6c8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67e10 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> FrameData transfer error, %d"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13b6f8
    pthread_self(...); // call imported API via PLT at 0x13b71c
    const char* s_9152c = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> FrameData transfer error, %d
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13b748
    pthread_self(...); // call imported API via PLT at 0x13b77c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_900b4 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->setInAudioDataFormat failed"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13b7a8
    pthread_self(...); // call imported API via PLT at 0x13b7d4
    const char* s_88df2 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->setInAudioDataFormat failed
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    pthread_self(...); // call imported API via PLT at 0x13b820
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67dce = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->write failed"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13b84c
    pthread_self(...); // call imported API via PLT at 0x13b878
    const char* s_7f435 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->write failed
"; // string xref
    const char* s_7d07b = "readAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13b8a0
    __stack_chk_fail(...); // call imported API via PLT at 0x13b8b4
}
