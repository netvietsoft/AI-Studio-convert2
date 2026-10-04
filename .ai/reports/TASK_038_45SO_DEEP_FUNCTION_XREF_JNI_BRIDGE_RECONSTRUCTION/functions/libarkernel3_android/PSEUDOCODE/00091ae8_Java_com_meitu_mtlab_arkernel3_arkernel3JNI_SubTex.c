// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91ae8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1flipTextRect
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91ae8 | Size: 52 bytes | SHA256: c01ad180a76b8dac13285d5aedad0aa8c5fe1093ec65442e41e2b52473034b62
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction12flipTextRectEv, _Znwm

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1flipTextRect(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x91ae8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x91aec */ stp x20, x19, [sp, #0x10];
    /* 0x91af0 */ mov x29, sp;
    /* 0x91af4 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction12flipTextRectEv();
    /* 0x91afc */ mov x19, x0;
    /* 0x91b00 */ mov w0, #0x10;
    /* 0x91b04 */ mov x20, x1;
    _Znwm();
    /* 0x91b0c */ stp x19, x20, [x0];
    /* 0x91b10 */ ldp x20, x19, [sp, #0x10];
    return x0;
}
