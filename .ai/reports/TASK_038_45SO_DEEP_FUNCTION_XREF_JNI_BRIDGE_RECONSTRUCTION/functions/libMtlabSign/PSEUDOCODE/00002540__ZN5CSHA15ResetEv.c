// Library: libMtlabSign.so
// Function ID: libMtlabSign::0x2540
// Recovered Name: _ZN5CSHA15ResetEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x2540 | Size: 32 bytes | SHA256: a3ffb4712d6396b9826b3bf99c41c6606e37e5a32d4a9512f2ada2aab863dd69
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN5CSHA15ResetEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2540 */ adrp x8, #0x1000;
    /* 0x2544 */ adrp x9, #0x1000;
    /* 0x2548 */ str wzr, [x0, #0x18];
    /* 0x254c */ ldr q0, [x8, #0x670];
    /* 0x2550 */ ldr d1, [x9, #0x680];
    /* 0x2554 */ str q0, [x0];
    /* 0x2558 */ str d1, [x0, #0x10];
    return x0;
}
