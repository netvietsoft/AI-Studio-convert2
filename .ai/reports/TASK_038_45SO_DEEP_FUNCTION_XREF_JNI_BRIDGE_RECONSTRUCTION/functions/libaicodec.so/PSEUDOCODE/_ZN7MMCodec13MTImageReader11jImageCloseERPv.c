// Function: MMCodec::MTImageReader::jImageClose(void*&)
// RVA: 0x10950c, Size: 248 bytes
int64_t _ZN7MMCodec13MTImageReader11jImageCloseERPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0x109534
    _ZN7_JNIEnv14CallVoidMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0x109544
    (*x8)(...); // indirect call at 0x109558
    const char* s_77e25 = "jImageClose"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ceee = "[%s(%d)]:> [%s]MTImageReader didn't initialized"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1095a4
    const char* s_77e25 = "jImageClose"; // string xref
    const char* s_80ca1 = "%s/MTMV_AICodec: [%s(%d)]:> [%s]MTImageReader didn't initialized
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1095f0
    return a0;
}
