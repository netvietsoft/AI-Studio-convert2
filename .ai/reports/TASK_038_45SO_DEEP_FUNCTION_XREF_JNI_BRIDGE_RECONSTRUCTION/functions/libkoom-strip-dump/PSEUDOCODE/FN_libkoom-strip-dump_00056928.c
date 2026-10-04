// Reconstructed Pseudocode for FN_libkoom-strip-dump_00056928 (android_log_addFilterString)
// Library: libkoom-strip-dump.so | RVA: 0x56928 | Size: 160B | Visibility: FACT

/* Imported APIs: strdup;strsep;android_log_addFilterRule;__stack_chk_fail */
/* String XREFs:  */

int android_log_addFilterString(void* ctx) {
    // Function prologue: set up stack frame
    sub_587D4(ctx);
    strdup(...);
    strsep(...);
    android_log_addFilterRule(...);
    __stack_chk_fail(...);
    return 0;
}
