// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c070
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleBoxConfig_1enable_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c070 | Size: 20 bytes | SHA256: 28cac96faa18582bbe8ceab1389ac4895747013fb032f15c77e2efd67e943df4
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleBoxConfig_1enable_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8c070 */ cbz x2, #0x8c080;
    /* 0x8c074 */ tst w4, #0xff;
    /* 0x8c078 */ cset w8, ne;
    /* 0x8c07c */ strb w8, [x2];
    return x0;
}
