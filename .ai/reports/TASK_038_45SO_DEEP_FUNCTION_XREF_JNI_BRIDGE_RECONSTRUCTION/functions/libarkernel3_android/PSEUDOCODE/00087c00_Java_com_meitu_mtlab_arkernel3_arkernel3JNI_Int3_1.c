// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x87c00
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Int3_1z_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x87c00 | Size: 12 bytes | SHA256: e8444d2950b3a723fe098e0876fb99d0226cd784bdc0becea0d22c153ca5a1a8
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Int3_1z_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x87c00 */ cbz x2, #0x87c08;
    /* 0x87c04 */ str w4, [x2, #8];
    return x0;
}
