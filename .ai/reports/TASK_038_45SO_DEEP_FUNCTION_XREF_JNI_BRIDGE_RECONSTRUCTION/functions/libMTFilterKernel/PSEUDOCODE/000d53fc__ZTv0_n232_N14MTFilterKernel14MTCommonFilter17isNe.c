// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xd53fc
// Recovered Name: _ZTv0_n232_N14MTFilterKernel14MTCommonFilter17isNeedBodySegmentEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xd53fc | Size: 28 bytes | SHA256: 5c552dbc81685ea3c0ccaeaef56b78175ef659a93f54de45f5cbaa624693d006
// Callers: 0 | Callees: 0 | Imports: 0


void _ZTv0_n232_N14MTFilterKernel14MTCommonFilter17isNeedBodySegmentEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0xd53fc */ ldr x8, [x0];
    /* 0xd5400 */ ldur x8, [x8, #-0xe8];
    /* 0xd5404 */ add x8, x0, x8;
    /* 0xd5408 */ ldr w8, [x8, #0x68];
    /* 0xd540c */ cmp w8, #0;
    /* 0xd5410 */ cset w0, ne;
    return x0;
}
