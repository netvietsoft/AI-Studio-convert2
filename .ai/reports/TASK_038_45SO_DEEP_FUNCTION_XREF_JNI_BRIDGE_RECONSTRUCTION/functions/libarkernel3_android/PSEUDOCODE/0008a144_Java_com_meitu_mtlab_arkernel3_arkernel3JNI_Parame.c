// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a144
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1integer_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a144 | Size: 12 bytes | SHA256: b4ee0e075166d638aa95f7c1db96dd314f1a74659fd2152e259f8d001009bf75
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterValue_1integer_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8a144 */ cbz x2, #0x8a14c;
    /* 0x8a148 */ str x4, [x2, #0x28];
    return x0;
}
