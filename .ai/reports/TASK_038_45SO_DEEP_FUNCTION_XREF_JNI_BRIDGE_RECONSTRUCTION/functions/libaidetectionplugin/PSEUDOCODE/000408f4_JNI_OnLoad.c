// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x408f4
// Recovered Name: JNI_OnLoad
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x408f4 | Size: 492 bytes | SHA256: 0830f805eff7c0dd53adb5963036a049eb57413f312715f0341dc00fb61a185e
// Callers: 0 | Callees: 0 | Imports: 5

// Calls external APIs: PF_registerPlugin, _Z27ai_detection_plugin_set_jvmP7_JavaVM, _Z43register_ai_detection_plugin_native_methodsP7_JNIEnv, _ZN17MMDetectionPlugin9JniHelper6getEnvEv, __android_log_print
// Strings referenced:
//   "JNI_OnLoad"

jobject JNI_OnLoad(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 123 instructions
    /* 0x408f4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x408f8 */ stp x20, x19, [sp, #0x10];
    /* 0x408fc */ mov x29, sp;
    /* 0x40900 */ adrp x19, #0x82000;
    /* 0x40904 */ ldr x19, [x19, #0xd50];
    /* 0x40908 */ ldr w8, [x19];
    /* 0x4090c */ cmp w8, #5;
    /* 0x40910 */ b.gt #0x4094c;
    /* 0x40914 */ adrp x8, #0x82000;
    /* 0x40918 */ nop ;
    /* 0x4091c */ adr x1, #0x30045;
    __android_log_print();
    _Z27ai_detection_plugin_set_jvmP7_JavaVM();
    _ZN17MMDetectionPlugin9JniHelper6getEnvEv();
    __android_log_print();
    _Z43register_ai_detection_plugin_native_methodsP7_JNIEnv();
    __android_log_print();
    PF_registerPlugin();
    __android_log_print();
    __android_log_print();
    return x0;
}
