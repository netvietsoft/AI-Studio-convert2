// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91b30
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getSubLayerVertex
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91b30 | Size: 52 bytes | SHA256: 24984211a9bc0b97fef9fa9382fa232f91213d119ad9290aa0cd0da854a86696
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction17getSubLayerVertexENS_15LayerVertexEnumE, _Znwm

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getSubLayerVertex(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x91b30 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x91b34 */ str x19, [sp, #0x10];
    /* 0x91b38 */ mov x29, sp;
    /* 0x91b3c */ mov w1, w4;
    /* 0x91b40 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction17getSubLayerVertexENS_15LayerVertexEnumE();
    /* 0x91b48 */ mov x19, x0;
    /* 0x91b4c */ mov w0, #8;
    _Znwm();
    /* 0x91b54 */ str x19, [x0];
    /* 0x91b58 */ ldr x19, [sp, #0x10];
    return x0;
}
