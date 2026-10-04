// Library: libARSPM.so
// Function ID: libARSPM::0x253d10
// Recovered Name: sub_253d10
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x253d10 | Size: 324 bytes | SHA256: 6dd44e2c2385a121a6e53cdabd2008bfdfe246a1cfb63d67b9414402d0a2f3e7
// Callers: 1 | Callees: 4 | Imports: 0

// Strings referenced:
//   "../../../../src/effects/imagefilters/SkBlurImageFilter.cpp"
//   "<D%"

void sub_253d10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 81 instructions
    /* 0x253d10 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x253d14 */ str x21, [sp, #0x10];
    /* 0x253d18 */ stp x20, x19, [sp, #0x20];
    /* 0x253d1c */ mov x29, sp;
    /* 0x253d20 */ fmov d1, #3.00000000;
    /* 0x253d24 */ adrp x8, #0x6b000;
    /* 0x253d28 */ fmul d0, d0, d1;
    /* 0x253d2c */ ldr d1, [x8, #0x150];
    /* 0x253d30 */ fmul d0, d0, d1;
    /* 0x253d34 */ fmov d1, #0.25000000;
    /* 0x253d38 */ fmul d0, d0, d1;
    sub_141420();
    sub_141288();
    return x0;
    sub_141420();
    sub_141288();
    return x0;
    sub_2cfaa0();
    sub_2666c0();
}
