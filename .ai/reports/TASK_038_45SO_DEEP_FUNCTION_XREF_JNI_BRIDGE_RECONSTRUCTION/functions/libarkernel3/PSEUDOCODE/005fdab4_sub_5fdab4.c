// Library: libarkernel3.so
// Function ID: libarkernel3::0x5fdab4
// Recovered Name: sub_5fdab4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5fdab4 | Size: 124 bytes | SHA256: 74bd7636e5a9e0bdd83b877158795abfcf62a38be77475dc17f8a23616f30d3a
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "ZN8mtlabar310compatible13GPGlobalState18getSegmentEyePupilEiiE3$_0"

void sub_5fdab4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 31 instructions
    /* 0x5fdab4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5fdab8 */ stp x22, x21, [sp, #0x10];
    /* 0x5fdabc */ stp x20, x19, [sp, #0x20];
    /* 0x5fdac0 */ mov x29, sp;
    /* 0x5fdac4 */ ldr x8, [x3];
    /* 0x5fdac8 */ ldr x19, [x0, #8];
    /* 0x5fdacc */ ldr w21, [x1];
    /* 0x5fdad0 */ ldr w1, [x2];
    /* 0x5fdad4 */ ldrb w22, [x8];
    /* 0x5fdad8 */ mov x0, x19;
    sub_d1a574();
    sub_d1a624();
    return x0;
    return x0;
    return x0;
}
