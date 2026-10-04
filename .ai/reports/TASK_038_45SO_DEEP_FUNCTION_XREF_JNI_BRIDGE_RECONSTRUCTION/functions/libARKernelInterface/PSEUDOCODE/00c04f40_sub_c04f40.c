// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc04f40
// Recovered Name: sub_c04f40
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc04f40 | Size: 136 bytes | SHA256: 8d1042b4f971a5b017297f5bce7450c20aef7f259bfeb0d2283d26329e4f1954
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: __stack_chk_fail, memcpy
// Strings referenced:
//   "GPHairSeamersData"

void sub_c04f40(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 34 instructions
    /* 0xc04f40 */ stp x29, x30, [sp, #0x90];
    /* 0xc04f44 */ stp x20, x19, [sp, #0xa0];
    /* 0xc04f48 */ add x29, sp, #0x90;
    /* 0xc04f4c */ mrs x19, tpidr_el0;
    /* 0xc04f50 */ adrp x1, #0x10a4000;
    /* 0xc04f54 */ add x1, x1, #0xe70;
    /* 0xc04f58 */ ldr x8, [x19, #0x28];
    /* 0xc04f5c */ add x0, sp, #0x28;
    /* 0xc04f60 */ mov w2, #0x60;
    /* 0xc04f64 */ stur x8, [x29, #-8];
    memcpy();
    sub_d94250();
    sub_59e3a4();
    return x0;
    __stack_chk_fail();
}
