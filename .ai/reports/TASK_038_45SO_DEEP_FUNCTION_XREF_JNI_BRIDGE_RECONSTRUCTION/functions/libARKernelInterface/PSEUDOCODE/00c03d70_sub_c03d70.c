// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc03d70
// Recovered Name: sub_c03d70
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc03d70 | Size: 212 bytes | SHA256: 57f4755f019ae193885485c593bf4b2ce45962889d7573a0e9be1310797f3b29
// Callers: 1 | Callees: 1 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "GPInstanceSegmentData:getNoFaceMask  noFaceMask get null pointer"
//   "GPInstanceSegmentData:getNoFaceMask  return"
//   "arkernel"

void sub_c03d70(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0xc03d70 */ stp x29, x30, [sp, #-0x10]!;
    /* 0xc03d74 */ mov x29, sp;
    /* 0xc03d78 */ ldr x8, [x0, #8];
    /* 0xc03d7c */ ldp w9, w8, [x8, #0x24];
    /* 0xc03d80 */ cmp w9, #0;
    /* 0xc03d84 */ ccmp w8, #0, #4, ne;
    /* 0xc03d88 */ b.ne #0xc03dc4;
    /* 0xc03d8c */ adrp x8, #0x10d0000;
    /* 0xc03d90 */ add x8, x8, #0xc30;
    /* 0xc03d94 */ ldr w8, [x8];
    /* 0xc03d98 */ cmp w8, #2;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
