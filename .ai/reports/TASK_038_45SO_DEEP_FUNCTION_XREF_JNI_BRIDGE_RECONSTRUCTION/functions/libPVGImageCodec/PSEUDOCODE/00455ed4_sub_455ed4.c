// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x455ed4
// Recovered Name: sub_455ed4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x455ed4 | Size: 1064 bytes | SHA256: ae465fdf94576aca50b4e9411be36e97ce9f70755dae2a5023a79bc25c0f28e2
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: WebPSafeFree, WebPSafeMalloc, __assert2, __stack_chk_fail
// Strings referenced:
//   "(uint64_t)(w * h) == (uint64_t)w * h"
//   "/Users/zhichenzhang/meitu/Project/PVGThirdParty/libwebp/src/enc/analysis_enc.c"
//   "void SmoothSegmentMap(VP8Encoder *const)"

void sub_455ed4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 266 instructions
    /* 0x455ed4 */ stp x29, x30, [sp, #0x60];
    /* 0x455ed8 */ add x29, sp, #0x60;
    /* 0x455edc */ mrs x8, tpidr_el0;
    /* 0x455ee0 */ ldr x8, [x8, #0x28];
    /* 0x455ee4 */ stur x8, [x29, #-8];
    /* 0x455ee8 */ stur x0, [x29, #-0x20];
    /* 0x455eec */ ldur x8, [x29, #-0x20];
    /* 0x455ef0 */ ldr w8, [x8, #0x30];
    /* 0x455ef4 */ str w8, [sp, #0x30];
    /* 0x455ef8 */ ldur x8, [x29, #-0x20];
    /* 0x455efc */ ldr w8, [x8, #0x34];
    WebPSafeMalloc();
    __assert2();
    WebPSafeFree();
    return x0;
    __stack_chk_fail();
}
