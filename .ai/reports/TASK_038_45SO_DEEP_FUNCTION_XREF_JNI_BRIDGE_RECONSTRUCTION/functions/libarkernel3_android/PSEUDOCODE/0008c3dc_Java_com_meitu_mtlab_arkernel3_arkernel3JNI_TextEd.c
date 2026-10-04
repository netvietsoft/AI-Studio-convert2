// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c3dc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfig_1horizontalEditable_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c3dc | Size: 20 bytes | SHA256: ab8e7de8d32c76329f122dcdcca4af8bca3423aa05844bf3b89c0ca32d2a9d25
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfig_1horizontalEditable_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8c3dc */ cbz x2, #0x8c3ec;
    /* 0x8c3e0 */ tst w4, #0xff;
    /* 0x8c3e4 */ cset w8, ne;
    /* 0x8c3e8 */ strb w8, [x2, #3];
    return x0;
}
