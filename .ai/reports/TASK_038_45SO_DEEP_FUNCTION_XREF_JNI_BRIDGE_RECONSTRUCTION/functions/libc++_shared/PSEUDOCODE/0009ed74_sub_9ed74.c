// Library: libc++_shared.so
// Function ID: libc++_shared::0x9ed74
// Recovered Name: sub_9ed74
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9ed74 | Size: 52 bytes | SHA256: 0b9017c9289836e2d5a3109e578274c17624ad01c2c6667c2146d269034f57a7
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZNSt8bad_castC1Ev, _ZSt9terminatev

void sub_9ed74(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x9ed74 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x9ed78 */ str x19, [sp, #0x10];
    /* 0x9ed7c */ mov x29, sp;
    /* 0x9ed80 */ mov w0, #8;
    _ZNSt8bad_castC1Ev();
    /* 0x9ed88 */ mov x19, x0;
    _ZSt9terminatev();
    /* 0x9ed90 */ adrp x1, #0x141000;
    /* 0x9ed94 */ adrp x2, #0x141000;
    /* 0x9ed98 */ mov x0, x19;
    /* 0x9ed9c */ ldr x1, [x1, #0x9b0];
    sub_132758();
}
