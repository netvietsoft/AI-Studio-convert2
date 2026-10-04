// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8edc8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1setEnableTextOnIcon
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8edc8 | Size: 16 bytes | SHA256: 392e86448367c4410e8dbbbc5db2073ddb85bf778f97f3692e376da8016bec92
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar326IconSequenceStyleInterface19setEnableTextOnIconEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1setEnableTextOnIcon(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8edc8 */ tst w4, #0xff;
    /* 0x8edcc */ mov x0, x2;
    /* 0x8edd0 */ cset w1, ne;
    /* 0x8edd4 */ b #0xa1c30;
}
