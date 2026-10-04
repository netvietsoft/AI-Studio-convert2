// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3f94d0
// Recovered Name: _ZN11LayerFlowNS21CLFDenseHairProcessorD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3f94d0 | Size: 36 bytes | SHA256: 336d3fc4ef95a5bd3560b49995676cbd7ab28db1eaf82a2a13e9a8a84caee333
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN11LayerFlowNS21CLFDenseHairProcessorD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x3f94d0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x3f94d4 */ str x19, [sp, #0x10];
    /* 0x3f94d8 */ mov x29, sp;
    /* 0x3f94dc */ mov x19, x0;
    _ZN11LayerFlowNS21CLFDenseHairProcessorD2Ev();
    /* 0x3f94e4 */ mov x0, x19;
    /* 0x3f94e8 */ ldr x19, [sp, #0x10];
    /* 0x3f94ec */ ldp x29, x30, [sp], #0x20;
    /* 0x3f94f0 */ b #0x52a280;
}
