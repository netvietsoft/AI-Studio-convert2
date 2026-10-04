// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c758
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1space_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c758 | Size: 12 bytes | SHA256: 797db50f01f773597804e9921abcafc6782dce32246775e76791942866c6230f
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_WatermarkConfig_1space_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c758 */ cbz x2, #0x8c760;
    /* 0x8c75c */ str s0, [x2, #0x10];
    return x0;
}
