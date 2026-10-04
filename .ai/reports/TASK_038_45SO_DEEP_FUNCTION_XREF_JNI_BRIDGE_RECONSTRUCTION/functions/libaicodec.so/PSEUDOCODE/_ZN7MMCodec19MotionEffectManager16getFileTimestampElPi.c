// Function: MMCodec::MotionEffectManager::getFileTimestamp(long, int*)
// RVA: 0x120abc, Size: 472 bytes
int64_t _ZN7MMCodec19MotionEffectManager16getFileTimestampElPi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x120ae8
    _ZNK7MMCodec12MotionEffect14getEffectParamEv(...); // call imported API via PLT at 0x120b28
    _ZN7MMCodec12MotionEffect12getTimestampEl(...); // call imported API via PLT at 0x120b34
    _ZN7MMCodec12MotionEffect16getFileTimestampEl(...); // call imported API via PLT at 0x120b78
    pthread_self(...); // call imported API via PLT at 0x120bc0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_85f56 = "[%s(%d)]:> [MotionEffectManager(%p)](%ld):> found no speed effect, timestamp:%lld"; // string xref
    const char* s_6e7f5 = "getFileTimestamp"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x120bf0
    pthread_self(...); // call imported API via PLT at 0x120c14
    const char* s_85fa8 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectManager(%p)](%ld):> found no speed effect, timestamp:%lld
"; // string xref
    const char* s_6e7f5 = "getFileTimestamp"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x120c40
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x120c48
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x120c74
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x120c88
}
