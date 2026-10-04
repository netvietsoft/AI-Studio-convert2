// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c388
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfig_1editable_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c388 | Size: 20 bytes | SHA256: 28cac96faa18582bbe8ceab1389ac4895747013fb032f15c77e2efd67e943df4
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfig_1editable_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8c388 */ cbz x2, #0x8c398;
    /* 0x8c38c */ tst w4, #0xff;
    /* 0x8c390 */ cset w8, ne;
    /* 0x8c394 */ strb w8, [x2];
    return x0;
}
