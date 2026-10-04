// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x582f90
// Recovered Name: sub_582f90
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x582f90 | Size: 68 bytes | SHA256: 70a31f3f0614065acae5318f83dfdabfe9391ce7f52e58954173ee5aaada6e2f
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetEnableFlip(J)Z (table at 0x10cf740)

jlong sub_582f90(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x582f90 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x582f94 */ mov x29, sp;
    /* 0x582f98 */ cbz x2, #0x582fc4;
    /* 0x582f9c */ ldr x8, [x2, #0xc10];
    /* 0x582fa0 */ cbz x8, #0x582fc4;
    /* 0x582fa4 */ ldr x0, [x2, #0xc40];
    /* 0x582fa8 */ cbz x0, #0x582fd0;
    /* 0x582fac */ ldr x8, [x0];
    /* 0x582fb0 */ ldr x8, [x8, #0x30];
    /* 0x582fb4 */ blr x8;
    /* 0x582fb8 */ and w0, w0, #1;
    return x0;
    return x0;
    sub_581efc();
}
