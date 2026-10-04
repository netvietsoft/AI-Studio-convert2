// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c828
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectHighlightConfig_1_1SWIG_11
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c828 | Size: 72 bytes | SHA256: d7e447b8b1383f24b3f54253b176588078f0e4f436d2be2223e3c45fa56b4765
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectHighlightConfig_1_1SWIG_11(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x8c828 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8c82c */ stp x20, x19, [sp, #0x10];
    /* 0x8c830 */ mov x29, sp;
    /* 0x8c834 */ mov w0, #0x18;
    /* 0x8c838 */ mov x20, x2;
    _Znwm();
    /* 0x8c840 */ mov x19, x0;
    /* 0x8c844 */ mov x1, x20;
    sub_8c870();
    /* 0x8c84c */ mov x0, x19;
    /* 0x8c850 */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_9c5c8();
}
