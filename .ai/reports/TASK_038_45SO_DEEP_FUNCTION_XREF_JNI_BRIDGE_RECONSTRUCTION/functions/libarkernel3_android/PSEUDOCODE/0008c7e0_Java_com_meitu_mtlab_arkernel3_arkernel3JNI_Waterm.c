// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c7e0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1minScale_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c7e0 | Size: 12 bytes | SHA256: 5d6aca40b089dc3be47974c18e46efeb31ecdad1859e30be611bbeb145d6b3d7
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1minScale_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c7e0 */ cbz x2, #0x8c7e8;
    /* 0x8c7e4 */ str s0, [x2, #0x38];
    return x0;
}
