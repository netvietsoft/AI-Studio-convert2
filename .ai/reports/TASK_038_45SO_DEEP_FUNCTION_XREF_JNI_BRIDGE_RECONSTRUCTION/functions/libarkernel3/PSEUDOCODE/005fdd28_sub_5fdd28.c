// Library: libarkernel3.so
// Function ID: libarkernel3::0x5fdd28
// Recovered Name: sub_5fdd28
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5fdd28 | Size: 120 bytes | SHA256: 606355957207abea236bc74e64cecc6ce182da15f1ed43c75513f794ce4ec209
// Callers: 0 | Callees: 2 | Imports: 0

// Strings referenced:
//   "ZN8mtlabar310compatible13GPGlobalState18getSegmentEyePupilEiiE3$_3"

void sub_5fdd28(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0x5fdd28 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5fdd2c */ str x21, [sp, #0x10];
    /* 0x5fdd30 */ stp x20, x19, [sp, #0x20];
    /* 0x5fdd34 */ mov x29, sp;
    /* 0x5fdd38 */ ldr x19, [x0, #8];
    /* 0x5fdd3c */ ldr w21, [x1];
    /* 0x5fdd40 */ ldr w1, [x2];
    /* 0x5fdd44 */ mov x0, x19;
    sub_d1a574();
    /* 0x5fdd4c */ mov x20, x0;
    /* 0x5fdd50 */ mov x0, x19;
    sub_d1a624();
    return x0;
    return x0;
    return x0;
}
