// Library: libarkernel3.so
// Function ID: libarkernel3::0x5fdc54
// Recovered Name: sub_5fdc54
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5fdc54 | Size: 132 bytes | SHA256: 87d8c2b51f88566d3e1257f03f0865f1d48d0289aa8fa2c88541f7cf7f135d88
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "ZN8mtlabar310compatible13GPGlobalState18getSegmentEyePupilEiiE3$_2"

void sub_5fdc54(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x5fdc54 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5fdc58 */ stp x22, x21, [sp, #0x10];
    /* 0x5fdc5c */ stp x20, x19, [sp, #0x20];
    /* 0x5fdc60 */ mov x29, sp;
    /* 0x5fdc64 */ ldr x8, [x3];
    /* 0x5fdc68 */ ldr x19, [x0, #8];
    /* 0x5fdc6c */ ldr w21, [x1];
    /* 0x5fdc70 */ ldr w1, [x2];
    /* 0x5fdc74 */ ldrb w22, [x8];
    /* 0x5fdc78 */ mov x0, x19;
    sub_d1a574();
    sub_d1a624();
    return x0;
    return x0;
    return x0;
    return x0;
}
