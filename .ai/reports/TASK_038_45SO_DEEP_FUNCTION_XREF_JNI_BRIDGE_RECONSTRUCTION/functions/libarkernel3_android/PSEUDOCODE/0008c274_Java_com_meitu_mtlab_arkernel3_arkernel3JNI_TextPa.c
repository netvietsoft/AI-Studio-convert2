// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c274
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1scaleY_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c274 | Size: 12 bytes | SHA256: b36f26123925a53727f2545e0f5fe04c8f58531490f0d71e2e9975a36918c07d
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1scaleY_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c274 */ cbz x2, #0x8c27c;
    /* 0x8c278 */ str s0, [x2, #0x24];
    return x0;
}
