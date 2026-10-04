// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9a1a8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1setOption
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9a1a8 | Size: 20 bytes | SHA256: 8fe2b6875368358363d755df2f1fc2fdc6ae67d373f28bd93ce1562069babd15
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39Interface9setOptionENS_10OptionTypeEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1setOption(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x9a1a8 */ tst w5, #0xff;
    /* 0x9a1ac */ mov w1, w4;
    /* 0x9a1b0 */ mov x0, x2;
    /* 0x9a1b4 */ cset w2, ne;
    /* 0x9a1b8 */ b #0xa59b0;
}
