// Reconstructed Pseudocode for FN_libPVGLive_0008BDF8 (JNI_OnLoad)
// Library: libPVGLive.so | RVA: 0x8BDF8 | Size: 220B | Visibility: FACT

/* Imported APIs: __android_log_print;__stack_chk_fail */
/* String XREFs: PVGLive;JNI_OnLoad libPVGLive.so attach to system!;JNI_OnLoad error: failed to getEnv!;PVGLive;JNI_OnLoad error: failed to RegisterMethods! */

int JNI_OnLoad(void* ctx) {
    // Function prologue: set up stack frame
    sub_8BD84(ctx);
    __android_log_print(...);
    __stack_chk_fail(...);
    return 0;
}
