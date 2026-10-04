// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9015c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectionHighlightInterface_1_1SWIG_11
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9015c | Size: 72 bytes | SHA256: c27ca234224a2ee031f21644004b997e2441415665c900d297888b48ca188ede
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectionHighlightInterface_1_1SWIG_11(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x9015c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x90160 */ stp x20, x19, [sp, #0x10];
    /* 0x90164 */ mov x29, sp;
    /* 0x90168 */ mov w0, #0x18;
    /* 0x9016c */ mov x20, x2;
    _Znwm();
    /* 0x90174 */ mov x19, x0;
    /* 0x90178 */ mov x1, x20;
    sub_901a4();
    /* 0x90180 */ mov x0, x19;
    /* 0x90184 */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_9c5c8();
}
