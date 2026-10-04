// Library: libaicodec.so
// Function ID: libaicodec::0x16c91c
// Recovered Name: _ZN7MMCodec4Vec218isSegmentIntersectERKS0_S2_S2_S2_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x16c91c | Size: 200 bytes | SHA256: 706ee3881d98f2528a9ab19ac721f50f95c32751dd5bb4d9e07ca2d5ed01f52d
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN7MMCodec4Vec218isSegmentIntersectERKS0_S2_S2_S2_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x16c91c */ ldr s0, [x0];
    /* 0x16c920 */ ldr s1, [x1];
    /* 0x16c924 */ fcmp s0, s1;
    /* 0x16c928 */ b.ne #0x16c93c;
    /* 0x16c92c */ ldr s2, [x0, #4];
    /* 0x16c930 */ ldr s3, [x1, #4];
    /* 0x16c934 */ fcmp s2, s3;
    /* 0x16c938 */ b.eq #0x16c9b8;
    /* 0x16c93c */ ldr s2, [x2];
    /* 0x16c940 */ ldr s4, [x3];
    /* 0x16c944 */ fcmp s2, s4;
    return x0;
}
