// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d620
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleConfiguration_1setEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d620 | Size: 16 bytes | SHA256: 656f1765f2b10df2d9732d1859af70a133ea259bf865b644438ed58f3a5e7239
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextBubbleConfiguration11setEditableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleConfiguration_1setEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8d620 */ tst w4, #0xff;
    /* 0x8d624 */ mov x0, x2;
    /* 0x8d628 */ cset w1, ne;
    /* 0x8d62c */ b #0xa0e90;
}
