// Function: MMCodec::MotionEffectManager::getSpeed(long)
// RVA: 0x1208fc, Size: 448 bytes
int64_t _ZN7MMCodec19MotionEffectManager8getSpeedEl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x120920
    _ZNK7MMCodec12MotionEffect14getEffectParamEv(...); // call imported API via PLT at 0x120954
    _ZN7MMCodec12MotionEffect12getTimestampEl(...); // call imported API via PLT at 0x120960
    _ZN7MMCodec12MotionEffect16getFileTimestampEl(...); // call imported API via PLT at 0x1209a0
    _ZN7MMCodec12MotionEffect8getSpeedEl(...); // call imported API via PLT at 0x1209ac
    pthread_self(...); // call imported API via PLT at 0x1209e8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_85f56 = "[%s(%d)]:> [MotionEffectManager(%p)](%ld):> found no speed effect, timestamp:%lld"; // string xref
    const char* s_834e3 = "getSpeed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x120a18
    pthread_self(...); // call imported API via PLT at 0x120a40
    const char* s_85fa8 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectManager(%p)](%ld):> found no speed effect, timestamp:%lld
"; // string xref
    const char* s_834e3 = "getSpeed"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x120a6c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x120a74
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x120a9c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x120ab0
}
