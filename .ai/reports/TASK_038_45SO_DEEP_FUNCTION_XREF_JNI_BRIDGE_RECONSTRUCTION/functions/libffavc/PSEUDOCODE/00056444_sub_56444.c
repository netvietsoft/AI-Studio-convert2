// Library: libffavc.so
// Function ID: libffavc::0x56444
// Recovered Name: sub_56444
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x56444 | Size: 100 bytes | SHA256: 42d7d8d71d21818b0f95d69ac33efa5da6becef721eacb41ea779142e511aa02
// Callers: 0 | Callees: 0 | Imports: 0


void sub_56444(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 25 instructions
    /* 0x56444 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x56448 */ stp x20, x19, [sp, #0x10];
    /* 0x5644c */ mov x29, sp;
    /* 0x56450 */ mov x19, x0;
    /* 0x56454 */ mov w0, #0x28;
    /* 0x56458 */ mov x20, x8;
    sub_101628();
    /* 0x56460 */ movi v0.2d, #0000000000000000;
    /* 0x56464 */ ldr x9, [x19, #0x18];
    /* 0x56468 */ mov x8, xzr;
    /* 0x5646c */ str xzr, [x0, #0x20];
    return x0;
}
