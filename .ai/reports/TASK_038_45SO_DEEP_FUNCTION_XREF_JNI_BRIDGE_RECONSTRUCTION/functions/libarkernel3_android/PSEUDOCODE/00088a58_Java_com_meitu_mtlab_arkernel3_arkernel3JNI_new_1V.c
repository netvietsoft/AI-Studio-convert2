// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88a58
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorPoint2F_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88a58 | Size: 32 bytes | SHA256: 2d6e2b3029d15f33e77d2bc4a6a0a8bbf4230bb69fb3f5c2218157516e409a9e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorPoint2F_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x88a58 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x88a5c */ mov x29, sp;
    /* 0x88a60 */ mov w0, #0x18;
    _Znwm();
    /* 0x88a68 */ stp xzr, xzr, [x0, #8];
    /* 0x88a6c */ str xzr, [x0];
    /* 0x88a70 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
