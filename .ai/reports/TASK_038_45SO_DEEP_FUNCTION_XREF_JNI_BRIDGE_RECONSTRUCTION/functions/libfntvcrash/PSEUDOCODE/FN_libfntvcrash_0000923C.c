// Reconstructed Pseudocode for FN_libfntvcrash_0000923C (JNI_OnLoad)
// Library: libfntvcrash.so | RVA: 0x923C | Size: 304B | Visibility: FACT

/* Imported APIs: __stack_chk_fail */
/* String XREFs: cn/fly/tools/xcrash/NativeHandler */

int JNI_OnLoad(void* ctx) {
    // Function prologue: set up stack frame
    sub_C984(ctx);
    sub_CBE8(ctx);
    __stack_chk_fail(...);
    return 0;
}
