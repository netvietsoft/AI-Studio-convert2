// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88668
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColor_1size
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88668 | Size: 16 bytes | SHA256: 16ef2fb36ef94c14fd0808013e64f27363dea5ee361347aa102ce50d7e080231
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColor_1size(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x88668 */ ldp x9, x8, [x2];
    /* 0x8866c */ sub x8, x8, x9;
    /* 0x88670 */ asr x0, x8, #4;
    return x0;
}
