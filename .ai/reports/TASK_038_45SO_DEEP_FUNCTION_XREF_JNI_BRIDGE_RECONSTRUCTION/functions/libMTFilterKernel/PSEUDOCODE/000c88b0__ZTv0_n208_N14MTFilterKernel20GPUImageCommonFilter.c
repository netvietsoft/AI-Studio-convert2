// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xc88b0
// Recovered Name: _ZTv0_n208_N14MTFilterKernel20GPUImageCommonFilter17isNeedBodySegmentEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xc88b0 | Size: 28 bytes | SHA256: 810cbf4a3a17f962a992a8f0ce588749cb7c95380c54a020ad3fc2da76fe0d2a
// Callers: 0 | Callees: 0 | Imports: 0


void _ZTv0_n208_N14MTFilterKernel20GPUImageCommonFilter17isNeedBodySegmentEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0xc88b0 */ ldr x8, [x0];
    /* 0xc88b4 */ ldur x8, [x8, #-0xd0];
    /* 0xc88b8 */ add x8, x0, x8;
    /* 0xc88bc */ ldr w8, [x8, #0x68];
    /* 0xc88c0 */ cmp w8, #0;
    /* 0xc88c4 */ cset w0, ne;
    return x0;
}
