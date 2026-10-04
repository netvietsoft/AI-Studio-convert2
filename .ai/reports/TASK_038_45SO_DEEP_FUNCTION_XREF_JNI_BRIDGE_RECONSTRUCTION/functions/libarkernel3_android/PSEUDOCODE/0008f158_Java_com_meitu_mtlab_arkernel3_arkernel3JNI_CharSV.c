// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f158
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1setEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f158 | Size: 16 bytes | SHA256: 2156d8204f70781001401a051c506bc372f5e39e51fb7bfb34c30430f6084438
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar326CharSVGBackgroundInterface9setEnableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1setEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8f158 */ tst w4, #0xff;
    /* 0x8f15c */ mov x0, x2;
    /* 0x8f160 */ cset w1, ne;
    /* 0x8f164 */ b #0xa1f30;
}
