// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8cccc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectAnimationConfig_1_1SWIG_11
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8cccc | Size: 72 bytes | SHA256: c1a50be553ae118924848011086df7de7776101ae577278ce20ff538c8a4ad9c
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectAnimationConfig_1_1SWIG_11(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x8cccc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8ccd0 */ stp x20, x19, [sp, #0x10];
    /* 0x8ccd4 */ mov x29, sp;
    /* 0x8ccd8 */ mov w0, #0x18;
    /* 0x8ccdc */ mov x20, x2;
    _Znwm();
    /* 0x8cce4 */ mov x19, x0;
    /* 0x8cce8 */ mov x1, x20;
    sub_8cd14();
    /* 0x8ccf0 */ mov x0, x19;
    /* 0x8ccf4 */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_9c5c8();
}
