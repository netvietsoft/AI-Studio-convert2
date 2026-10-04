// Library: libVERenderer.so
// Function ID: libVERenderer::0x43e40
// Recovered Name: _ZN10verenderer4Vec216isSegmentOverlapERKS0_S2_S2_S2_PS0_S3_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x43e40 | Size: 456 bytes | SHA256: 47376172867e54762eede7b085a630503d660a2bf5e8cbeeba0d332975f8c94c
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN10verenderer4Vec216isSegmentOverlapERKS0_S2_S2_S2_PS0_S3_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 114 instructions
    /* 0x43e40 */ ldr s0, [x0];
    /* 0x43e44 */ ldr s1, [x1];
    /* 0x43e48 */ fcmp s0, s1;
    /* 0x43e4c */ b.ne #0x43e60;
    /* 0x43e50 */ ldr s2, [x0, #4];
    /* 0x43e54 */ ldr s3, [x1, #4];
    /* 0x43e58 */ fcmp s2, s3;
    /* 0x43e5c */ b.eq #0x43f3c;
    /* 0x43e60 */ ldr s2, [x2];
    /* 0x43e64 */ ldr s3, [x3];
    /* 0x43e68 */ fcmp s2, s3;
    return x0;
    return x0;
}
