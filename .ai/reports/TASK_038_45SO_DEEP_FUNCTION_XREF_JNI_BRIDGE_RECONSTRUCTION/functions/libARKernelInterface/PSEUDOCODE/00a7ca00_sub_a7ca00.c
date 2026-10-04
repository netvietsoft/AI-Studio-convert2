// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa7ca00
// Recovered Name: sub_a7ca00
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa7ca00 | Size: 108 bytes | SHA256: a74d5056cc2c2bf1f56729e80a9f2ed55e60f81b4f150b86ac88a080466239e0
// Callers: 13 | Callees: 0 | Imports: 0

// Strings referenced:
//   "mouthSegmentMask"
//   "useMouthSegmentMask"

void sub_a7ca00(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0xa7ca00 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xa7ca04 */ stp x20, x19, [sp, #0x10];
    /* 0xa7ca08 */ mov x29, sp;
    /* 0xa7ca0c */ mov x19, x0;
    /* 0xa7ca10 */ ldr x0, [x0, #0x388];
    /* 0xa7ca14 */ cbz x0, #0xa7ca60;
    /* 0xa7ca18 */ ldr x8, [x0];
    /* 0xa7ca1c */ ldrb w2, [x19, #0x6b3];
    /* 0xa7ca20 */ mov w20, w1;
    /* 0xa7ca24 */ adrp x1, #0x1b8000;
    /* 0xa7ca28 */ add x1, x1, #0x521;
    return x0;
}
