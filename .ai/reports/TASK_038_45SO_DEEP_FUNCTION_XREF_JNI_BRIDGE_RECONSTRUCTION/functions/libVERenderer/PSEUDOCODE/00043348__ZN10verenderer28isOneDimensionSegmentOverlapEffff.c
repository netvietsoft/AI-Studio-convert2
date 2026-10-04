// Library: libVERenderer.so
// Function ID: libVERenderer::0x43348
// Recovered Name: _ZN10verenderer28isOneDimensionSegmentOverlapEffffPfS0_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x43348 | Size: 152 bytes | SHA256: 354c1b8c7111c2e62557c24e3331a3e78286950f49c7fcfd290131190d390e8a
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN10verenderer28isOneDimensionSegmentOverlapEffffPfS0_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x43348 */ fcmp s1, s0;
    /* 0x4334c */ fcsel s5, s1, s0, mi;
    /* 0x43350 */ fcmp s0, s1;
    /* 0x43354 */ fcsel s0, s1, s0, mi;
    /* 0x43358 */ fcmp s3, s2;
    /* 0x4335c */ fcsel s4, s3, s2, mi;
    /* 0x43360 */ fcmp s2, s3;
    /* 0x43364 */ fcsel s1, s3, s2, mi;
    /* 0x43368 */ fcmp s0, s4;
    /* 0x4336c */ cset w8, pl;
    /* 0x43370 */ fcmp s1, s5;
    return x0;
    return x0;
}
