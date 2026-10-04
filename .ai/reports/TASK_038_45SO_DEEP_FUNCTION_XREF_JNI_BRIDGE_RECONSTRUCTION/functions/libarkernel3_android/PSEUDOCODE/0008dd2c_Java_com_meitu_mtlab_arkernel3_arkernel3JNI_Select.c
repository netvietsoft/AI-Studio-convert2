// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8dd2c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setHideNonHighlightUnderline
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8dd2c | Size: 16 bytes | SHA256: f5ef64cc50de9d3fe6a64e4199eee317cf4f8e27c9c92438304a0539976e0033
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar327SelectionHighlightInterface28setHideNonHighlightUnderlineEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setHideNonHighlightUnderline(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8dd2c */ tst w4, #0xff;
    /* 0x8dd30 */ mov x0, x2;
    /* 0x8dd34 */ cset w1, ne;
    /* 0x8dd38 */ b #0xa1330;
}
