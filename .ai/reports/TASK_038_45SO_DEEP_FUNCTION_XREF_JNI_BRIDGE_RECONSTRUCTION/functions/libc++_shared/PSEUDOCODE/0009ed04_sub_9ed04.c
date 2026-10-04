// Library: libc++_shared.so
// Function ID: libc++_shared::0x9ed04
// Recovered Name: sub_9ed04
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9ed04 | Size: 52 bytes | SHA256: da444c6a62bfa1c057603db26db4fea07f3599647a1626f92e2205ad8a3c47f5
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt8bad_castC1Ev

void sub_9ed04(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x9ed04 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x9ed08 */ str x19, [sp, #0x10];
    /* 0x9ed0c */ mov x29, sp;
    /* 0x9ed10 */ mov w0, #8;
    _ZNSt8bad_castC1Ev();
    /* 0x9ed18 */ mov x19, x0;
    sub_132728();
    /* 0x9ed20 */ adrp x1, #0x141000;
    /* 0x9ed24 */ adrp x2, #0x141000;
    /* 0x9ed28 */ mov x0, x19;
    /* 0x9ed2c */ ldr x1, [x1, #0x990];
    sub_132758();
}
