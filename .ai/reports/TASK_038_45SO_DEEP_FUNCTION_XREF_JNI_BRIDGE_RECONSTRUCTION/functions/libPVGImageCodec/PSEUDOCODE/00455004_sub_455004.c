// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x455004
// Recovered Name: sub_455004
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x455004 | Size: 1684 bytes | SHA256: 0d25a1eb9e4f57192c2f6978ee3068282c59c1bd2cade30769339082a0182db3
// Callers: 1 | Callees: 2 | Imports: 2

// Calls external APIs: __assert2, __stack_chk_fail
// Strings referenced:
//   "/Users/zhichenzhang/meitu/Project/PVGThirdParty/libwebp/src/enc/analysis_enc.c"
//   "n < 2 * nb"
//   "nb <= NUM_MB_SEGMENTS"
//   "nb >= 1"
//   "void AssignSegments(VP8Encoder *const, const int *)"

void sub_455004(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 421 instructions
    /* 0x455004 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x455008 */ str x28, [sp, #0x10];
    /* 0x45500c */ mov x29, sp;
    /* 0x455010 */ sub sp, sp, #0x4a0;
    /* 0x455014 */ mrs x8, tpidr_el0;
    /* 0x455018 */ ldr x8, [x8, #0x28];
    /* 0x45501c */ stur x8, [x29, #-8];
    /* 0x455020 */ str x0, [sp, #0x60];
    /* 0x455024 */ str x1, [sp, #0x58];
    /* 0x455028 */ ldr x8, [sp, #0x60];
    /* 0x45502c */ ldr w8, [x8, #0x20];
    __assert2();
    __assert2();
    __assert2();
    sub_455ed0();
    sub_4562fc();
    return x0;
    __stack_chk_fail();
}
