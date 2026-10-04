// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b758
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportVideoData_1path_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b758 | Size: 28 bytes | SHA256: 1a545d1edb90524019129356ab0b727d39002f33bea07248d658564ab75c4bce
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportVideoData_1path_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8b758 */ ldr x1, [x2];
    /* 0x8b75c */ cbz x1, #0x8b76c;
    /* 0x8b760 */ ldr x8, [x0];
    /* 0x8b764 */ ldr x2, [x8, #0x538];
    /* 0x8b768 */ br x2;
    /* 0x8b76c */ mov x0, xzr;
    return x0;
}
