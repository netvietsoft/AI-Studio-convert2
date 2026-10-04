// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c360
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1aspectRatio_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c360 | Size: 12 bytes | SHA256: 3492d15d3a91a41438f3703cb7850f7c25877b013fd94d0ef670902022f758de
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1aspectRatio_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c360 */ cbz x2, #0x8c368;
    /* 0x8c364 */ str s0, [x2, #0x50];
    return x0;
}
