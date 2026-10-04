// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d5f4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleConfiguration_1setEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d5f4 | Size: 16 bytes | SHA256: d3918e325ad06fb6b2b393a42e5273a5ecc180d2ac1b7befadd3609235784ae5
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextBubbleConfiguration9setEnableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleConfiguration_1setEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8d5f4 */ tst w4, #0xff;
    /* 0x8d5f8 */ mov x0, x2;
    /* 0x8d5fc */ cset w1, ne;
    /* 0x8d600 */ b #0xa0e70;
}
