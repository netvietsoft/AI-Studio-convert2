// Reconstructed Pseudocode for FN_libfntvcrash_0000B260 (native_inv0_(Ljava/lang/Object;Ljava/lang/String;ZLjava/lang/String;[Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;)
// Library: libfntvcrash.so | RVA: 0xB260 | Size: 876B | Visibility: FACT

/* Imported APIs: __stack_chk_fail */
/* String XREFs: plemented;illegal name;illegal arg sig;illegal return sig */

int native_inv0_(Ljava/lang/Object;Ljava/lang/String;ZLjava/lang/String;[Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;(void* ctx) {
    // Function prologue: set up stack frame
    sub_C9F0(ctx);
    sub_CA0C(ctx);
    sub_C978(ctx);
    sub_CBB8(ctx);
    sub_C978(ctx);
    __stack_chk_fail(...);
    return 0;
}
