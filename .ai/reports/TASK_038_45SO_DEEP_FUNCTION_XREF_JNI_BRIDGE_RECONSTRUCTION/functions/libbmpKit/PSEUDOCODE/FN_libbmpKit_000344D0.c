// Reconstructed Pseudocode for FN_libbmpKit_000344D0 (JNI_OnLoad)
// Library: libbmpKit.so | RVA: 0x344D0 | Size: 224B | Visibility: FACT

/* Imported APIs: _ZN7_JavaVM6GetEnvEPPvi;__android_log_print;_ZN11KitApi30NDK18registerJniMethodsEP7_JNIEnv;__stack_chk_fail */
/* String XREFs: cBmpKit;jni OnLoad GetEnv error!;cBmpKit;KitApi30NDK registerJniMethods error! */

int JNI_OnLoad(void* ctx) {
    // Function prologue: set up stack frame
    _ZN7_JavaVM6GetEnvEPPvi(...);
    __android_log_print(...);
    _ZN11KitApi30NDK18registerJniMethodsEP7_JNIEnv(...);
    __stack_chk_fail(...);
    return 0;
}
