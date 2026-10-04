// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x687c4
// Recovered Name: sub_687c4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x687c4 | Size: 80 bytes | SHA256: 89856754bd60f5cfbff952b02fb9a53de70b355596db0669f81a330f2b9575a7
// Callers: 2 | Callees: 1 | Imports: 2

// Calls external APIs: av_free, avio_context_free

void sub_687c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0x687c4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x687c8 */ str x19, [sp, #0x10];
    /* 0x687cc */ mov x29, sp;
    /* 0x687d0 */ mov x19, x0;
    /* 0x687d4 */ adrp x8, #0x139000;
    /* 0x687d8 */ add x8, x8, #0x198;
    /* 0x687dc */ str x8, [x0];
    /* 0x687e0 */ ldr x8, [x19, #8]!;
    /* 0x687e4 */ cbz x8, #0x68804;
    /* 0x687e8 */ ldr x0, [x8, #8];
    /* 0x687ec */ cbz x0, #0x687fc;
    av_free();
    avio_context_free();
    return x0;
    sub_68814();
}
