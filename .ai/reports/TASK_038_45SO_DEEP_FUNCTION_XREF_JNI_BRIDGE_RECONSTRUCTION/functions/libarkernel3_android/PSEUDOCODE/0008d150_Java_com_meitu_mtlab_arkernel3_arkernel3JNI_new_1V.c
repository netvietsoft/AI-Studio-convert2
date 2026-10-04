// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d150
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorAnimationTimeType_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d150 | Size: 32 bytes | SHA256: bb3d983136550dfa48c444df346e9fd3e9970d57c5bec237016d08c0a2f1ab05
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorAnimationTimeType_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8d150 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8d154 */ mov x29, sp;
    /* 0x8d158 */ mov w0, #0x18;
    _Znwm();
    /* 0x8d160 */ stp xzr, xzr, [x0, #8];
    /* 0x8d164 */ str xzr, [x0];
    /* 0x8d168 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
