// Library: libVERenderer.so
// Function ID: libVERenderer::0x44008
// Recovered Name: _ZN10verenderer4Vec218isSegmentIntersectERKS0_S2_S2_S2_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x44008 | Size: 200 bytes | SHA256: 706ee3881d98f2528a9ab19ac721f50f95c32751dd5bb4d9e07ca2d5ed01f52d
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN10verenderer4Vec218isSegmentIntersectERKS0_S2_S2_S2_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x44008 */ ldr s0, [x0];
    /* 0x4400c */ ldr s1, [x1];
    /* 0x44010 */ fcmp s0, s1;
    /* 0x44014 */ b.ne #0x44028;
    /* 0x44018 */ ldr s2, [x0, #4];
    /* 0x4401c */ ldr s3, [x1, #4];
    /* 0x44020 */ fcmp s2, s3;
    /* 0x44024 */ b.eq #0x440a4;
    /* 0x44028 */ ldr s2, [x2];
    /* 0x4402c */ ldr s4, [x3];
    /* 0x44030 */ fcmp s2, s4;
    return x0;
}
