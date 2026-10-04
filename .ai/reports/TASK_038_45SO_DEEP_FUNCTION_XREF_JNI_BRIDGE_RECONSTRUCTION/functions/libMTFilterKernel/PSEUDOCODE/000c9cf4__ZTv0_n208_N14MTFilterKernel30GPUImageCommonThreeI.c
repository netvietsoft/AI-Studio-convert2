// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xc9cf4
// Recovered Name: _ZTv0_n208_N14MTFilterKernel30GPUImageCommonThreeInputFilter17isNeedBodySegmentEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xc9cf4 | Size: 20 bytes | SHA256: fe3271ec43e75a31a087dc77f946170356e2b08a6df14044591fe68ced3fd77c
// Callers: 0 | Callees: 0 | Imports: 0


void _ZTv0_n208_N14MTFilterKernel30GPUImageCommonThreeInputFilter17isNeedBodySegmentEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0xc9cf4 */ ldr x8, [x0];
    /* 0xc9cf8 */ ldur x8, [x8, #-0xd0];
    /* 0xc9cfc */ add x8, x0, x8;
    /* 0xc9d00 */ add x0, x8, #0x18;
    /* 0xc9d04 */ b #0xc88a0;
}
