// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x13cb90
// Recovered Name: _ZN4Vec216isSegmentOverlapERKS_S1_S1_S1_PS_S2_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x13cb90 | Size: 456 bytes | SHA256: 47376172867e54762eede7b085a630503d660a2bf5e8cbeeba0d332975f8c94c
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN4Vec216isSegmentOverlapERKS_S1_S1_S1_PS_S2_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 114 instructions
    /* 0x13cb90 */ ldr s0, [x0];
    /* 0x13cb94 */ ldr s1, [x1];
    /* 0x13cb98 */ fcmp s0, s1;
    /* 0x13cb9c */ b.ne #0x13cbb0;
    /* 0x13cba0 */ ldr s2, [x0, #4];
    /* 0x13cba4 */ ldr s3, [x1, #4];
    /* 0x13cba8 */ fcmp s2, s3;
    /* 0x13cbac */ b.eq #0x13cc8c;
    /* 0x13cbb0 */ ldr s2, [x2];
    /* 0x13cbb4 */ ldr s3, [x3];
    /* 0x13cbb8 */ fcmp s2, s3;
    return x0;
    return x0;
}
