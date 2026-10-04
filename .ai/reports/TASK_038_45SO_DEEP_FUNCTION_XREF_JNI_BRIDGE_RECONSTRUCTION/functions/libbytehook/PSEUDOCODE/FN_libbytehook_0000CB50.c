// Reconstructed Pseudocode for FN_libbytehook_0000CB50 (sub_CB50)
// Library: libbytehook.so | RVA: 0xCB50 | Size: 232B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: dlopen */
/* String XREFs: libc.so;sigaction64;sigprocmask64;sigaction;sigprocmask */

int sub_CB50(void* ctx) {
    // Function prologue: set up stack frame
    sub_D168(ctx);
    sub_D168(ctx);
    sub_D15C(ctx);
    sub_D168(ctx);
    sub_D168(ctx);
    dlopen(...);
    return 0;
}
