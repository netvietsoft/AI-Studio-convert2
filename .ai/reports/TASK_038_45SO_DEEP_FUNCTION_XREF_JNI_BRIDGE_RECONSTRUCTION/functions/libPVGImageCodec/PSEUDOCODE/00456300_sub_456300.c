// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x456300
// Recovered Name: sub_456300
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x456300 | Size: 580 bytes | SHA256: 45a38a08e0236b853c2826bfd17eb208a4592e7fcad92fcf66ef5ea4925968d1
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: __assert2
// Strings referenced:
//   "/Users/zhichenzhang/meitu/Project/PVGThirdParty/libwebp/src/enc/analysis_enc.c"
//   "mid <= max && mid >= min"
//   "void SetSegmentAlphas(VP8Encoder *const, const int *, int)"

void sub_456300(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 145 instructions
    /* 0x456300 */ stp x29, x30, [sp, #0x40];
    /* 0x456304 */ add x29, sp, #0x40;
    /* 0x456308 */ stur x0, [x29, #-8];
    /* 0x45630c */ stur x1, [x29, #-0x10];
    /* 0x456310 */ stur w2, [x29, #-0x14];
    /* 0x456314 */ ldur x8, [x29, #-8];
    /* 0x456318 */ ldr w8, [x8, #0x20];
    /* 0x45631c */ stur w8, [x29, #-0x18];
    /* 0x456320 */ ldur x8, [x29, #-0x10];
    /* 0x456324 */ ldr w8, [x8];
    /* 0x456328 */ stur w8, [x29, #-0x1c];
    __assert2();
    sub_455e5c();
    sub_455e5c();
    return x0;
}
