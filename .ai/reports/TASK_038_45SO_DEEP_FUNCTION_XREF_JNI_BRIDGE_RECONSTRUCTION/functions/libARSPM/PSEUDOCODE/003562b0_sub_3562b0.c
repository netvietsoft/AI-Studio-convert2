// Library: libARSPM.so
// Function ID: libARSPM::0x3562b0
// Recovered Name: sub_3562b0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3562b0 | Size: 768 bytes | SHA256: 18b3ec885f4ad5e4eb419e5162da789b892e6205ccd987dd2e17426c73335c00
// Callers: 0 | Callees: 11 | Imports: 0

// Strings referenced:
//   "%s = %s;"
//   "Coverage"
//   "HairQuadEdge"
//   "edgeAlpha = half(%s.x * %s.x - %s.y);"
//   "edgeAlpha = max(1.0 - edgeAlpha, 0.0);"

void sub_3562b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 192 instructions
    /* 0x3562b0 */ stp x29, x30, [sp, #0x40];
    /* 0x3562b4 */ str x27, [sp, #0x50];
    /* 0x3562b8 */ stp x26, x25, [sp, #0x60];
    /* 0x3562bc */ stp x24, x23, [sp, #0x70];
    /* 0x3562c0 */ stp x22, x21, [sp, #0x80];
    /* 0x3562c4 */ stp x20, x19, [sp, #0x90];
    /* 0x3562c8 */ add x29, sp, #0x40;
    /* 0x3562cc */ ldp x22, x21, [x1, #0x10];
    /* 0x3562d0 */ mov x19, x1;
    /* 0x3562d4 */ ldr x23, [x1, #0x28];
    /* 0x3562d8 */ ldr x25, [x1];
    sub_3439bc();
    sub_343850();
    sub_2d1b70();
    sub_2d1b70();
    sub_340bb4();
    sub_340ed4();
    sub_1d8fb8();
    sub_1d91c4();
    sub_1d8fa8();
    sub_1d8fa8();
    sub_1d93f8();
    sub_341208();
    sub_1d93f8();
    sub_1d93f8();
    sub_1d93f8();
    sub_2d1b70();
    sub_2d1b70();
    sub_2d1b70();
    sub_2d1b70();
    sub_2d1b70();
    sub_1d99c4();
    sub_1d99c4();
    sub_2d1b70();
    sub_2d1b70();
    return x0;
    return x0;
}
