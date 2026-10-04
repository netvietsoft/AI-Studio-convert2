// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c3f8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfig_1verticalEditable_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c3f8 | Size: 20 bytes | SHA256: 44e020c6163b72320278841a5823bfdd3aec9baea6f9b31fde69ba7583873abf
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfig_1verticalEditable_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8c3f8 */ cbz x2, #0x8c408;
    /* 0x8c3fc */ tst w4, #0xff;
    /* 0x8c400 */ cset w8, ne;
    /* 0x8c404 */ strb w8, [x2, #4];
    return x0;
}
