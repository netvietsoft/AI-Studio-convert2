// Library: libVERenderer.so
// Function ID: libVERenderer::0x41458
// Recovered Name: _ZN10verenderer8MathUtil19checkPointInSegmentERKNS_4Vec2ES3_S3_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x41458 | Size: 92 bytes | SHA256: 0647ffcf49b621f7736a07c8607d530682ac081a782a77c7607f49e212e4e241
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN10verenderer8MathUtil19checkPointInSegmentERKNS_4Vec2ES3_S3_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x41458 */ ldp s2, s1, [x1];
    /* 0x4145c */ ldr s5, [x2];
    /* 0x41460 */ ldp s3, s0, [x0];
    /* 0x41464 */ fcmp s3, s2;
    /* 0x41468 */ fcsel s4, s2, s3, gt;
    /* 0x4146c */ fcsel s3, s2, s3, mi;
    /* 0x41470 */ fcmp s0, s1;
    /* 0x41474 */ fcsel s2, s1, s0, mi;
    /* 0x41478 */ fcmp s5, s4;
    /* 0x4147c */ fccmp s5, s3, #2, ge;
    /* 0x41480 */ b.ls #0x4148c;
    return x0;
    return x0;
    return x0;
}
