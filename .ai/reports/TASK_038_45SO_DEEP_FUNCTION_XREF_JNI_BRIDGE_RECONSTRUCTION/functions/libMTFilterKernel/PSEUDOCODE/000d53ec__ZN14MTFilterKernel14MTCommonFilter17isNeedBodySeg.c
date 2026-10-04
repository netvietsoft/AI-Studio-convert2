// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xd53ec
// Recovered Name: _ZN14MTFilterKernel14MTCommonFilter17isNeedBodySegmentEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xd53ec | Size: 16 bytes | SHA256: 4e7a5e8bcdc893af7f308cab6ea9f87ef417b2cc1864559ce4575606ab356bb5
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN14MTFilterKernel14MTCommonFilter17isNeedBodySegmentEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0xd53ec */ ldr w8, [x0, #0x68];
    /* 0xd53f0 */ cmp w8, #0;
    /* 0xd53f4 */ cset w0, ne;
    return x0;
}
