// Function: MMCodec::AICodecGlobal::getHardware()
// RVA: 0x12ebb4, Size: 608 bytes
int64_t _ZN7MMCodec13AICodecGlobal11getHardwareEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_20ae40 = (void*)0x20ae40; // global ref
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0x12ebf8
    void* g_20ae18 = (void*)0x20ae18; // global ref
    _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(...); // call imported API via PLT at 0x12ec30
    const char* s_8a5ce = "getHardwareLowerCase"; // string xref
    const char* s_69932 = "()Ljava/lang/String;"; // string xref
    (*x8)(...); // indirect call at 0x12ec58
    _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(...); // call imported API via PLT at 0x12ec70
    _ZN9JniHelper14jstring2stringEP8_jstring(...); // call imported API via PLT at 0x12ec80
    _ZdlPv(...); // call imported API via PLT at 0x12ec98
    (*x8)(...); // indirect call at 0x12ecbc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ed6c = "[%s(%d)]:> %s"; // string xref
    const char* s_8112e = "getHardware"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12ed0c
    const char* s_8110e = "%s/MTMV_AICodec: [%s(%d)]:> %s
"; // string xref
    const char* s_8112e = "getHardware"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12ed58
    void* g_20ae40 = (void*)0x20ae40; // global ref
    return a0;
    void* g_20ae18 = (void*)0x20ae18; // global ref
    __cxa_guard_acquire(...); // call imported API via PLT at 0x12ed94
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x12eda8
    void* g_20ae10 = (void*)0x20ae10; // global ref
    __cxa_guard_release(...); // call imported API via PLT at 0x12edbc
    void* g_20ae18 = (void*)0x20ae18; // global ref
    __cxa_guard_abort(...); // call imported API via PLT at 0x12edd0
    sub_CEBC4(...); // call internal func at 0x12edd8
    (*x8)(...); // indirect call at 0x12edf0
    __stack_chk_fail(...); // call imported API via PLT at 0x12ee0c
    sub_CEBC4(...); // call internal func at 0x12ee10
}
