// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc03c84
// Recovered Name: sub_c03c84
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc03c84 | Size: 236 bytes | SHA256: 54e0054a72fac0802062202f1df01a98a1609c8f3cec7b3125afa9af910560b9
// Callers: 1 | Callees: 1 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "GPInstanceSegmentData:getInstanceSegmentMask  mask get null pointer.Index:%d"
//   "GPInstanceSegmentData:getInstanceSegmentMask No multi-instance segment masks "
//   "arkernel"

void sub_c03c84(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0xc03c84 */ stp x29, x30, [sp, #-0x10]!;
    /* 0xc03c88 */ mov x29, sp;
    /* 0xc03c8c */ ldr x8, [x0, #8];
    /* 0xc03c90 */ ldp w9, w8, [x8, #0x30];
    /* 0xc03c94 */ cmp w9, #0;
    /* 0xc03c98 */ ccmp w8, #0, #4, ne;
    /* 0xc03c9c */ b.ne #0xc03ce0;
    /* 0xc03ca0 */ adrp x8, #0x10d0000;
    /* 0xc03ca4 */ add x8, x8, #0xc30;
    /* 0xc03ca8 */ ldr w8, [x8];
    /* 0xc03cac */ cmp w8, #2;
    sub_5a6b20();
    sub_5a6b20();
    __android_log_print();
    __android_log_print();
    return x0;
}
