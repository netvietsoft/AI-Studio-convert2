// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x90a34
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectionNoteInterface_1_1SWIG_11
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x90a34 | Size: 72 bytes | SHA256: 1567d5875f7ac472c9d19cf500065289a66cc9489224f994bb3ee9f0a78b0b96
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectionNoteInterface_1_1SWIG_11(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x90a34 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x90a38 */ stp x20, x19, [sp, #0x10];
    /* 0x90a3c */ mov x29, sp;
    /* 0x90a40 */ mov w0, #0x18;
    /* 0x90a44 */ mov x20, x2;
    _Znwm();
    /* 0x90a4c */ mov x19, x0;
    /* 0x90a50 */ mov x1, x20;
    sub_90a7c();
    /* 0x90a58 */ mov x0, x19;
    /* 0x90a5c */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_9c5c8();
}
