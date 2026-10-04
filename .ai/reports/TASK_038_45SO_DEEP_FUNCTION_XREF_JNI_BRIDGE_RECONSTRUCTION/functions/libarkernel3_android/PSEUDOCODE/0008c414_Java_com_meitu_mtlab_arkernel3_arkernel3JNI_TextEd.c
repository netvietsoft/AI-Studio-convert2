// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c414
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfig_1pinyinEditable_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c414 | Size: 20 bytes | SHA256: 8b0335864074649a9820c199c9b46a5c83d12ad037f643d007c1df23084354df
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfig_1pinyinEditable_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8c414 */ cbz x2, #0x8c424;
    /* 0x8c418 */ tst w4, #0xff;
    /* 0x8c41c */ cset w8, ne;
    /* 0x8c420 */ strb w8, [x2, #5];
    return x0;
}
