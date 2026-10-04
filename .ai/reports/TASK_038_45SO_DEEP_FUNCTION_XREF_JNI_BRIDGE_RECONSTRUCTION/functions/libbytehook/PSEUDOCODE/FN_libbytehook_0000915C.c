// Reconstructed Pseudocode for FN_libbytehook_0000915C (JNI_OnLoad)
// Library: libbytehook.so | RVA: 0x915C | Size: 216B | Visibility: FACT

/* Imported APIs: memcpy;__stack_chk_fail */
/* String XREFs: com/bytedance/android/bytehook/ByteHook */

int JNI_OnLoad(void* ctx) {
    // Function prologue: set up stack frame
    memcpy(...);
    __stack_chk_fail(...);
    return 0;
}
