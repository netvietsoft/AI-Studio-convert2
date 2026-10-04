// Reconstructed Pseudocode for FN_libPVGLive_0008BED4 (JNI_OnUnload)
// Library: libPVGLive.so | RVA: 0x8BED4 | Size: 156B | Visibility: FACT

/* Imported APIs: __android_log_print;__stack_chk_fail */
/* String XREFs: PVGLive;JNI_OnUnload libPVGLive.so dettach from system!;PVGLive;JNI_OnUnload error: failed to getEnv! */

int JNI_OnUnload(void* ctx) {
    // Function prologue: set up stack frame
    __android_log_print(...);
    __stack_chk_fail(...);
    return 0;
}
