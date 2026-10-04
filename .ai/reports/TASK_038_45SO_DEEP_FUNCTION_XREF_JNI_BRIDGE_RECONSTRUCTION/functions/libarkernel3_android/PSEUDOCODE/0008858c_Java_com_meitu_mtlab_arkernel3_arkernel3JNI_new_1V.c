// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8858c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorColor_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8858c | Size: 32 bytes | SHA256: 69d38e93d1325b674ec13d135bac042b66f43efdbbd0aa4556ff30fba0e66c48
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorColor_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8858c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x88590 */ mov x29, sp;
    /* 0x88594 */ mov w0, #0x18;
    _Znwm();
    /* 0x8859c */ stp xzr, xzr, [x0, #8];
    /* 0x885a0 */ str xzr, [x0];
    /* 0x885a4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
