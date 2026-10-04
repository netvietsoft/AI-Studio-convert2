// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xc44d0
// Recovered Name: _Z25MTARFPMSetBodySegmentDataPvPhiii
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xc44d0 | Size: 32 bytes | SHA256: c3190a5b113184ae30e0889fd09d1b7202dd20e5f71578d03c176fd6fdc97102
// Callers: 0 | Callees: 0 | Imports: 0


void _Z25MTARFPMSetBodySegmentDataPvPhiii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0xc44d0 */ cbz x0, #0xc44ec;
    /* 0xc44d4 */ mov w8, w2;
    /* 0xc44d8 */ mov w2, w3;
    /* 0xc44dc */ mov w3, w4;
    /* 0xc44e0 */ mov w4, w8;
    /* 0xc44e4 */ mov w5, wzr;
    /* 0xc44e8 */ b #0x1aa50c;
    return x0;
}
