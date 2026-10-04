// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x9040a8
// Recovered Name: sub_9040a8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9040a8 | Size: 88 bytes | SHA256: 63ac21f7c7fcd8fcda174d9e1af9d50c1bbe322ebf572471034b2639b201585e
// Callers: 0 | Callees: 0 | Imports: 0

// Strings referenced:
//   "ZN8arkernel33CoreFluffyHairFaceliftPartControl7PrepareEvE3$_0"

void sub_9040a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 22 instructions
    /* 0x9040a8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x9040ac */ str x19, [sp, #0x10];
    /* 0x9040b0 */ mov x29, sp;
    /* 0x9040b4 */ ldp x19, x8, [x0, #8];
    /* 0x9040b8 */ ldr x9, [x8];
    /* 0x9040bc */ mov x0, x8;
    /* 0x9040c0 */ ldr x9, [x9, #0x70];
    /* 0x9040c4 */ blr x9;
    /* 0x9040c8 */ mov x0, x19;
    /* 0x9040cc */ ldr x19, [sp, #0x10];
    /* 0x9040d0 */ ldp x29, x30, [sp], #0x20;
    return x0;
    return x0;
}
