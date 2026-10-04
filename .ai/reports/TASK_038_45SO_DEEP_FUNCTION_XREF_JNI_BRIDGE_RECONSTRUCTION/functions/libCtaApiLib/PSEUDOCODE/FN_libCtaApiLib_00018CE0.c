// Reconstructed Pseudocode for FN_libCtaApiLib_00018CE0 (native_dneulret_([B)[B)
// Library: libCtaApiLib.so | RVA: 0x18CE0 | Size: 508B | Visibility: FACT

/* Imported APIs: free;__stack_chk_fail;_Unwind_Resume */
/* String XREFs: QU */

int native_dneulret_([B)[B(void* ctx) {
    // Function prologue: set up stack frame
    sub_27588(ctx);
    sub_217FC(ctx);
    sub_2C258(ctx);
    sub_2C258(ctx);
    free(...);
    __stack_chk_fail(...);
    _Unwind_Resume(...);
    return 0;
}
