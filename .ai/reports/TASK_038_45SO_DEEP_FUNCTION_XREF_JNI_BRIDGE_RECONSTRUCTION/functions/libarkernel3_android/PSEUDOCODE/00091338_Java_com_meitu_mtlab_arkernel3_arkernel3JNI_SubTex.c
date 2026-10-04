// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91338
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getTextRect
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91338 | Size: 52 bytes | SHA256: c5b6d0b32027357cf73293ed973150671343eb679703d48de87ce5ad5c399ebe
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction11getTextRectEv, _Znwm

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getTextRect(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x91338 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x9133c */ stp x20, x19, [sp, #0x10];
    /* 0x91340 */ mov x29, sp;
    /* 0x91344 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction11getTextRectEv();
    /* 0x9134c */ mov x19, x0;
    /* 0x91350 */ mov w0, #0x10;
    /* 0x91354 */ mov x20, x1;
    _Znwm();
    /* 0x9135c */ stp x19, x20, [x0];
    /* 0x91360 */ ldp x20, x19, [sp, #0x10];
    return x0;
}
