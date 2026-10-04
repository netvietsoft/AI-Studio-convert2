// Library: libarkernel3.so
// Function ID: libarkernel3::0x600f00
// Recovered Name: sub_600f00
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x600f00 | Size: 212 bytes | SHA256: cbce8e9521daad7fcb7a16a7f33e9191bcc97f07549fc96e55e083c50155934f
// Callers: 1 | Callees: 5 | Imports: 0

// Strings referenced:
//   "GPInstanceSegmentData::getFaceMappingInstanceSegmentMask  mask get null pointer.nFaceIndex:%d"
//   "GPInstanceSegmentData:getInstanceSegmentRectF size is 0"
//   "getFaceMappingInstanceSegmentMask"
//   "mtlabar3"

void sub_600f00(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0x600f00 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x600f04 */ stp x20, x19, [sp, #0x10];
    /* 0x600f08 */ mov x29, sp;
    /* 0x600f0c */ mov w19, w1;
    /* 0x600f10 */ mov x20, x0;
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_a4308c();
    /* 0x600f24 */ ldr w8, [x0, #0x18];
    /* 0x600f28 */ cbz w8, #0x600f70;
    sub_cccfe0();
    sub_cccfe0();
    return x0;
}
