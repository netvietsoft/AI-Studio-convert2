// Library: libffavc.so
// Function ID: libffavc::0x56378
// Recovered Name: sub_56378
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x56378 | Size: 96 bytes | SHA256: 43f95a96852889dbdc23f09d6704f9504141a6f3cbf2ba0e2d5e5bfe09069259
// Callers: 0 | Callees: 1 | Imports: 0


void sub_56378(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 24 instructions
    /* 0x56378 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x5637c */ str x19, [sp, #0x10];
    /* 0x56380 */ mov x29, sp;
    /* 0x56384 */ mov x8, x0;
    /* 0x56388 */ ldr x0, [x0, #0x10];
    /* 0x5638c */ mov w19, #-2;
    /* 0x56390 */ cbz x0, #0x563c8;
    /* 0x56394 */ ldr x8, [x8, #0x20];
    /* 0x56398 */ str x1, [x8, #0x18];
    /* 0x5639c */ mov x1, x8;
    /* 0x563a0 */ str w2, [x8, #0x20];
    sub_59a30();
    return x0;
}
