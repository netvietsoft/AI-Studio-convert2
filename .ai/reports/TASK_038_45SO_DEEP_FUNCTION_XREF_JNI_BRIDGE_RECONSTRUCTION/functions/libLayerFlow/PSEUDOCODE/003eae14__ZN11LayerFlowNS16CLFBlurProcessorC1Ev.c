// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3eae14
// Recovered Name: _ZN11LayerFlowNS16CLFBlurProcessorC1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3eae14 | Size: 56 bytes | SHA256: 4c9d9c7b1e7e2320e05ebd2c118c0105eea367c95b168c89354779590aa0299c
// Callers: 1 | Callees: 0 | Imports: 0


void _ZN11LayerFlowNS16CLFBlurProcessorC1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x3eae14 */ mov w9, #0x6c62;
    /* 0x3eae18 */ mov w8, #8;
    /* 0x3eae1c */ movi v0.2d, #0000000000000000;
    /* 0x3eae20 */ movk w9, #0x7275, lsl #16;
    /* 0x3eae24 */ strb w8, [x0, #8];
    /* 0x3eae28 */ adrp x8, #0x54b000;
    /* 0x3eae2c */ stur w9, [x0, #9];
    /* 0x3eae30 */ strb wzr, [x0, #0xd];
    /* 0x3eae34 */ ldr x8, [x8, #0xc8];
    /* 0x3eae38 */ stp q0, q0, [x0, #0x20];
    /* 0x3eae3c */ str q0, [x0, #0x40];
    return x0;
}
