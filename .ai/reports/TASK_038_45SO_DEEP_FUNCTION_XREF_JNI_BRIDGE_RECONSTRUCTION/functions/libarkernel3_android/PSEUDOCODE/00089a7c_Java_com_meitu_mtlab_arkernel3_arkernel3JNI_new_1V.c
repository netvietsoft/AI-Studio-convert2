// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x89a7c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorFloat_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x89a7c | Size: 32 bytes | SHA256: 528ed1d11a3a6ad2bd44a0829e2df3fd2b93659855c596d02b391ed26c17ee7e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorFloat_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x89a7c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x89a80 */ mov x29, sp;
    /* 0x89a84 */ mov w0, #0x18;
    _Znwm();
    /* 0x89a8c */ stp xzr, xzr, [x0, #8];
    /* 0x89a90 */ str xzr, [x0];
    /* 0x89a94 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
