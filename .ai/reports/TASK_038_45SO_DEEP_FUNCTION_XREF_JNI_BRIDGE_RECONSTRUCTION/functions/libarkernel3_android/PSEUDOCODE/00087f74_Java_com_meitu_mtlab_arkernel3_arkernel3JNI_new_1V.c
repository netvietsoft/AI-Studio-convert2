// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x87f74
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorColorA_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x87f74 | Size: 32 bytes | SHA256: 8a79ee9e2740378cad825683ddbc70220cdd0d6973b2cc0a00c62cc97f63a97b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorColorA_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x87f74 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x87f78 */ mov x29, sp;
    /* 0x87f7c */ mov w0, #0x18;
    _Znwm();
    /* 0x87f84 */ stp xzr, xzr, [x0, #8];
    /* 0x87f88 */ str xzr, [x0];
    /* 0x87f8c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
