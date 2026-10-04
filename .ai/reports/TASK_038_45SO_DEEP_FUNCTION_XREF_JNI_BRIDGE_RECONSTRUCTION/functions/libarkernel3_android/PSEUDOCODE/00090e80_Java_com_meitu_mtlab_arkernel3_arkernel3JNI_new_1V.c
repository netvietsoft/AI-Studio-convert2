// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x90e80
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorLineLayoutConfigInterface_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x90e80 | Size: 32 bytes | SHA256: 9880fff31d26a77509b209d004ea258a4b101dc74cddb6d5ec5c0bfae66a288b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorLineLayoutConfigInterface_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x90e80 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x90e84 */ mov x29, sp;
    /* 0x90e88 */ mov w0, #0x18;
    _Znwm();
    /* 0x90e90 */ stp xzr, xzr, [x0, #8];
    /* 0x90e94 */ str xzr, [x0];
    /* 0x90e98 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
