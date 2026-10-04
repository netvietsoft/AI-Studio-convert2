// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x697760
// Recovered Name: sub_697760
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x697760 | Size: 140 bytes | SHA256: 8648fa5c7274041c305751c11a3561d4731a158a8eecb3554a4659cd469c3f20
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeInitBitmapDC(II[BII)V (table at 0x10d56b0)
// Calls external APIs: malloc

jlong sub_697760(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 35 instructions
    /* 0x697760 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x697764 */ stp x26, x25, [sp, #0x10];
    /* 0x697768 */ stp x24, x23, [sp, #0x20];
    /* 0x69776c */ stp x22, x21, [sp, #0x30];
    /* 0x697770 */ stp x20, x19, [sp, #0x40];
    /* 0x697774 */ mov x29, sp;
    /* 0x697778 */ mul w8, w2, w3;
    /* 0x69777c */ mov w19, w6;
    /* 0x697780 */ mov w20, w5;
    /* 0x697784 */ mov x21, x4;
    /* 0x697788 */ mov w22, w3;
    sub_69721c();
    malloc();
}
