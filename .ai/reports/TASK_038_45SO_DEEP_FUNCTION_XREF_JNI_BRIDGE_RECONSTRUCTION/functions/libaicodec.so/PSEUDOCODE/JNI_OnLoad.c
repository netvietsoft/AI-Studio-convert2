// Function: JNI_OnLoad
// RVA: 0x118454, Size: 496 bytes
int64_t JNI_OnLoad(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Z15aicodec_set_jvmP7_JavaVM(...); // call imported API via PLT at 0x118460
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0x118468
    _ZN7MMCodec10JniUtility4initEP7_JNIEnv(...); // call imported API via PLT at 0x118474
    _Z31register_aicodec_native_methodsP7_JNIEnv(...); // call imported API via PLT at 0x11847c
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8b58d = "[%s(%d)]:> aicodec_set_jvm failed"; // string xref
    const char* s_85e6b = "JNI_OnLoad"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1184d4
    const char* s_75090 = "%s/MTMV_AICodec: [%s(%d)]:> aicodec_set_jvm failed
"; // string xref
    const char* s_85e6b = "JNI_OnLoad"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x118510
    return a0;
    const char* s_85e6b = "JNI_OnLoad"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8a18f = "[%s(%d)]:> [%s]JniHelper::getEnv() get null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x118564
    const char* s_85e6b = "JNI_OnLoad"; // string xref
    const char* s_6ab57 = "%s/MTMV_AICodec: [%s(%d)]:> [%s]JniHelper::getEnv() get null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1185a4
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7655c = "[%s(%d)]:> register_aicodec_native_methods failed"; // string xref
    const char* s_85e6b = "JNI_OnLoad"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1185f4
    const char* s_845ae = "%s/MTMV_AICodec: [%s(%d)]:> register_aicodec_native_methods failed
"; // string xref
    const char* s_85e6b = "JNI_OnLoad"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x118630
    return a0;
}
