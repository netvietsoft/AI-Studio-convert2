// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x89fc0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterInteger2_1y_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x89fc0 | Size: 12 bytes | SHA256: 515ee2b128b76203b538471c318346ba6bc0e88f64b4df1297233b519c864735
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParameterInteger2_1y_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x89fc0 */ cbz x2, #0x89fc8;
    /* 0x89fc4 */ str x4, [x2, #8];
    return x0;
}
