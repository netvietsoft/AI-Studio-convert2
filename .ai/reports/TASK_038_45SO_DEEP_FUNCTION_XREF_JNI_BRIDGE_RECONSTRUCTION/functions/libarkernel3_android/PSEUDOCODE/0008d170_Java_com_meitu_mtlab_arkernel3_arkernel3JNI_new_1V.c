// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d170
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorAnimationTimeType_1_1SWIG_11
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d170 | Size: 72 bytes | SHA256: c479dab8d5f1b27fd1540249cba2d9ffb7692ccc8f1eb8f20ebd87c18474ec34
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorAnimationTimeType_1_1SWIG_11(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x8d170 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8d174 */ stp x20, x19, [sp, #0x10];
    /* 0x8d178 */ mov x29, sp;
    /* 0x8d17c */ mov w0, #0x18;
    /* 0x8d180 */ mov x20, x2;
    _Znwm();
    /* 0x8d188 */ mov x19, x0;
    /* 0x8d18c */ mov x1, x20;
    sub_8d1b8();
    /* 0x8d194 */ mov x0, x19;
    /* 0x8d198 */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_9c5c8();
}
