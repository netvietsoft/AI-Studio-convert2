// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x905a8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectionAnimationInterface_1_1SWIG_10
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x905a8 | Size: 32 bytes | SHA256: 46ac5b2bd414f42c2e1aad55b70e79fabe34130a78742f8b4c033f7438ce170f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectionAnimationInterface_1_1SWIG_10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x905a8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x905ac */ mov x29, sp;
    /* 0x905b0 */ mov w0, #0x18;
    _Znwm();
    /* 0x905b8 */ stp xzr, xzr, [x0, #8];
    /* 0x905bc */ str xzr, [x0];
    /* 0x905c0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
