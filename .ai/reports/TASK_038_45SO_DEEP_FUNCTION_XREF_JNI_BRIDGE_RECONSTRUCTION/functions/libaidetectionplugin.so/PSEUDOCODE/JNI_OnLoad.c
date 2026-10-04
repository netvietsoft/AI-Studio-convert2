// Function: JNI_OnLoad
// RVA: 0x408f4, Size: 492 bytes
int64_t JNI_OnLoad(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_30045 = "MTMVCore";
    const char* s_31439 = "[%s(%d)]:> [hrs] plugin JNI_OnLoad
"; // string xref
    const char* s_31393 = "JNI_OnLoad"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x40944
    _Z27ai_detection_plugin_set_jvmP7_JavaVM(...); // call imported API via PLT at 0x4094c
    _ZN17MMDetectionPlugin9JniHelper6getEnvEv(...); // call imported API via PLT at 0x40954
    const char* s_30045 = "MTMVCore";
    const char* s_30378 = "[%s(%d)]:> AIDetectionPlugin JNI_OnLoad register_ai_detection_plugin_native_methods
"; // string xref
    const char* s_31393 = "JNI_OnLoad"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x40998
    _Z43register_ai_detection_plugin_native_methodsP7_JNIEnv(...); // call imported API via PLT at 0x409a0
    const char* s_30045 = "MTMVCore";
    const char* s_316b2 = "[%s(%d)]:> [hrs] PF_registerPlugin
"; // string xref
    const char* s_31393 = "JNI_OnLoad"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x409dc
    PF_registerPlugin(...); // call imported API via PLT at 0x409e8
    const char* s_30045 = "MTMVCore";
    const char* s_30d09 = "[%s(%d)]:> ai_detection_plugin_set_jvm failed
"; // string xref
    const char* s_31393 = "JNI_OnLoad"; // string xref
    const char* s_31393 = "JNI_OnLoad"; // string xref
    const char* s_30045 = "MTMVCore";
    const char* s_30ea4 = "[%s(%d)]:> [%s]JniHelper::getEnv() get null
"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x40a64
    const char* s_30045 = "MTMVCore";
    const char* s_31673 = "[%s(%d)]:> register_ai_detection_plugin_native_methods failed
"; // string xref
    const char* s_31393 = "JNI_OnLoad"; // string xref
    const char* s_30045 = "MTMVCore";
    const char* s_3004e = "[%s(%d)]:> PF_register AIDetector DynamicPlugin failed
"; // string xref
    const char* s_31393 = "JNI_OnLoad"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x40acc
    return a0;
}
