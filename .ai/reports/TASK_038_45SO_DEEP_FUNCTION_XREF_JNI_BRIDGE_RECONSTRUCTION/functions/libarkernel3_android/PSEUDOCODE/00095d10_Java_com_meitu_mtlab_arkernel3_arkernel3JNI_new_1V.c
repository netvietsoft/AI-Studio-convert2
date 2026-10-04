// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95d10
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorBrushCache_1_1SWIG_11
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95d10 | Size: 72 bytes | SHA256: cf8053cb238c6070b2fa6126c742b4a48bfec2dbe45d03041b439ec028d75480
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorBrushCache_1_1SWIG_11(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x95d10 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x95d14 */ stp x20, x19, [sp, #0x10];
    /* 0x95d18 */ mov x29, sp;
    /* 0x95d1c */ mov w0, #0x18;
    /* 0x95d20 */ mov x20, x2;
    _Znwm();
    /* 0x95d28 */ mov x19, x0;
    /* 0x95d2c */ mov x1, x20;
    sub_95d58();
    /* 0x95d34 */ mov x0, x19;
    /* 0x95d38 */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_9c5c8();
}
