// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xe30e4
// Recovered Name: _ZTv0_n232_N14MTFilterKernel18MTImageBlendFilter17isNeedBodySegmentEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xe30e4 | Size: 28 bytes | SHA256: 5bb709e7d97a9f96ddbfbdfde6e9ed6dd33522f73fcd55893855d2d230f1ba3f
// Callers: 0 | Callees: 0 | Imports: 0


void _ZTv0_n232_N14MTFilterKernel18MTImageBlendFilter17isNeedBodySegmentEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0xe30e4 */ ldr x8, [x0];
    /* 0xe30e8 */ ldur x8, [x8, #-0xe8];
    /* 0xe30ec */ add x8, x0, x8;
    /* 0xe30f0 */ ldr w8, [x8, #0x40];
    /* 0xe30f4 */ cmp w8, #0;
    /* 0xe30f8 */ cset w0, gt;
    return x0;
}
