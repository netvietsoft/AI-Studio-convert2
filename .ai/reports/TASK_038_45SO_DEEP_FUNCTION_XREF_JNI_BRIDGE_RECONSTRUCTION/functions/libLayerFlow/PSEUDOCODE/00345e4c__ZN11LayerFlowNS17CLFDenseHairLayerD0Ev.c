// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x345e4c
// Recovered Name: _ZN11LayerFlowNS17CLFDenseHairLayerD0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x345e4c | Size: 36 bytes | SHA256: 0c06b39cfc73270b7ae8404787bc94d65ca57c149f92fd4e7cbc770cf5781398
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN11LayerFlowNS17CLFDenseHairLayerD0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x345e4c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x345e50 */ str x19, [sp, #0x10];
    /* 0x345e54 */ mov x29, sp;
    /* 0x345e58 */ mov x19, x0;
    _ZN11LayerFlowNS17CLFDenseHairLayerD1Ev();
    /* 0x345e60 */ mov x0, x19;
    /* 0x345e64 */ ldr x19, [sp, #0x10];
    /* 0x345e68 */ ldp x29, x30, [sp], #0x20;
    /* 0x345e6c */ b #0x52a280;
}
