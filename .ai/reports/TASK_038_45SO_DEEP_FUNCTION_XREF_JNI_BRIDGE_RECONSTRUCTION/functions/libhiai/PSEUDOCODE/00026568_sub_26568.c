// Library: libhiai.so
// Function ID: libhiai::0x26568
// Recovered Name: sub_26568
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x26568 | Size: 108 bytes | SHA256: 86f8f9ffc5cbdad1fe01bb6846b242c8ff4dc45ac938ed4795530ebec0fa02da
// Callers: 1 | Callees: 1 | Imports: 3

// Calls external APIs: __cxa_atexit, __cxa_guard_acquire, __cxa_guard_release

void sub_26568(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x26568 */ stp x30, x19, [sp, #-0x10]!;
    /* 0x2656c */ nop ;
    /* 0x26570 */ adr x8, #0x787f8;
    /* 0x26574 */ ldarb w8, [x8];
    /* 0x26578 */ tbz w8, #0, #0x2658c;
    /* 0x2657c */ nop ;
    /* 0x26580 */ adr x0, #0x787f0;
    /* 0x26584 */ ldp x30, x19, [sp], #0x10;
    return x0;
    /* 0x2658c */ nop ;
    /* 0x26590 */ adr x0, #0x787f8;
    __cxa_guard_acquire();
    sub_265d4();
    __cxa_atexit();
    __cxa_guard_release();
}
