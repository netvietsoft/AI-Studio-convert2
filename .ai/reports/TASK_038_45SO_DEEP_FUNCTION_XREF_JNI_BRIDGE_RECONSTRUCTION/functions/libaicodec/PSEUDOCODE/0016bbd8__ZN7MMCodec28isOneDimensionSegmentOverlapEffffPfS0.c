// Library: libaicodec.so
// Function ID: libaicodec::0x16bbd8
// Recovered Name: _ZN7MMCodec28isOneDimensionSegmentOverlapEffffPfS0_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x16bbd8 | Size: 160 bytes | SHA256: 82577a4b54d689a50882587bd7af9f1bde7bfe54c7335ffdc2f24c5f5b9fea11
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN7MMCodec28isOneDimensionSegmentOverlapEffffPfS0_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 40 instructions
    /* 0x16bbd8 */ fcmp s1, s0;
    /* 0x16bbdc */ fcsel s5, s1, s0, mi;
    /* 0x16bbe0 */ fcmp s0, s1;
    /* 0x16bbe4 */ fcsel s0, s1, s0, mi;
    /* 0x16bbe8 */ fcmp s3, s2;
    /* 0x16bbec */ fcsel s4, s3, s2, mi;
    /* 0x16bbf0 */ fcmp s2, s3;
    /* 0x16bbf4 */ fcsel s1, s3, s2, mi;
    /* 0x16bbf8 */ fcmp s0, s4;
    /* 0x16bbfc */ cset w8, pl;
    /* 0x16bc00 */ fcmp s1, s5;
    return x0;
    return x0;
    return x0;
}
