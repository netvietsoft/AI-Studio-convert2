// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c308
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1firstMarginRatio_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c308 | Size: 12 bytes | SHA256: 374978e93f9ef207c7235db058ef2a6bd8792a4d76a4f969e177568354e58816
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1firstMarginRatio_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c308 */ cbz x2, #0x8c310;
    /* 0x8c30c */ str s0, [x2, #0x40];
    return x0;
}
