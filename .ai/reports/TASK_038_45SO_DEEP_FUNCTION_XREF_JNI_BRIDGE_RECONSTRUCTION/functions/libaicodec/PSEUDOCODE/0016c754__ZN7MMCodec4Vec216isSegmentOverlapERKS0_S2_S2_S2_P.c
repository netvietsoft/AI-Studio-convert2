// Library: libaicodec.so
// Function ID: libaicodec::0x16c754
// Recovered Name: _ZN7MMCodec4Vec216isSegmentOverlapERKS0_S2_S2_S2_PS0_S3_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x16c754 | Size: 456 bytes | SHA256: 47376172867e54762eede7b085a630503d660a2bf5e8cbeeba0d332975f8c94c
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN7MMCodec4Vec216isSegmentOverlapERKS0_S2_S2_S2_PS0_S3_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 114 instructions
    /* 0x16c754 */ ldr s0, [x0];
    /* 0x16c758 */ ldr s1, [x1];
    /* 0x16c75c */ fcmp s0, s1;
    /* 0x16c760 */ b.ne #0x16c774;
    /* 0x16c764 */ ldr s2, [x0, #4];
    /* 0x16c768 */ ldr s3, [x1, #4];
    /* 0x16c76c */ fcmp s2, s3;
    /* 0x16c770 */ b.eq #0x16c850;
    /* 0x16c774 */ ldr s2, [x2];
    /* 0x16c778 */ ldr s3, [x3];
    /* 0x16c77c */ fcmp s2, s3;
    return x0;
    return x0;
}
