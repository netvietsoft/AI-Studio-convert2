// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x560068
// Recovered Name: sub_560068
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x560068 | Size: 768 bytes | SHA256: 1809ddceadfbf074b3c82888e6c32cce711cffde5590803c5ec8ac92cbb5bacd
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nativeSetInstantPlacementInfo(J[FI[FI)V (table at 0x10cc470)
// Calls external APIs: _Znam, memset

jlong sub_560068(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 192 instructions
    /* 0x560068 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x56006c */ stp x28, x27, [sp, #0x10];
    /* 0x560070 */ stp x26, x25, [sp, #0x20];
    /* 0x560074 */ stp x24, x23, [sp, #0x30];
    /* 0x560078 */ stp x22, x21, [sp, #0x40];
    /* 0x56007c */ stp x20, x19, [sp, #0x50];
    /* 0x560080 */ mov x29, sp;
    /* 0x560084 */ cbz x2, #0x560318;
    /* 0x560088 */ add x8, x2, #0x11, lsl #12;
    /* 0x56008c */ mov w21, w6;
    /* 0x560090 */ mov x19, x5;
    _Znam();
    memset();
    _Znam();
    memset();
    return x0;
}
