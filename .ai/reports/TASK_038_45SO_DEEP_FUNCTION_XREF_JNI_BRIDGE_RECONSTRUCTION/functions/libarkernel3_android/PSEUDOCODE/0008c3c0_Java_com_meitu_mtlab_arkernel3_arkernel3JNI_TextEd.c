// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c3c0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfig_1lineSpacingEditable_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c3c0 | Size: 20 bytes | SHA256: 8cd6537af7a0af514539f1863bed4f7ee2d2d181f2096cb1195501f3c9558fa7
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfig_1lineSpacingEditable_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8c3c0 */ cbz x2, #0x8c3d0;
    /* 0x8c3c4 */ tst w4, #0xff;
    /* 0x8c3c8 */ cset w8, ne;
    /* 0x8c3cc */ strb w8, [x2, #2];
    return x0;
}
