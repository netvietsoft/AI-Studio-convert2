// Function: MMCodec::AndroidEncoder::codecClose(MMCodec::EncodePerformanceInfo*)
// RVA: 0xf0320, Size: 248 bytes
int64_t _ZN7MMCodec14AndroidEncoder10codecCloseEPNS_21EncodePerformanceInfoE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0xf0330
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0xf0354
    return a0;
    const char* s_8f8d8 = "codecClose"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_90bfe = "[%s(%d)]:> [%s:%d]state error"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf03c0
    const char* s_8f8d8 = "codecClose"; // string xref
    const char* s_674b0 = "%s/MTMV_AICodec: [%s(%d)]:> [%s:%d]state error
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf0404
    return a0;
}
