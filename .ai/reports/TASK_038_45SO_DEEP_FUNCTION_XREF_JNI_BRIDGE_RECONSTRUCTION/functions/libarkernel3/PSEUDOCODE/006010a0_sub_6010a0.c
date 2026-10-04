// Library: libarkernel3.so
// Function ID: libarkernel3::0x6010a0
// Recovered Name: sub_6010a0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6010a0 | Size: 208 bytes | SHA256: a8a0a05432ee87562ec4ed25daa3387be1a6c35f1f3eca1d716efef09a17b5ba
// Callers: 1 | Callees: 5 | Imports: 0

// Strings referenced:
//   "GPInstanceSegmentData:getInstanceSegmentMask get null pointer"
//   "GPInstanceSegmentData:getInstanceSegmentMask index out of range"
//   "GPInstanceSegmentData:getInstanceSegmentMask size is 0"
//   "getInstanceSegmentMask"
//   "mtlabar3"

void sub_6010a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 52 instructions
    /* 0x6010a0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x6010a4 */ stp x20, x19, [sp, #0x10];
    /* 0x6010a8 */ mov x29, sp;
    /* 0x6010ac */ tbnz w1, #0x1f, #0x601124;
    /* 0x6010b0 */ ldp x9, x8, [x0, #0x28];
    /* 0x6010b4 */ mov w20, w1;
    /* 0x6010b8 */ mov x19, x0;
    /* 0x6010bc */ sub x8, x8, x9;
    /* 0x6010c0 */ cmp x20, x8, asr #3;
    /* 0x6010c4 */ b.hs #0x601124;
    /* 0x6010c8 */ mov x0, x19;
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_a4308c();
    sub_cccfe0();
    sub_cccfe0();
    return x0;
}
