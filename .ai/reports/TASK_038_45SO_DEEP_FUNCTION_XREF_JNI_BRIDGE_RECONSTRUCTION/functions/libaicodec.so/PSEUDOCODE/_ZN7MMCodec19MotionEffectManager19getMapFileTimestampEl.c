// Function: MMCodec::MotionEffectManager::getMapFileTimestamp(long)
// RVA: 0x120c94, Size: 460 bytes
int64_t _ZN7MMCodec19MotionEffectManager19getMapFileTimestampEl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x120cb8
    _ZNK7MMCodec12MotionEffect14getEffectParamEv(...); // call imported API via PLT at 0x120cec
    _ZN7MMCodec12MotionEffect12getTimestampEl(...); // call imported API via PLT at 0x120cf8
    _ZN7MMCodec12MotionEffect16getFileTimestampEl(...); // call imported API via PLT at 0x120d3c
    _ZNK7MMCodec12MotionEffect14getEffectParamEv(...); // call imported API via PLT at 0x120d48
    pthread_self(...); // call imported API via PLT at 0x120d90
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_85f56 = "[%s(%d)]:> [MotionEffectManager(%p)](%ld):> found no speed effect, timestamp:%lld"; // string xref
    const char* s_6e8b7 = "getMapFileTimestamp"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x120dc0
    pthread_self(...); // call imported API via PLT at 0x120de4
    const char* s_85fa8 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectManager(%p)](%ld):> found no speed effect, timestamp:%lld
"; // string xref
    const char* s_6e8b7 = "getMapFileTimestamp"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x120e10
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x120e18
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x120e40
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x120e54
}
