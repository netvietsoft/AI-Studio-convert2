// Reconstructed Pseudocode for FN_libaidetectionplugin_000408F4 (JNI_OnLoad)
// Library: libaidetectionplugin.so | RVA: 0x408F4 | Size: 492B | Visibility: FACT

/* Imported APIs: __android_log_print;_Z27ai_detection_plugin_set_jvmP7_JavaVM;_ZN17MMDetectionPlugin9JniHelper6getEnvEv;_Z43register_ai_detection_plugin_native_methodsP7_JNIEnv;PF_registerPlugin */
/* String XREFs: MTMVCore;[%s(%d)]:> [hrs] plugin JNI_OnLoad;JNI_OnLoad;MTMVCore;[%s(%d)]:> AIDetectionPlugin JNI_OnLoad register_ai_detection_plugin_native_meth */

int JNI_OnLoad(void* ctx) {
    // Function prologue: set up stack frame
    __android_log_print(...);
    _Z27ai_detection_plugin_set_jvmP7_JavaVM(...);
    _ZN17MMDetectionPlugin9JniHelper6getEnvEv(...);
    _Z43register_ai_detection_plugin_native_methodsP7_JNIEnv(...);
    PF_registerPlugin(...);
    return 0;
}
