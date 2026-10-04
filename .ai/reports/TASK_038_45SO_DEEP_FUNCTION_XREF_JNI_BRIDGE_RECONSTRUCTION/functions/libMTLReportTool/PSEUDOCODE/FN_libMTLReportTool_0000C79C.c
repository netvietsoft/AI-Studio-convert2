// Reconstructed Pseudocode for FN_libMTLReportTool_0000C79C (JNI_OnLoad)
// Library: libMTLReportTool.so | RVA: 0xC79C | Size: 228B | Visibility: FACT

/* Imported APIs: __android_log_print;__stack_chk_fail */
/* String XREFs: vllogmediatorLog-JNI;JNI_OnLoad libMTLReportTool.so attach to system!;JNI_OnLoad error: failed to getEnv!;vllogmediatorLog-JNI;JNI_OnLoad error: failed to RegisterMethods! */

int JNI_OnLoad(void* ctx) {
    // Function prologue: set up stack frame
    sub_C66C(ctx);
    sub_C628(ctx);
    __android_log_print(...);
    __stack_chk_fail(...);
    return 0;
}
