// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c574
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectHighlightConfig_1index_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c574 | Size: 12 bytes | SHA256: b3057a4458ada53d644b2ca4a22f0840a191592375ae5e019dcc0558c6b0dd52
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectHighlightConfig_1index_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x8c574 */ cbz x2, #0x8c57c;
    /* 0x8c578 */ str w4, [x2, #0x18];
    return x0;
}
