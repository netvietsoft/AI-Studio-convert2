// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9013c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectionHighlightInterface_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9013c | Size: 32 bytes | SHA256: c58fd15b495933311b8fec984955a301d9b81196042d3096c9e102e383f9b822
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectionHighlightInterface_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x9013c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x90140 */ mov x29, sp;
    /* 0x90144 */ mov w0, #0x18;
    _Znwm();
    /* 0x9014c */ stp xzr, xzr, [x0, #8];
    /* 0x90150 */ str xzr, [x0];
    /* 0x90154 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
