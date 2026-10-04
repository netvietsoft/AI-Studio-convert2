// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x13cd58
// Recovered Name: _ZN4Vec218isSegmentIntersectERKS_S1_S1_S1_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x13cd58 | Size: 200 bytes | SHA256: 706ee3881d98f2528a9ab19ac721f50f95c32751dd5bb4d9e07ca2d5ed01f52d
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN4Vec218isSegmentIntersectERKS_S1_S1_S1_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x13cd58 */ ldr s0, [x0];
    /* 0x13cd5c */ ldr s1, [x1];
    /* 0x13cd60 */ fcmp s0, s1;
    /* 0x13cd64 */ b.ne #0x13cd78;
    /* 0x13cd68 */ ldr s2, [x0, #4];
    /* 0x13cd6c */ ldr s3, [x1, #4];
    /* 0x13cd70 */ fcmp s2, s3;
    /* 0x13cd74 */ b.eq #0x13cdf4;
    /* 0x13cd78 */ ldr s2, [x2];
    /* 0x13cd7c */ ldr s4, [x3];
    /* 0x13cd80 */ fcmp s2, s4;
    return x0;
}
