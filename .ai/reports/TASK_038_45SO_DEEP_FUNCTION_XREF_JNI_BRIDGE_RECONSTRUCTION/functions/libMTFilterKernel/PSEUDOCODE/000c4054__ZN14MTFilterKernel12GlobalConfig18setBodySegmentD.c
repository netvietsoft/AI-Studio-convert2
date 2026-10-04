// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xc4054
// Recovered Name: _ZN14MTFilterKernel12GlobalConfig18setBodySegmentDataEPhiiii
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xc4054 | Size: 468 bytes | SHA256: b481542f555eb27ef9f09988a3fadee4208bf1737ac8af66579236113617a8e1
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: _ZdaPv, _Znam, memcpy

void _ZN14MTFilterKernel12GlobalConfig18setBodySegmentDataEPhiiii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 117 instructions
    /* 0xc4054 */ stp x29, x30, [sp, #-0x40]!;
    /* 0xc4058 */ stp x24, x23, [sp, #0x10];
    /* 0xc405c */ stp x22, x21, [sp, #0x20];
    /* 0xc4060 */ stp x20, x19, [sp, #0x30];
    /* 0xc4064 */ mov x29, sp;
    /* 0xc4068 */ mov x20, x0;
    /* 0xc406c */ ldr x0, [x0, #0xa8];
    /* 0xc4070 */ mov w23, w5;
    /* 0xc4074 */ mov w22, w4;
    /* 0xc4078 */ mov w19, w3;
    /* 0xc407c */ mov w21, w2;
    memcpy();
    return x0;
    _ZdaPv();
    _Znam();
    return x0;
}
