// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x165d5c
// Recovered Name: _ZN14MTFilterKernel26GPUImageGaussianBlurFilter36setBlurRadiusAsFractionOfImageHeightEf
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x165d5c | Size: 44 bytes | SHA256: 6b5c406a8607d9b6522c2524a6319cb06ca5d32fbb9ffd0adab2921f7a87c04e
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN14MTFilterKernel26GPUImageGaussianBlurFilter36setBlurRadiusAsFractionOfImageHeightEf(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x165d5c */ fcmp s0, #0.0;
    /* 0x165d60 */ b.mi #0x165d84;
    /* 0x165d64 */ ldr s1, [x0, #0xe8];
    /* 0x165d68 */ movi d2, #0000000000000000;
    /* 0x165d6c */ str s0, [x0, #0xe8];
    /* 0x165d70 */ str wzr, [x0, #0xe4];
    /* 0x165d74 */ fcmp s1, s0;
    /* 0x165d78 */ fccmp s0, s2, #4, ne;
    /* 0x165d7c */ cset w8, gt;
    /* 0x165d80 */ strb w8, [x0, #0xd8];
    return x0;
}
