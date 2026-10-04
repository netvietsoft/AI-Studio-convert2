// Library: libbmpKit.so
// Function ID: libbmpKit::0x346b0
// Recovered Name: sub_346b0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x346b0 | Size: 48 bytes | SHA256: 7f51895828783d19c563b2cc1b7e5bbd7edbc0ebe24a70d4d35c916aa2ca0432
// Callers: 0 | Callees: 0 | Imports: 0


void sub_346b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x346b0 */ stp x29, x30, [sp, #0x10];
    /* 0x346b4 */ add x29, sp, #0x10;
    /* 0x346b8 */ str x0, [sp, #8];
    /* 0x346bc */ str x1, [sp];
    /* 0x346c0 */ ldr x0, [sp, #8];
    /* 0x346c4 */ ldr x8, [x0];
    /* 0x346c8 */ ldr x8, [x8, #0x30];
    /* 0x346cc */ ldr x1, [sp];
    /* 0x346d0 */ blr x8;
    /* 0x346d4 */ ldp x29, x30, [sp, #0x10];
    /* 0x346d8 */ add sp, sp, #0x20;
    return x0;
}
