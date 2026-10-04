// Library: libARSPM.so
// Function ID: libARSPM::0x12ce04
// Recovered Name: sub_12ce04
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x12ce04 | Size: 256 bytes | SHA256: 04d6760e96a99c893c46fbd8ad47adfe1e633b2e0c69c9e8519755da4312801b
// Callers: 2 | Callees: 2 | Imports: 0


void sub_12ce04(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 64 instructions
    /* 0x12ce04 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x12ce08 */ stp x20, x19, [sp, #0x10];
    /* 0x12ce0c */ mov x29, sp;
    /* 0x12ce10 */ ldp s2, s3, [x0, #8];
    /* 0x12ce14 */ mov x19, x0;
    /* 0x12ce18 */ mov x20, x1;
    /* 0x12ce1c */ fcmp s0, s2;
    /* 0x12ce20 */ fccmp s1, s3, #0, eq;
    /* 0x12ce24 */ b.eq #0x12ced8;
    /* 0x12ce28 */ ldr s2, [x19, #0x10];
    /* 0x12ce2c */ fcmp s2, #0.0;
    sub_13a594();
    sub_46af0c();
}
