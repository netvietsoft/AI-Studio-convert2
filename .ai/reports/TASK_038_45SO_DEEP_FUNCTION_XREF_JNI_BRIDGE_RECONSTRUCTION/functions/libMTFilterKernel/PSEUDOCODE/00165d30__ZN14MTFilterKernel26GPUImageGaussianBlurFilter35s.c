// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x165d30
// Recovered Name: _ZN14MTFilterKernel26GPUImageGaussianBlurFilter35setBlurRadiusAsFractionOfImageWidthEf
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x165d30 | Size: 44 bytes | SHA256: a1465901fb903f2dd21e97d03f19eef1b2cf41541bee4d74794bade9f5e0f824
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN14MTFilterKernel26GPUImageGaussianBlurFilter35setBlurRadiusAsFractionOfImageWidthEf(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x165d30 */ fcmp s0, #0.0;
    /* 0x165d34 */ b.mi #0x165d58;
    /* 0x165d38 */ ldr s1, [x0, #0xe4];
    /* 0x165d3c */ movi d2, #0000000000000000;
    /* 0x165d40 */ str s0, [x0, #0xe4];
    /* 0x165d44 */ str wzr, [x0, #0xe8];
    /* 0x165d48 */ fcmp s1, s0;
    /* 0x165d4c */ fccmp s0, s2, #4, ne;
    /* 0x165d50 */ cset w8, gt;
    /* 0x165d54 */ strb w8, [x0, #0xd8];
    return x0;
}
