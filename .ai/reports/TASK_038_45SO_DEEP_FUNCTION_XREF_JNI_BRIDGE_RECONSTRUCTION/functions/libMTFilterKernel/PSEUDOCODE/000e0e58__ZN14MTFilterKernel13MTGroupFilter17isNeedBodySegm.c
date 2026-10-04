// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xe0e58
// Recovered Name: _ZN14MTFilterKernel13MTGroupFilter17isNeedBodySegmentEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xe0e58 | Size: 148 bytes | SHA256: 544cb19e092a901263ea42c7ed04a25d66a3971cbb8663c684f87d3d81e81cd2
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN14MTFilterKernel13MTGroupFilter17isNeedBodySegmentEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0xe0e58 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xe0e5c */ stp x20, x19, [sp, #0x10];
    /* 0xe0e60 */ mov x29, sp;
    /* 0xe0e64 */ ldr x20, [x0, #0xb0];
    /* 0xe0e68 */ add x19, x0, #0xb8;
    /* 0xe0e6c */ cmp x20, x19;
    /* 0xe0e70 */ b.ne #0xe0e94;
    /* 0xe0e74 */ mov w0, wzr;
    /* 0xe0e78 */ and w0, w0, #1;
    /* 0xe0e7c */ ldp x20, x19, [sp, #0x10];
    /* 0xe0e80 */ ldp x29, x30, [sp], #0x20;
    return x0;
    return x0;
}
