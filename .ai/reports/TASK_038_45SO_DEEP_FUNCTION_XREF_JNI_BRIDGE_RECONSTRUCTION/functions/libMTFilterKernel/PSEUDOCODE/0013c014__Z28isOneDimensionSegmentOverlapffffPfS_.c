// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x13c014
// Recovered Name: _Z28isOneDimensionSegmentOverlapffffPfS_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x13c014 | Size: 160 bytes | SHA256: 82577a4b54d689a50882587bd7af9f1bde7bfe54c7335ffdc2f24c5f5b9fea11
// Callers: 0 | Callees: 0 | Imports: 0


void _Z28isOneDimensionSegmentOverlapffffPfS_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 40 instructions
    /* 0x13c014 */ fcmp s1, s0;
    /* 0x13c018 */ fcsel s5, s1, s0, mi;
    /* 0x13c01c */ fcmp s0, s1;
    /* 0x13c020 */ fcsel s0, s1, s0, mi;
    /* 0x13c024 */ fcmp s3, s2;
    /* 0x13c028 */ fcsel s4, s3, s2, mi;
    /* 0x13c02c */ fcmp s2, s3;
    /* 0x13c030 */ fcsel s1, s3, s2, mi;
    /* 0x13c034 */ fcmp s0, s4;
    /* 0x13c038 */ cset w8, pl;
    /* 0x13c03c */ fcmp s1, s5;
    return x0;
    return x0;
    return x0;
}
