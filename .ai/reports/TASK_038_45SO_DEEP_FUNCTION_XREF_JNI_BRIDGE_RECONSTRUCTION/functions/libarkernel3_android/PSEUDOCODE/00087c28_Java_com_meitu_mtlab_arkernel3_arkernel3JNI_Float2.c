// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x87c28
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Float2_1y_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x87c28 | Size: 12 bytes | SHA256: 2f0f8f53c2b37479c0511f56a5b74dab9e9c88499f77b1b9525148c2f6f285db
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Float2_1y_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x87c28 */ cbz x2, #0x87c30;
    /* 0x87c2c */ str s0, [x2, #4];
    return x0;
}
