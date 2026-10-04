// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc34ed8
// Recovered Name: sub_c34ed8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc34ed8 | Size: 288 bytes | SHA256: a9fa86a7f88bf3584412ecaa8288c977eae49d31a5f150a8a569dc242971e77d
// Callers: 1 | Callees: 2 | Imports: 0

// Strings referenced:
//   "NeedOptimize"
//   "SegmentMaskEdgeFactor"
//   "SegmentMaskEdgeFixedSize480"

void sub_c34ed8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 72 instructions
    /* 0xc34ed8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xc34edc */ str x21, [sp, #0x10];
    /* 0xc34ee0 */ stp x20, x19, [sp, #0x20];
    /* 0xc34ee4 */ mov x29, sp;
    /* 0xc34ee8 */ ldr x8, [x1];
    /* 0xc34eec */ mov x19, x0;
    /* 0xc34ef0 */ mov x0, x1;
    /* 0xc34ef4 */ mov x20, x1;
    /* 0xc34ef8 */ ldr x8, [x8, #0xa8];
    /* 0xc34efc */ blr x8;
    /* 0xc34f00 */ ldr x8, [x20];
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8da0();
    return x0;
}
