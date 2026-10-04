// Library: libARSPM.so
// Function ID: libARSPM::0x2e52f4
// Recovered Name: sub_2e52f4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2e52f4 | Size: 840 bytes | SHA256: 4a8ca6d5e8882af51d27e207adb7d28ed107faf71781725eae186065be853871
// Callers: 0 | Callees: 13 | Imports: 2

// Calls external APIs: __cxa_guard_acquire, __cxa_guard_release
// Strings referenced:
//   "../../../../src/core/SkRuntimeEffectPriv.h"
//   "CircleBlur"
//   "blurProfile"
//   "circleData"
//   "uniform shader blurProfile;uniform half4 circleData;half4 main(float2 xy) {half2 vec = half2((sk_FragCoord.xy - circleData.xy) * circleData.w);half dist = length(vec) + (0.5 - circleData.z) * circleData.w;return blurProfile.eval(half2(dist, 0.5)).aaaa;}"

void sub_2e52f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 210 instructions
    /* 0x2e52f4 */ ldr x20, [sp, #0x98];
    /* 0x2e52f8 */ cbz x20, #0x2e5320;
    /* 0x2e52fc */ add x1, x20, #8;
    /* 0x2e5300 */ mov w0, #-1;
    sub_4ecb10();
    /* 0x2e5308 */ cmp w0, #1;
    /* 0x2e530c */ b.ne #0x2e5320;
    /* 0x2e5310 */ ldr x8, [x20];
    /* 0x2e5314 */ mov x0, x20;
    /* 0x2e5318 */ ldr x8, [x8, #8];
    /* 0x2e531c */ blr x8;
    sub_4ecb10();
    sub_14803c();
    sub_148054();
    sub_2666f8();
    sub_2e6db4();
    sub_327904();
    return x0;
    sub_331af0();
    sub_4ecb10();
    __cxa_guard_acquire();
    sub_3f2320();
    __cxa_guard_release();
    __cxa_guard_acquire();
    sub_1d8fb8();
    sub_1bdbb4();
    sub_1d93f8();
    sub_1d93f8();
    sub_4ecb10();
    __cxa_guard_release();
    sub_2cfaa0();
    sub_2666c0();
}
