// Function: MMCodec::SpeedEffectManager::getTimestamp(long)
// RVA: 0x11a604, Size: 568 bytes
int64_t _ZN7MMCodec18SpeedEffectManager12getTimestampEl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x11a638
    _ZN7MMCodec18SpeedEffectManager33_findSpeedEffectWithFileTimestampEl(...); // call imported API via PLT at 0x11a644
    (*x8)(...); // indirect call at 0x11a664
    (*x8)(...); // indirect call at 0x11a67c
    pthread_self(...); // call imported API via PLT at 0x11a6b0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7658e = "[%s(%d)]:> [SpeedEffectManager(%p)](%ld):> found no speed effect, file timestamp:%lld"; // string xref
    const char* s_7baa9 = "getTimestamp"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11a6e0
    pthread_self(...); // call imported API via PLT at 0x11a704
    const char* s_88a8d = "%s/MTMV_AICodec: [%s(%d)]:> [SpeedEffectManager(%p)](%ld):> found no speed effect, file timestamp:%lld
"; // string xref
    const char* s_7baa9 = "getTimestamp"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x11a730
    pthread_self(...); // call imported API via PLT at 0x11a758
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_80f1c = "[%s(%d)]:> [SpeedEffectManager(%p)](%ld):> check fileTimestamp:%lld failed"; // string xref
    const char* s_7baa9 = "getTimestamp"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11a788
    pthread_self(...); // call imported API via PLT at 0x11a7ac
    const char* s_8a4de = "%s/MTMV_AICodec: [%s(%d)]:> [SpeedEffectManager(%p)](%ld):> check fileTimestamp:%lld failed
"; // string xref
    const char* s_7baa9 = "getTimestamp"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x11a7d8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x11a7e4
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x11a81c
    __stack_chk_fail(...); // call imported API via PLT at 0x11a838
}
