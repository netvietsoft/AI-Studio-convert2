// Library: libarkernel3.so
// Function ID: libarkernel3::0x5fdb80
// Recovered Name: sub_5fdb80
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5fdb80 | Size: 132 bytes | SHA256: 4271e1ab217f013e92bc9a16bde98b537e0b863b47a65cc52b0c892d04f9969d
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "ZN8mtlabar310compatible13GPGlobalState18getSegmentEyePupilEiiE3$_1"

void sub_5fdb80(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x5fdb80 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5fdb84 */ stp x22, x21, [sp, #0x10];
    /* 0x5fdb88 */ stp x20, x19, [sp, #0x20];
    /* 0x5fdb8c */ mov x29, sp;
    /* 0x5fdb90 */ ldr x8, [x3];
    /* 0x5fdb94 */ ldr x19, [x0, #8];
    /* 0x5fdb98 */ ldr w21, [x1];
    /* 0x5fdb9c */ ldr w1, [x2];
    /* 0x5fdba0 */ ldrb w22, [x8];
    /* 0x5fdba4 */ mov x0, x19;
    sub_d1a574();
    sub_d1a624();
    return x0;
    return x0;
    return x0;
    return x0;
}
