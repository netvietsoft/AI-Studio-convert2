// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c808
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectHighlightConfig_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c808 | Size: 32 bytes | SHA256: 72b1d0c3c136fc87c2b65697a0f809149a684100345504ed2fc027062dbb71f1
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectHighlightConfig_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8c808 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8c80c */ mov x29, sp;
    /* 0x8c810 */ mov w0, #0x18;
    _Znwm();
    /* 0x8c818 */ stp xzr, xzr, [x0, #8];
    /* 0x8c81c */ str xzr, [x0];
    /* 0x8c820 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
