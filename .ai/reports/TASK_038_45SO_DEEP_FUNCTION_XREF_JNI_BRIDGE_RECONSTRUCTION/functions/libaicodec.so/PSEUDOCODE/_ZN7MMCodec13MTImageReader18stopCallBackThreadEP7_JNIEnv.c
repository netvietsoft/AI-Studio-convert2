// Function: MMCodec::MTImageReader::stopCallBackThread(_JNIEnv*)
// RVA: 0x108c50, Size: 372 bytes
int64_t _ZN7MMCodec13MTImageReader18stopCallBackThreadEP7_JNIEnv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0x108c7c
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x108c90
    const char* s_8e8b1 = "quit"; // string xref
    const char* s_7a5da = "()Z"; // string xref
    (*x8)(...); // indirect call at 0x108cb8
    _ZN7_JNIEnv17CallBooleanMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0x108cc8
    const char* s_7efe5 = "join"; // string xref
    const char* s_6bad5 = "()V"; // string xref
    (*x8)(...); // indirect call at 0x108cf4
    _ZN7_JNIEnv14CallVoidMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0x108d04
    (*x8)(...); // indirect call at 0x108d18
    const char* s_7a5c7 = "stopCallBackThread"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ceee = "[%s(%d)]:> [%s]MTImageReader didn't initialized"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x108d64
    const char* s_7a5c7 = "stopCallBackThread"; // string xref
    const char* s_80ca1 = "%s/MTMV_AICodec: [%s(%d)]:> [%s]MTImageReader didn't initialized
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x108db0
    return a0;
}
