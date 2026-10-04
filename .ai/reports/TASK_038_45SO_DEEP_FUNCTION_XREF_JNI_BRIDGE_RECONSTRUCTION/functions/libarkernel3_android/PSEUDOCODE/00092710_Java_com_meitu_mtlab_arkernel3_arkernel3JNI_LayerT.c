// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92710
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextBGTextureInteraction_1getColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92710 | Size: 72 bytes | SHA256: dd801ec34e66774df9c20c27e37d7436e74aa3a03cc6f710cf58dc94cbb100bf
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN8mtlabar329LayerTextBGTextureInteraction8getColorEv, _Znwm

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextBGTextureInteraction_1getColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x92710 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x92714 */ stp x22, x21, [sp, #0x10];
    /* 0x92718 */ stp x20, x19, [sp, #0x20];
    /* 0x9271c */ mov x29, sp;
    /* 0x92720 */ mov x0, x2;
    _ZN8mtlabar329LayerTextBGTextureInteraction8getColorEv();
    /* 0x92728 */ mov x19, x0;
    /* 0x9272c */ lsr x21, x0, #0x20;
    /* 0x92730 */ mov w0, #0x10;
    /* 0x92734 */ mov x20, x1;
    /* 0x92738 */ lsr x22, x1, #0x20;
    _Znwm();
    return x0;
}
