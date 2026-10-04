// Function: MMCodec::SpeedEffectManager::getAudio(MMCodec::AudioFrame*)
// RVA: 0x11a83c, Size: 956 bytes
int64_t _ZN7MMCodec18SpeedEffectManager8getAudioEPNS_10AudioFrameE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x11a87c
    _ZN7MMCodec18SpeedEffectManager33_findSpeedEffectWithFileTimestampEl(...); // call imported API via PLT at 0x11a894
    (*x8)(...); // indirect call at 0x11a8f0
    (*x8)(...); // indirect call at 0x11a908
    (*x9)(...); // indirect call at 0x11a938
    (*x8)(...); // indirect call at 0x11a954
    pthread_self(...); // call imported API via PLT at 0x11a980
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x11a990
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_791e0 = "[%s(%d)]:> [SpeedEffectManager(%p)](%ld):> av_get_bytes_per_sample failed %d %d->%s"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11a9c8
    pthread_self(...); // call imported API via PLT at 0x11a9ec
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x11a9fc
    const char* s_77f69 = "%s/MTMV_AICodec: [%s(%d)]:> [SpeedEffectManager(%p)](%ld):> av_get_bytes_per_sample failed %d %d->%s
"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x11aa30
    pthread_self(...); // call imported API via PLT at 0x11aa5c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72ce9 = "[%s(%d)]:> [SpeedEffectManager(%p)](%ld):> found no speed effect, file audio clock:%lld"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11aa8c
    pthread_self(...); // call imported API via PLT at 0x11aab0
    const char* s_8b5af = "%s/MTMV_AICodec: [%s(%d)]:> [SpeedEffectManager(%p)](%ld):> found no speed effect, file audio clock:%lld
"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x11aadc
    pthread_self(...); // call imported API via PLT at 0x11ab04
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_80f1c = "[%s(%d)]:> [SpeedEffectManager(%p)](%ld):> check fileTimestamp:%lld failed"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11ab34
    pthread_self(...); // call imported API via PLT at 0x11ab58
    const char* s_8a4de = "%s/MTMV_AICodec: [%s(%d)]:> [SpeedEffectManager(%p)](%ld):> check fileTimestamp:%lld failed
"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x11ab84
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x11ab90
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x11abd8
    __stack_chk_fail(...); // call imported API via PLT at 0x11abf4
}
