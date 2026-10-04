// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c258
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1reverse_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c258 | Size: 20 bytes | SHA256: 548fc3a9c0ce1dac1518722ddd65d7fd7df25c40a6a2fafd4e1df6443faa48ae
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfig_1reverse_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8c258 */ cbz x2, #0x8c268;
    /* 0x8c25c */ tst w4, #0xff;
    /* 0x8c260 */ cset w8, ne;
    /* 0x8c264 */ strb w8, [x2, #0x21];
    return x0;
}
