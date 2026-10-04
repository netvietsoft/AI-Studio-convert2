// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x458090
// Recovered Name: sub_458090
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x458090 | Size: 800 bytes | SHA256: 8a9cb7c11b92b912a5fd2263fcbf503d0926f1bb5ed1a600bd3813ac11561261
// Callers: 0 | Callees: 6 | Imports: 2

// Calls external APIs: __assert2, pow
// Strings referenced:
//   "/Users/zhichenzhang/meitu/Project/PVGThirdParty/libwebp/src/enc/quant_enc.c"
//   "expn > 0."
//   "void VP8SetSegmentParams(VP8Encoder *const, float)"

void sub_458090(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 200 instructions
    /* 0x458090 */ stp x29, x30, [sp, #0x70];
    /* 0x458094 */ add x29, sp, #0x70;
    /* 0x458098 */ stur x0, [x29, #-8];
    /* 0x45809c */ stur s0, [x29, #-0xc];
    /* 0x4580a0 */ ldur x8, [x29, #-8];
    /* 0x4580a4 */ ldr w8, [x8, #0x20];
    /* 0x4580a8 */ stur w8, [x29, #-0x1c];
    /* 0x4580ac */ ldur x8, [x29, #-8];
    /* 0x4580b0 */ ldr x8, [x8];
    /* 0x4580b4 */ ldr s0, [x8, #0x1c];
    /* 0x4580b8 */ fmov w8, s0;
    sub_4583b0();
    sub_4584b8();
    pow();
    __assert2();
    sub_458540();
    sub_458540();
    sub_458540();
    sub_4585b4();
    sub_458728();
    sub_4589e4();
    return x0;
}
