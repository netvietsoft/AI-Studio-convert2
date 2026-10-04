// Function: MMCodec::AndroidMediaStream::readVideo(MMCodec::FrameData*, long, int)
// RVA: 0x1036e0, Size: 1476 bytes
int64_t _ZN7MMCodec18AndroidMediaStream9readVideoEPNS_9FrameDataEli(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x103720
    (*x8)(...); // indirect call at 0x103738
    _ZN7MMCodec10StreamBase19findSmoothSeekFrameEliRPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x10375c
    _ZN7MMCodec10StreamBase13findNextFrameEiRPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x103780
    _ZN7MMCodec10StreamBase13findBestFrameEliRPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x10379c
    _ZN7MMCodec9FrameData24getPresentationTimestampEv(...); // call imported API via PLT at 0x1037d0
    return a0;
    const char* s_9317e = "superfast";
    const char* s_931be = "zerolatency";
    void* g_660f8 = (void*)0x660f8; // global ref
    _ZN7MMCodec21getAICodecPixelFormatEi(...); // call imported API via PLT at 0x1038e4
    _ZN7MMCodec9FrameData20setInVideoDataFormatERKNS_12VideoParam_tENS_10StreamTypeE(...); // call imported API via PLT at 0x103904
    av_gettime_relative(...); // call imported API via PLT at 0x10390c
    _ZN7MMCodec9FrameData5writeEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x10391c
    _ZN7MMCodec9FrameData8transferEv(...); // call imported API via PLT at 0x103928
    av_get_time_base_q(...); // call imported API via PLT at 0x103940
    av_rescale_q(...); // call imported API via PLT at 0x103950
    _ZN7MMCodec9FrameData30setPrimalPresentationTimestampEl(...); // call imported API via PLT at 0x10395c
    av_gettime_relative(...); // call imported API via PLT at 0x103960
    const char* s_661e8 = "`Y "; // string xref
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x103998
    _ZNSt6__ndk112__hash_tableIPvNS_4hashIS1_EENS_8equal_toIS1_EENS_9allocatorIS1_EEE25__emplace_unique_key_argsIS1_JRKS1_EEENS_4pairINS_15__hash_iteratorIPNS_11__hash_nodeIS1_S1_EEEEbEERKT_DpOT0_(...); // call imported API via PLT at 0x1039ac
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1039b4
    pthread_self(...); // call imported API via PLT at 0x1039ec
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90fa0 = "[%s(%d)]:> [AndroidMediaStream(%p)](%ld):> frameData->setInVideoDataFormat failed %d"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x103a1c
    pthread_self(...); // call imported API via PLT at 0x103a40
    const char* s_80a63 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidMediaStream(%p)](%ld):> frameData->setInVideoDataFormat failed %d
"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    pthread_self(...); // call imported API via PLT at 0x103a8c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_83037 = "[%s(%d)]:> [AndroidMediaStream(%p)](%ld):> frameData->write failed %d"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x103abc
    pthread_self(...); // call imported API via PLT at 0x103ae0
    const char* s_7164d = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidMediaStream(%p)](%ld):> frameData->write failed %d
"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    pthread_self(...); // call imported API via PLT at 0x103b2c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8fa58 = "[%s(%d)]:> [AndroidMediaStream(%p)](%ld):> frameData->transfer failed %d"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x103b5c
    pthread_self(...); // call imported API via PLT at 0x103b80
    const char* s_8cdd4 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidMediaStream(%p)](%ld):> frameData->transfer failed %d
"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x103bac
    _ZN7MMCodec13ThreadContext7isValidEv(...); // call imported API via PLT at 0x103bc4
    pthread_self(...); // call imported API via PLT at 0x103bf4
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0x103c04
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8307d = "[%s(%d)]:> [AndroidMediaStream(%p)](%ld):> decode thread state is invalid %d, return eof"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x103c34
    pthread_self(...); // call imported API via PLT at 0x103c58
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0x103c68
    const char* s_830d6 = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidMediaStream(%p)](%ld):> decode thread state is invalid %d, return eof
"; // string xref
    const char* s_84275 = "readVideo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x103c94
    __stack_chk_fail(...); // call imported API via PLT at 0x103ca0
}
