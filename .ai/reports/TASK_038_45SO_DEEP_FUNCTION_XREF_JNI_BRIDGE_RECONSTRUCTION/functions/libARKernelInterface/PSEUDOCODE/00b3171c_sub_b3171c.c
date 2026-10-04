// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb3171c
// Recovered Name: sub_b3171c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb3171c | Size: 864 bytes | SHA256: 484cab6c77cea4ecd80f01330af18074d6dc2b4aff79fe9b7a783a86801afec9
// Callers: 0 | Callees: 4 | Imports: 0

// Strings referenced:
//   "EnableSamllFaceReduceAlpha"
//   "FilterColorAlpha"
//   "HairsoftAlpha"
//   "HairsoftAlphaSecond"
//   "MergesrcAlpha"

void sub_b3171c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 216 instructions
    /* 0xb3171c */ stp x29, x30, [sp, #-0x30]!;
    /* 0xb31720 */ stp x22, x21, [sp, #0x10];
    /* 0xb31724 */ stp x20, x19, [sp, #0x20];
    /* 0xb31728 */ mov x29, sp;
    /* 0xb3172c */ mov x21, x1;
    /* 0xb31730 */ mov x19, x0;
    sub_61bfa0();
    /* 0xb31738 */ mov w20, w0;
    /* 0xb3173c */ tbz w0, #0, #0xb31a64;
    /* 0xb31740 */ ldr x8, [x21];
    /* 0xb31744 */ mov x0, x21;
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8da0();
    sub_5a8d1c();
    sub_5a8da0();
    sub_5a8d1c();
    sub_5a8de8();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8da0();
    return x0;
}
