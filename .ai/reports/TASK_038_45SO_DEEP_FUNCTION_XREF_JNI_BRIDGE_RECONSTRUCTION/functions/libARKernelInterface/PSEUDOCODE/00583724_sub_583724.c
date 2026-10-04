// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x583724
// Recovered Name: sub_583724
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x583724 | Size: 60 bytes | SHA256: 8103f9488ac1c0d497609a21adfc2958bb1a5e98bf1eca6677bb4458ac595783
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetLockScreen(J)Z (table at 0x10cf8c0)

jlong sub_583724(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x583724 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x583728 */ mov x29, sp;
    /* 0x58372c */ cbz x2, #0x583750;
    /* 0x583730 */ ldr x0, [x2, #0x950];
    /* 0x583734 */ cbz x0, #0x58375c;
    /* 0x583738 */ ldr x8, [x0];
    /* 0x58373c */ ldr x8, [x8, #0x30];
    /* 0x583740 */ blr x8;
    /* 0x583744 */ and w0, w0, #1;
    /* 0x583748 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
