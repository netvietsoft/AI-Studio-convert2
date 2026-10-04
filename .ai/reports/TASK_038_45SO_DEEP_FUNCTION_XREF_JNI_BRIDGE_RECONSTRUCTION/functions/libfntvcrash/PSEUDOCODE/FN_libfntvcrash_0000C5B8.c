// Reconstructed Pseudocode for FN_libfntvcrash_0000C5B8 (native_nrInit_()Z)
// Library: libfntvcrash.so | RVA: 0xC5B8 | Size: 960B | Visibility: FACT

/* Imported APIs: pthread_create;pthread_join;__stack_chk_fail */
/* String XREFs: java/lang/reflect/Array;newInstance;(Ljava/lang/Class;I)Ljava/lang/Object;;java/lang/String;set */

int native_nrInit_()Z(void* ctx) {
    // Function prologue: set up stack frame
    sub_CA50(ctx);
    sub_CAEC(ctx);
    sub_C98C(ctx);
    sub_CB58(ctx);
    sub_C98C(ctx);
    pthread_create(...);
    pthread_join(...);
    __stack_chk_fail(...);
    return 0;
}
