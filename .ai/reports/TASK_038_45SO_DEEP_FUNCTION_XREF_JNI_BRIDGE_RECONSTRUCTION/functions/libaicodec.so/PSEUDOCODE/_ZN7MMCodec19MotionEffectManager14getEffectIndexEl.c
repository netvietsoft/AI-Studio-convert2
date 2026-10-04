// Function: MMCodec::MotionEffectManager::getEffectIndex(long)
// RVA: 0x120e60, Size: 432 bytes
int64_t _ZN7MMCodec19MotionEffectManager14getEffectIndexEl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x120e88
    _ZNK7MMCodec12MotionEffect14getEffectParamEv(...); // call imported API via PLT at 0x120ec8
    _ZN7MMCodec12MotionEffect12getTimestampEl(...); // call imported API via PLT at 0x120ed4
    pthread_self(...); // call imported API via PLT at 0x120f3c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_85f56 = "[%s(%d)]:> [MotionEffectManager(%p)](%ld):> found no speed effect, timestamp:%lld"; // string xref
    const char* s_8461b = "getEffectIndex"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x120f6c
    pthread_self(...); // call imported API via PLT at 0x120f90
    const char* s_85fa8 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectManager(%p)](%ld):> found no speed effect, timestamp:%lld
"; // string xref
    const char* s_8461b = "getEffectIndex"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x120fbc
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x120fc4
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x120ff0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x121004
}
