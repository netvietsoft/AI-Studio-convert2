// Library: libVERenderer.so
// Function ID: libVERenderer::0x38ef4
// Recovered Name: _ZNK10verenderer4Rect7getMidYEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x38ef4 | Size: 24 bytes | SHA256: ca9560522526a5737d747267fe47efcfb48cc5abb2f81c8f54d7dc7a6d00092d
// Callers: 0 | Callees: 0 | Imports: 0


void _ZNK10verenderer4Rect7getMidYEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x38ef4 */ fmov s0, #0.50000000;
    /* 0x38ef8 */ ldr s1, [x0, #0xc];
    /* 0x38efc */ fmul s0, s1, s0;
    /* 0x38f00 */ ldr s1, [x0, #4];
    /* 0x38f04 */ fadd s0, s1, s0;
    return x0;
}
