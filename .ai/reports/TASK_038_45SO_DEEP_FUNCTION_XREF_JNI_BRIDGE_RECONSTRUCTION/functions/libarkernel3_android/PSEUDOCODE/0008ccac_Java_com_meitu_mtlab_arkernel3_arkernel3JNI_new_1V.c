// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ccac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectAnimationConfig_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ccac | Size: 32 bytes | SHA256: 367f3a1b28a993b53c0de5e6a629da1c34191a987e91e46f0a33a6675f8be9e2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectAnimationConfig_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8ccac */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8ccb0 */ mov x29, sp;
    /* 0x8ccb4 */ mov w0, #0x18;
    _Znwm();
    /* 0x8ccbc */ stp xzr, xzr, [x0, #8];
    /* 0x8ccc0 */ str xzr, [x0];
    /* 0x8ccc4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
