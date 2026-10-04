// Library: libffavc.so
// Function ID: libffavc::0x56508
// Recovered Name: sub_56508
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x56508 | Size: 64 bytes | SHA256: 0d3143947efd1606fdc0f383bd68aa096683b9f4952b76ee9c970f5f262c1722
// Callers: 0 | Callees: 0 | Imports: 0


void sub_56508(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x56508 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x5650c */ str x19, [sp, #0x10];
    /* 0x56510 */ mov x29, sp;
    /* 0x56514 */ mov w0, #0x28;
    /* 0x56518 */ mov x19, x8;
    sub_101628();
    /* 0x56520 */ movi v0.2d, #0000000000000000;
    /* 0x56524 */ adrp x8, #0x105000;
    /* 0x56528 */ add x8, x8, #0xd18;
    /* 0x5652c */ str x8, [x0];
    /* 0x56530 */ stur q0, [x0, #8];
    return x0;
}
