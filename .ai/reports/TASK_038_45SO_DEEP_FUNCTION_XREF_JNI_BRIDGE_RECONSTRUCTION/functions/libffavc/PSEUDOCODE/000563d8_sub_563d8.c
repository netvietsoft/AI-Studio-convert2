// Library: libffavc.so
// Function ID: libffavc::0x563d8
// Recovered Name: sub_563d8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x563d8 | Size: 108 bytes | SHA256: 26b48f48898fb1827e74b2035abcf0adcec2584862c902962719a0db15e3ba6f
// Callers: 0 | Callees: 1 | Imports: 0


void sub_563d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x563d8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x563dc */ str x19, [sp, #0x10];
    /* 0x563e0 */ mov x29, sp;
    /* 0x563e4 */ mov x19, x0;
    /* 0x563e8 */ ldr x0, [x0, #0x10];
    /* 0x563ec */ ldr x1, [x19, #0x18];
    sub_57600();
    /* 0x563f4 */ tbnz w0, #0x1f, #0x5640c;
    /* 0x563f8 */ ldr x8, [x19, #0x18];
    /* 0x563fc */ ldr x8, [x8];
    /* 0x56400 */ cbz x8, #0x5640c;
    return x0;
}
