// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c31c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1lastMarginRatio_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c31c | Size: 12 bytes | SHA256: e145d30b3cbfa701c3ff93daa97c375446eb0a44fe5a79b5a41d6ba1df1aa913
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1lastMarginRatio_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c31c */ cbz x2, #0x8c324;
    /* 0x8c320 */ str s0, [x2, #0x44];
    return x0;
}
