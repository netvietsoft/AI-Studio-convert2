// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95cf0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorBrushCache_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95cf0 | Size: 32 bytes | SHA256: ce6f6741c5af1e1c377ec28ddb502b0d99a5c945fa8162b4aebafe4d5b2b1642
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorBrushCache_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95cf0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x95cf4 */ mov x29, sp;
    /* 0x95cf8 */ mov w0, #0x18;
    _Znwm();
    /* 0x95d00 */ stp xzr, xzr, [x0, #8];
    /* 0x95d04 */ str xzr, [x0];
    /* 0x95d08 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
