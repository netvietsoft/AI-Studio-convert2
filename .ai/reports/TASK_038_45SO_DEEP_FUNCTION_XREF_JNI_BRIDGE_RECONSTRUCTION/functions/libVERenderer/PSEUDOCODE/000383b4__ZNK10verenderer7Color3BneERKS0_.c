// Library: libVERenderer.so
// Function ID: libVERenderer::0x383b4
// Recovered Name: _ZNK10verenderer7Color3BneERKS0_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x383b4 | Size: 60 bytes | SHA256: 818969925ad177d3628ccbbc0e6f68204369b3b32f5ca6776d4d1fda6a66c7d8
// Callers: 0 | Callees: 0 | Imports: 0


void _ZNK10verenderer7Color3BneERKS0_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x383b4 */ ldrb w8, [x0];
    /* 0x383b8 */ ldrb w9, [x1];
    /* 0x383bc */ cmp w8, w9;
    /* 0x383c0 */ b.ne #0x383e8;
    /* 0x383c4 */ ldrb w8, [x0, #1];
    /* 0x383c8 */ ldrb w9, [x1, #1];
    /* 0x383cc */ cmp w8, w9;
    /* 0x383d0 */ b.ne #0x383e8;
    /* 0x383d4 */ ldrb w8, [x0, #2];
    /* 0x383d8 */ ldrb w9, [x1, #2];
    /* 0x383dc */ cmp w8, w9;
    return x0;
    return x0;
}
