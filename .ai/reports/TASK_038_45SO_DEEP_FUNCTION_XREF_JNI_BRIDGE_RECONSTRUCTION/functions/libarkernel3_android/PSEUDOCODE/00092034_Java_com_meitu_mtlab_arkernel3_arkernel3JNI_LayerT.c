// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92034
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1getGlobalColorValue
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92034 | Size: 72 bytes | SHA256: 27a332eb154005ae44b00dc590fc2577984515917dcc2ae3c50a13a1967da7d9
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN8mtlabar320LayerTextInteraction19getGlobalColorValueEv, _Znwm

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1getGlobalColorValue(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x92034 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x92038 */ stp x22, x21, [sp, #0x10];
    /* 0x9203c */ stp x20, x19, [sp, #0x20];
    /* 0x92040 */ mov x29, sp;
    /* 0x92044 */ mov x0, x2;
    _ZN8mtlabar320LayerTextInteraction19getGlobalColorValueEv();
    /* 0x9204c */ mov x19, x0;
    /* 0x92050 */ lsr x21, x0, #0x20;
    /* 0x92054 */ mov w0, #0x10;
    /* 0x92058 */ mov x20, x1;
    /* 0x9205c */ lsr x22, x1, #0x20;
    _Znwm();
    return x0;
}
