// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x87f94
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorColorA_1_1SWIG_11
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x87f94 | Size: 72 bytes | SHA256: b79f42f83bba973ac5f5eba512ad8209382773a2d993af336cb4428cf792ba30
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorColorA_1_1SWIG_11(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x87f94 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x87f98 */ stp x20, x19, [sp, #0x10];
    /* 0x87f9c */ mov x29, sp;
    /* 0x87fa0 */ mov w0, #0x18;
    /* 0x87fa4 */ mov x20, x2;
    _Znwm();
    /* 0x87fac */ mov x19, x0;
    /* 0x87fb0 */ mov x1, x20;
    sub_87fdc();
    /* 0x87fb8 */ mov x0, x19;
    /* 0x87fbc */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_9c5c8();
}
