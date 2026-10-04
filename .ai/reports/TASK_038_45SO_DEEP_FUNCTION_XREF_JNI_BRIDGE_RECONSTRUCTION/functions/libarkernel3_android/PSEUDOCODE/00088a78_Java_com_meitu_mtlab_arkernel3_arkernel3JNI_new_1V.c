// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88a78
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorPoint2F_1_1SWIG_11
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88a78 | Size: 72 bytes | SHA256: 18b72923a7ca8b14552afe578ed21e758e19cc3d4db688ea2a4c5bf2acae8bda
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorPoint2F_1_1SWIG_11(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x88a78 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x88a7c */ stp x20, x19, [sp, #0x10];
    /* 0x88a80 */ mov x29, sp;
    /* 0x88a84 */ mov w0, #0x18;
    /* 0x88a88 */ mov x20, x2;
    _Znwm();
    /* 0x88a90 */ mov x19, x0;
    /* 0x88a94 */ mov x1, x20;
    sub_88ac0();
    /* 0x88a9c */ mov x0, x19;
    /* 0x88aa0 */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_9c5c8();
}
