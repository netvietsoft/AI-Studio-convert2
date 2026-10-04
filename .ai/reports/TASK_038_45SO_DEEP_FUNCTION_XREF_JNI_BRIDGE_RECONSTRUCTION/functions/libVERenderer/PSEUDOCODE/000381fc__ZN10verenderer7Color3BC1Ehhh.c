// Library: libVERenderer.so
// Function ID: libVERenderer::0x381fc
// Recovered Name: _ZN10verenderer7Color3BC1Ehhh
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x381fc | Size: 16 bytes | SHA256: e39964c33ecc33a0673fdb272c9437e89d4aa514d24add2a4303c2024b6ad601
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN10verenderer7Color3BC1Ehhh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x381fc */ strb w1, [x0];
    /* 0x38200 */ strb w2, [x0, #1];
    /* 0x38204 */ strb w3, [x0, #2];
    return x0;
}
