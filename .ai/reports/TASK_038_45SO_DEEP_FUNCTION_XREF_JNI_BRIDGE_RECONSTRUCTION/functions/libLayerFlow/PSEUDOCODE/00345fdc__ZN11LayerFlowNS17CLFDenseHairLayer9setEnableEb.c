// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x345fdc
// Recovered Name: _ZN11LayerFlowNS17CLFDenseHairLayer9setEnableEb
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x345fdc | Size: 24 bytes | SHA256: 78f08cc10a140b7d99feee6d6b3c57a3f04e7d097ef84432eb531eeedc8ce74e
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN11LayerFlowNS17CLFDenseHairLayer9setEnableEb(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x345fdc */ ldr w8, [x0, #0x258];
    /* 0x345fe0 */ cmp w8, #0x28;
    /* 0x345fe4 */ b.ne #0x345ff4;
    /* 0x345fe8 */ and w8, w1, #1;
    /* 0x345fec */ strb w8, [x0, #0x38];
    return x0;
}
