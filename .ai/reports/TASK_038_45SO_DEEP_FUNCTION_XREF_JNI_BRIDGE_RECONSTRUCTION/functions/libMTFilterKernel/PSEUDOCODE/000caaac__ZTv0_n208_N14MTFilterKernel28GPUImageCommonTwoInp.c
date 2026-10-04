// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xcaaac
// Recovered Name: _ZTv0_n208_N14MTFilterKernel28GPUImageCommonTwoInputFilter17isNeedBodySegmentEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xcaaac | Size: 20 bytes | SHA256: 3f62cc0467dc791b2fc83495d520c97d4dcb4fd1a68e2e8c8a42d597d58f9f78
// Callers: 0 | Callees: 0 | Imports: 0


void _ZTv0_n208_N14MTFilterKernel28GPUImageCommonTwoInputFilter17isNeedBodySegmentEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0xcaaac */ ldr x8, [x0];
    /* 0xcaab0 */ ldur x8, [x8, #-0xd0];
    /* 0xcaab4 */ add x8, x0, x8;
    /* 0xcaab8 */ add x0, x8, #0x18;
    /* 0xcaabc */ b #0xc88a0;
}
