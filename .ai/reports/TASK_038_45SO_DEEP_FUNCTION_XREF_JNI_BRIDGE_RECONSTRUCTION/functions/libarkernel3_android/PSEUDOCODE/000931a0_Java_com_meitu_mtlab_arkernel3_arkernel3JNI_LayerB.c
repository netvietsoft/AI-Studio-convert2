// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x931a0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1getBorderVertexPosition
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x931a0 | Size: 52 bytes | SHA256: 4748ad3d06959dd3c530d5266c3dcadefe561324cfda6c8fa74a7b34b7c76b9d
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN8mtlabar322LayerBorderInteraction23getBorderVertexPositionENS_15LayerVertexEnumE, _Znwm

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1getBorderVertexPosition(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x931a0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x931a4 */ str x19, [sp, #0x10];
    /* 0x931a8 */ mov x29, sp;
    /* 0x931ac */ mov w1, w4;
    /* 0x931b0 */ mov x0, x2;
    _ZN8mtlabar322LayerBorderInteraction23getBorderVertexPositionENS_15LayerVertexEnumE();
    /* 0x931b8 */ mov x19, x0;
    /* 0x931bc */ mov w0, #8;
    _Znwm();
    /* 0x931c4 */ str x19, [x0];
    /* 0x931c8 */ ldr x19, [sp, #0x10];
    return x0;
}
