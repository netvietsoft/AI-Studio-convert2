// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x87cdc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SizeI_1height_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x87cdc | Size: 12 bytes | SHA256: d8867ff440bb628d2ddf6466cc7a8d3f662d41e3a6baab251149eb0ed273ab77
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SizeI_1height_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x87cdc */ cbz x2, #0x87ce4;
    /* 0x87ce0 */ str w4, [x2, #4];
    return x0;
}
