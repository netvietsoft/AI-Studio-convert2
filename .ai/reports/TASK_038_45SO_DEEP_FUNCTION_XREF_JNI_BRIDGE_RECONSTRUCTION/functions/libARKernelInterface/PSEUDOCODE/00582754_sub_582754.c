// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x582754
// Recovered Name: sub_582754
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x582754 | Size: 60 bytes | SHA256: 8bc9437331a0c0a96b4dca978f9358da19a7d4d8db0904af4abe8c6d3e6f6f90
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetAreaLimit(J)Z (table at 0x10cf5a8)

jlong sub_582754(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x582754 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x582758 */ mov x29, sp;
    /* 0x58275c */ cbz x2, #0x582780;
    /* 0x582760 */ ldr x0, [x2, #0x500];
    /* 0x582764 */ cbz x0, #0x58278c;
    /* 0x582768 */ ldr x8, [x0];
    /* 0x58276c */ ldr x8, [x8, #0x30];
    /* 0x582770 */ blr x8;
    /* 0x582774 */ and w0, w0, #1;
    /* 0x582778 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
