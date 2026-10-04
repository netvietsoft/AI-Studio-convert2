// Reconstructed Pseudocode for FN_libbytehook_00009354 (native_nativeGetRecords_(I)Ljava/lang/String;)
// Library: libbytehook.so | RVA: 0x9354 | Size: 80B | Visibility: FACT

/* Imported APIs: bytehook_get_records;free */
/* String XREFs:  */

int native_nativeGetRecords_(I)Ljava/lang/String;(void* ctx) {
    // Function prologue: set up stack frame
    bytehook_get_records(...);
    free(...);
    return 0;
}
