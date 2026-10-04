// Library: libVERenderer.so
// Function ID: libVERenderer::0x38368
// Recovered Name: _ZNK10verenderer7Color4FeqERKS0_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x38368 | Size: 76 bytes | SHA256: fd264919049694160d1bd6938a34161226a2e0075b0e5806ca4369b5902cdaa3
// Callers: 0 | Callees: 0 | Imports: 0


void _ZNK10verenderer7Color4FeqERKS0_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x38368 */ ldr s0, [x0];
    /* 0x3836c */ ldr s1, [x1];
    /* 0x38370 */ fcmp s0, s1;
    /* 0x38374 */ b.ne #0x383ac;
    /* 0x38378 */ ldr s0, [x0, #4];
    /* 0x3837c */ ldr s1, [x1, #4];
    /* 0x38380 */ fcmp s0, s1;
    /* 0x38384 */ b.ne #0x383ac;
    /* 0x38388 */ ldr s0, [x0, #8];
    /* 0x3838c */ ldr s1, [x1, #8];
    /* 0x38390 */ fcmp s0, s1;
    return x0;
    return x0;
}
