// Library: libMtlabSign.so
// Function ID: libMtlabSign::0x2518
// Recovered Name: _ZN5CSHA1C2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x2518 | Size: 40 bytes | SHA256: 6f3c558584900d2f3332714c3f88a3a9ddc0c96730188787c7c5a03f587ed9cc
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN5CSHA1C2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x2518 */ adrp x8, #0x1000;
    /* 0x251c */ adrp x9, #0x1000;
    /* 0x2520 */ add x10, x0, #0x80;
    /* 0x2524 */ ldr q0, [x8, #0x670];
    /* 0x2528 */ ldr d1, [x9, #0x680];
    /* 0x252c */ str x10, [x0, #0xc0];
    /* 0x2530 */ str wzr, [x0, #0x18];
    /* 0x2534 */ str q0, [x0];
    /* 0x2538 */ str d1, [x0, #0x10];
    return x0;
}
