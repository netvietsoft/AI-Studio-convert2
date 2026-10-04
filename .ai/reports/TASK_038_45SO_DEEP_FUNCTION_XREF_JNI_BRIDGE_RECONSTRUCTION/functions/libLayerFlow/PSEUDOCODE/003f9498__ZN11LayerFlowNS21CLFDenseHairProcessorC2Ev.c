// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3f9498
// Recovered Name: _ZN11LayerFlowNS21CLFDenseHairProcessorC2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3f9498 | Size: 52 bytes | SHA256: dfdd3ee53f6c29382ef6f159dd9208991d2d3f0fe3d2bae45a5e0da74145cfe3
// Callers: 1 | Callees: 0 | Imports: 0


void _ZN11LayerFlowNS21CLFDenseHairProcessorC2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x3f9498 */ mov w9, #0x3332;
    /* 0x3f949c */ mov w8, #6;
    /* 0x3f94a0 */ movi v0.2d, #0000000000000000;
    /* 0x3f94a4 */ movk w9, #0x30, lsl #16;
    /* 0x3f94a8 */ strb w8, [x0, #8];
    /* 0x3f94ac */ adrp x8, #0x54b000;
    /* 0x3f94b0 */ stur w9, [x0, #9];
    /* 0x3f94b4 */ ldr x8, [x8, #0x170];
    /* 0x3f94b8 */ stp q0, q0, [x0, #0x20];
    /* 0x3f94bc */ add x8, x8, #0x10;
    /* 0x3f94c0 */ str q0, [x0, #0x40];
    return x0;
}
