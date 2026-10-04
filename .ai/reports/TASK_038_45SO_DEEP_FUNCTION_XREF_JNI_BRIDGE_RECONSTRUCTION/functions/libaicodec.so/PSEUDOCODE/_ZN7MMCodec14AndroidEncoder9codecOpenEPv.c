// Function: MMCodec::AndroidEncoder::codecOpen(void*)
// RVA: 0xf0114, Size: 524 bytes
int64_t _ZN7MMCodec14AndroidEncoder9codecOpenEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0xf012c
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xf0148
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8f91c = "[%s(%d)]:> %s java CodecOpen failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf0190
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_6bb55 = "%s/MTMV_AICodec: [%s(%d)]:> %s java CodecOpen failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf01d0
    return a0;
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_712cc = "[%s(%d)]:> %s state is invalid"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf022c
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_6bb24 = "%s/MTMV_AICodec: [%s(%d)]:> %s state is invalid
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf026c
    return a0;
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xf0290
    _ZdlPv(...); // call imported API via PLT at 0xf02b8
    _ZdlPv(...); // call imported API via PLT at 0xf02d0
    _ZdlPv(...); // call imported API via PLT at 0xf02e4
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xf02ec
    return a0;
    return a0;
}
