// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x90a14
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectionNoteInterface_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x90a14 | Size: 32 bytes | SHA256: f375c8e41341b636400b0ca5f46603a6261affef0a5185136d13f5876542c5a1
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectionNoteInterface_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x90a14 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x90a18 */ mov x29, sp;
    /* 0x90a1c */ mov w0, #0x18;
    _Znwm();
    /* 0x90a24 */ stp xzr, xzr, [x0, #8];
    /* 0x90a28 */ str xzr, [x0];
    /* 0x90a2c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
