// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8960c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorInt_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8960c | Size: 32 bytes | SHA256: 09b15dac17aa260c9866d7eb95afa126b9f43f090be8b500b122910e63ca782f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorInt_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8960c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x89610 */ mov x29, sp;
    /* 0x89614 */ mov w0, #0x18;
    _Znwm();
    /* 0x8961c */ stp xzr, xzr, [x0, #8];
    /* 0x89620 */ str xzr, [x0];
    /* 0x89624 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
