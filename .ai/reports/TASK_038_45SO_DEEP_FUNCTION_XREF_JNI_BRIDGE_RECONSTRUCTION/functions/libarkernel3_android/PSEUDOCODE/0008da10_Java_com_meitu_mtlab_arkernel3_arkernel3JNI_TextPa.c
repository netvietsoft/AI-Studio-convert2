// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8da10
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1setReverse
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8da10 | Size: 16 bytes | SHA256: a11f43f0269fb05bfda1e1e297d6d7f8c059c44d3e649532fc5d5f8a3004ef3e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321TextPathConfiguration10setReverseEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1setReverse(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8da10 */ tst w4, #0xff;
    /* 0x8da14 */ mov x0, x2;
    /* 0x8da18 */ cset w1, ne;
    /* 0x8da1c */ b #0xa1070;
}
