// Library: libffavc.so
// Function ID: libffavc::0x560f0
// Recovered Name: sub_560f0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x560f0 | Size: 92 bytes | SHA256: 07cf801331a6bb4a66a35c0f2b196036b575cec2b460a8b9ee0511c53b82e7fc
// Callers: 1 | Callees: 2 | Imports: 0


void sub_560f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x560f0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x560f4 */ stp x20, x19, [sp, #0x10];
    /* 0x560f8 */ mov x29, sp;
    /* 0x560fc */ mov x20, x0;
    /* 0x56100 */ mov x19, x0;
    /* 0x56104 */ ldr x8, [x20, #0x10]!;
    /* 0x56108 */ cbz x8, #0x56118;
    /* 0x5610c */ mov x0, x20;
    sub_c6958();
    /* 0x56114 */ str xzr, [x20];
    /* 0x56118 */ mov x0, x19;
    sub_d3a0c();
    return x0;
}
