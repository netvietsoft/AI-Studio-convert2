// Library: libVERenderer.so
// Function ID: libVERenderer::0x3820c
// Recovered Name: _ZN10verenderer7Color3BC2ERKNS_7Color4BE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3820c | Size: 20 bytes | SHA256: ce28e19be76198851d71c147696537a3157633a54fdc1bfe734d4f8a27f53b62
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN10verenderer7Color3BC2ERKNS_7Color4BE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x3820c */ ldrb w8, [x1];
    /* 0x38210 */ strb w8, [x0];
    /* 0x38214 */ ldurh w8, [x1, #1];
    /* 0x38218 */ sturh w8, [x0, #1];
    return x0;
}
