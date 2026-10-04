// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc03ba4
// Recovered Name: sub_c03ba4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc03ba4 | Size: 196 bytes | SHA256: bdd96e2f2cc283587d93619e6fcc0fec983ead7a9e958546692c3162c473cb4e
// Callers: 1 | Callees: 1 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "GPInstanceSegmentData:  mask get null pointer.nFaceIndex:%d"
//   "arkernel"

void sub_c03ba4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0xc03ba4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0xc03ba8 */ mov x29, sp;
    /* 0xc03bac */ ldr x10, [x0, #8];
    /* 0xc03bb0 */ ldp w8, w9, [x10, #0x30];
    /* 0xc03bb4 */ cmp w8, #0;
    /* 0xc03bb8 */ ccmp w9, #0, #4, ne;
    /* 0xc03bbc */ b.eq #0xc03c5c;
    /* 0xc03bc0 */ ldr w9, [x10, #0x10];
    /* 0xc03bc4 */ mov w3, w1;
    /* 0xc03bc8 */ cmp w9, #1;
    /* 0xc03bcc */ b.lt #0xc03c04;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
