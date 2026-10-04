// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c288
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1pathLengthUseRatio_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c288 | Size: 12 bytes | SHA256: 9154ad0febcd5dd5d189e37bbc6fb0a1844160707a8f78c0d22bb6321b8639a9
// Callers: 0 | Callees: 0 | Imports: 0


jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1pathLengthUseRatio_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c288 */ cbz x2, #0x8c290;
    /* 0x8c28c */ str s0, [x2, #0x28];
    return x0;
}
