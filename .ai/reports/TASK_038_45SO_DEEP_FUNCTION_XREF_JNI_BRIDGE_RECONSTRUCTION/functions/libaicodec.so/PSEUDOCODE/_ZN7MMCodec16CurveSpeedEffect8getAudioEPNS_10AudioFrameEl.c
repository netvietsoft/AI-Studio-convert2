// Function: MMCodec::CurveSpeedEffect::getAudio(MMCodec::AudioFrame*, long)
// RVA: 0x11c298, Size: 1660 bytes
int64_t _ZN7MMCodec16CurveSpeedEffect8getAudioEPNS_10AudioFrameEl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN6rtSOLA5CSOLA14getNextSamplesEfi(...); // call imported API via PLT at 0x11c2f0
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0x11c300
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x11c324
    _ZN6rtSOLA5CSOLA11SOLAProcessEPsiPKsii(...); // call imported API via PLT at 0x11c340
    pthread_self(...); // call imported API via PLT at 0x11c388
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x11c398
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_765ed = "[%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> av_get_bytes_per_sample failed %d %d->%s"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11c3d0
    pthread_self(...); // call imported API via PLT at 0x11c3f4
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x11c404
    const char* s_750d0 = "%s/MTMV_AICodec: [%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> av_get_bytes_per_sample failed %d %d->%s
"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x11c438
    (*x8)(...); // indirect call at 0x11c470
    _ZN7MMCodec10MTResample35getNextOutBufferSizeWithWantSamplesEi(...); // call imported API via PLT at 0x11c484
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0x11c49c
    _ZN7MMCodec10MTResample8resampleEPhmS1_Rmi(...); // call imported API via PLT at 0x11c4bc
    pthread_self(...); // call imported API via PLT at 0x11c4fc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7f187 = "[%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> realloc failed"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11c528
    pthread_self(...); // call imported API via PLT at 0x11c54c
    const char* s_6fa65 = "%s/MTMV_AICodec: [%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> realloc failed
"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x11c574
    pthread_self(...); // call imported API via PLT at 0x11c5a0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_80ff5 = "[%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> resamper is null"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11c5cc
    pthread_self(...); // call imported API via PLT at 0x11c5f0
    const char* s_912c9 = "%s/MTMV_AICodec: [%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> resamper is null
"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x11c618
    pthread_self(...); // call imported API via PLT at 0x11c64c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6aee7 = "[%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> Time scale process failed<%d> !"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11c67c
    pthread_self(...); // call imported API via PLT at 0x11c6a0
    const char* s_8b66c = "%s/MTMV_AICodec: [%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> Time scale process failed<%d> !
"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x11c6cc
    pthread_self(...); // call imported API via PLT at 0x11c6f8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8102f = "[%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> resamper->getNextOutBufferSizeWithWantSamples %zu invalid"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11c728
    pthread_self(...); // call imported API via PLT at 0x11c74c
    const char* s_6e842 = "%s/MTMV_AICodec: [%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> resamper->getNextOutBufferSizeWithWantSamples %zu invalid
"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x11c778
    pthread_self(...); // call imported API via PLT at 0x11c7a4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7f187 = "[%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> realloc failed"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11c7d0
    pthread_self(...); // call imported API via PLT at 0x11c7f4
    const char* s_6fa65 = "%s/MTMV_AICodec: [%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> realloc failed
"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    pthread_self(...); // call imported API via PLT at 0x11c858
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_75134 = "[%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> resample process failed<%d> !"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11c888
    pthread_self(...); // call imported API via PLT at 0x11c8ac
    const char* s_7f1bf = "%s/MTMV_AICodec: [%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> resample process failed<%d> !
"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x11c8d8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x11c910
}
