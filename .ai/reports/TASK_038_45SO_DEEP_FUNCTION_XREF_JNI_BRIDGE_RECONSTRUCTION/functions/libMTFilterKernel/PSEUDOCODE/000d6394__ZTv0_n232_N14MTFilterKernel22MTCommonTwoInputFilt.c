// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xd6394
// Recovered Name: _ZTv0_n232_N14MTFilterKernel22MTCommonTwoInputFilter17isNeedBodySegmentEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xd6394 | Size: 20 bytes | SHA256: e2fe6ebe3bd578c8c4e66964f86cab339fff8cdf4381d2aca97aa6138a2208f4
// Callers: 0 | Callees: 0 | Imports: 0


void _ZTv0_n232_N14MTFilterKernel22MTCommonTwoInputFilter17isNeedBodySegmentEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0xd6394 */ ldr x8, [x0];
    /* 0xd6398 */ ldur x8, [x8, #-0xe8];
    /* 0xd639c */ add x8, x0, x8;
    /* 0xd63a0 */ add x0, x8, #0x18;
    /* 0xd63a4 */ b #0xd53ec;
}
