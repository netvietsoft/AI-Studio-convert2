// Library: libVERenderer.so
// Function ID: libVERenderer::0x38220
// Recovered Name: _ZN10verenderer7Color3BC2ERKNS_7Color4FE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x38220 | Size: 56 bytes | SHA256: 8359734cdfff1cebb80e86a3ab527c2a654332fa93e15dbe0ced2d3fe1f0acbb
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN10verenderer7Color3BC2ERKNS_7Color4FE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x38220 */ mov w8, #0x437f0000;
    /* 0x38224 */ ldp s0, s2, [x1];
    /* 0x38228 */ fmov s1, w8;
    /* 0x3822c */ ldr s3, [x1, #8];
    /* 0x38230 */ fmul s0, s0, s1;
    /* 0x38234 */ fmul s2, s2, s1;
    /* 0x38238 */ fmul s1, s3, s1;
    /* 0x3823c */ fcvtzs w8, s0;
    /* 0x38240 */ fcvtzs w9, s2;
    /* 0x38244 */ fcvtzs w10, s1;
    /* 0x38248 */ strb w8, [x0];
    return x0;
}
