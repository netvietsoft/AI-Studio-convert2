// Library: libarkernel3.so
// Function ID: libarkernel3::0x600fd4
// Recovered Name: sub_600fd4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x600fd4 | Size: 188 bytes | SHA256: c490c48397751c3648bb26d9598281681c72c79f65681b014606b440435294a4
// Callers: 1 | Callees: 5 | Imports: 0

// Strings referenced:
//   "GPInstanceSegmentData:getInstanceSegmentRectF index out of range"
//   "GPInstanceSegmentData:getInstanceSegmentRectF size is 0"
//   "getInstanceSegmentRectF"
//   "mtlabar3"

void sub_600fd4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x600fd4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x600fd8 */ stp x20, x19, [sp, #0x10];
    /* 0x600fdc */ mov x29, sp;
    /* 0x600fe0 */ mov x19, x8;
    /* 0x600fe4 */ tbnz w1, #0x1f, #0x601044;
    /* 0x600fe8 */ ldp x9, x8, [x0, #0x28];
    /* 0x600fec */ mov w20, w1;
    /* 0x600ff0 */ sub x8, x8, x9;
    /* 0x600ff4 */ cmp x20, x8, asr #3;
    /* 0x600ff8 */ b.hs #0x601044;
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_a4308c();
    sub_cccfe0();
}
