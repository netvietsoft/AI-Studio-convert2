// Function: MMCodec::FFmpegMediaStream::readVideo(MMCodec::FrameData*, long, int)
// RVA: 0x13d050, Size: 2136 bytes
int64_t _ZN7MMCodec17FFmpegMediaStream9readVideoEPNS_9FrameDataEli(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x13d0a8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6fd1a = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> media type error %d"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13d0d8
    pthread_self(...); // call imported API via PLT at 0x13d0fc
    const char* s_78281 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> media type error %d
"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13d128
    (*x8)(...); // indirect call at 0x13d148
    return a0;
    _ZN7MMCodec17FFmpegMediaStream6decodeEv(...); // call imported API via PLT at 0x13d18c
    _ZN7MMCodec17FFmpegMediaStream6decodeEv(...); // call imported API via PLT at 0x13d19c
    _ZN7MMCodec17FFmpegMediaStream6decodeEv(...); // call imported API via PLT at 0x13d1ac
    _ZN7MMCodec17FFmpegMediaStream6decodeEv(...); // call imported API via PLT at 0x13d1bc
    _ZN7MMCodec17FFmpegMediaStream6decodeEv(...); // call imported API via PLT at 0x13d1cc
    _ZN7MMCodec17FFmpegMediaStream6decodeEv(...); // call imported API via PLT at 0x13d1dc
    (*x8)(...); // indirect call at 0x13d1f0
    _ZN7MMCodec10StreamBase19findSmoothSeekFrameEliRPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x13d218
    _ZN7MMCodec10StreamBase13findNextFrameEiRPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x13d240
    _ZN7MMCodec10StreamBase13findBestFrameEliRPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x13d260
    _ZN7MMCodec9FrameData24getPresentationTimestampEv(...); // call imported API via PLT at 0x13d2a0
    pthread_self(...); // call imported API via PLT at 0x13d2dc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6b19a = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> can't find %lld frame"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13d30c
    pthread_self(...); // call imported API via PLT at 0x13d330
    const char* s_87603 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> can't find %lld frame
"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13d35c
    _ZN7MMCodec13ThreadContext7isValidEv(...); // call imported API via PLT at 0x13d37c
    pthread_self(...); // call imported API via PLT at 0x13d3ac
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0x13d3bc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_68c72 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> decode thread state is invalid %d, return eof"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13d3ec
    pthread_self(...); // call imported API via PLT at 0x13d410
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0x13d420
    const char* s_6b130 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> decode thread state is invalid %d, return eof
"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    const char* s_943a6 = "superfast";
    const char* s_943e6 = "zerolatency";
    void* g_660f8 = (void*)0x660f8; // global ref
    _ZN7MMCodec19getVideoOuterFormatE13AVPixelFormat(...); // call imported API via PLT at 0x13d598
    _ZN7MMCodec9FrameData20setInVideoDataFormatERKNS_12VideoParam_tENS_10StreamTypeE(...); // call imported API via PLT at 0x13d5f8
    av_gettime_relative(...); // call imported API via PLT at 0x13d600
    _ZN7MMCodec9FrameData5writeEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x13d610
    _ZN7MMCodec9FrameData8transferEv(...); // call imported API via PLT at 0x13d61c
    av_get_time_base_q(...); // call imported API via PLT at 0x13d634
    av_rescale_q(...); // call imported API via PLT at 0x13d644
    _ZN7MMCodec9FrameData30setPrimalPresentationTimestampEl(...); // call imported API via PLT at 0x13d650
    av_gettime_relative(...); // call imported API via PLT at 0x13d654
    const char* s_661e8 = "`Y "; // string xref
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x13d68c
    void* g_201008 = (void*)0x201008; // global ref
    void* g_201008 = (void*)0x201008; // global ref
    _ZNSt6__ndk112__hash_tableIPvNS_4hashIS1_EENS_8equal_toIS1_EENS_9allocatorIS1_EEE25__emplace_unique_key_argsIS1_JRKS1_EEENS_4pairINS_15__hash_iteratorIPNS_11__hash_nodeIS1_S1_EEEEbEERKT_DpOT0_(...); // call imported API via PLT at 0x13d6a0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x13d6a8
    pthread_self(...); // call imported API via PLT at 0x13d6d8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7d085 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->setInVideoDataFormat failed %d"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13d708
    pthread_self(...); // call imported API via PLT at 0x13d72c
    const char* s_7e200 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->setInVideoDataFormat failed %d
"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    pthread_self(...); // call imported API via PLT at 0x13d778
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86438 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->write failed %d"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13d7a8
    pthread_self(...); // call imported API via PLT at 0x13d7cc
    const char* s_6b1da = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->write failed %d
"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    pthread_self(...); // call imported API via PLT at 0x13d818
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_75320 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->transfer failed %d"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13d848
    pthread_self(...); // call imported API via PLT at 0x13d86c
    const char* s_767f1 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> frameData->transfer failed %d
"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13d898
    __stack_chk_fail(...); // call imported API via PLT at 0x13d8a4
}
