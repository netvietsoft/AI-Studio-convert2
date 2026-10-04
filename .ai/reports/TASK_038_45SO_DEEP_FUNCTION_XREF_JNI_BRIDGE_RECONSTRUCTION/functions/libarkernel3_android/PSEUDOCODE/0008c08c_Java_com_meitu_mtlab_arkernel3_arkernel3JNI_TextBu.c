// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c08c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleBoxConfig_1editable_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c08c | Size: 20 bytes | SHA256: 14859c5ba1c8e6b47d2e0cf68b7dcfdfc37860379f148977822ab160598ac8b8
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleBoxConfig_1editable_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8c08c */ cbz x2, #0x8c09c;
    /* 0x8c090 */ tst w4, #0xff;
    /* 0x8c094 */ cset w8, ne;
    /* 0x8c098 */ strb w8, [x2, #1];
    return x0;
}
