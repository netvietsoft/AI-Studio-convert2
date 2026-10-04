// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88f10
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorString_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88f10 | Size: 32 bytes | SHA256: df08ee67b84ed18a8e7c2610abb2643c71af0e7da4c92c6cbeec92960b821cbb
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorString_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x88f10 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x88f14 */ mov x29, sp;
    /* 0x88f18 */ mov w0, #0x18;
    _Znwm();
    /* 0x88f20 */ stp xzr, xzr, [x0, #8];
    /* 0x88f24 */ str xzr, [x0];
    /* 0x88f28 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
