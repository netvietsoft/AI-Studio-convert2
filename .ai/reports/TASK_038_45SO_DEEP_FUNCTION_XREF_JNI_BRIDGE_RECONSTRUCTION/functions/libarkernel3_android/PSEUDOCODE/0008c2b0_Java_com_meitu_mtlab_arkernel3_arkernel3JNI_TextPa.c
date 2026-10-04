// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c2b0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1textBound_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c2b0 | Size: 12 bytes | SHA256: c71fc5c34b5bd2d4da7f185e91efb5be017494f32763121d168f3d0a164eff6d
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1textBound_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c2b0 */ cbz x2, #0x8c2b8;
    /* 0x8c2b4 */ str s0, [x2, #0x30];
    return x0;
}
