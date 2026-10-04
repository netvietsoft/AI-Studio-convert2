// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x581e60
// Recovered Name: sub_581e60
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x581e60 | Size: 60 bytes | SHA256: 9a2a1baa2595637fd73f9825370c3df71ca9789875244a2b4bcbecaa0565e367
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetShowStaticFrame(J)Z (table at 0x10cf3e0)

jlong sub_581e60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x581e60 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x581e64 */ mov x29, sp;
    /* 0x581e68 */ cbz x2, #0x581e8c;
    /* 0x581e6c */ ldr x0, [x2, #0x4a0];
    /* 0x581e70 */ cbz x0, #0x581e98;
    /* 0x581e74 */ ldr x8, [x0];
    /* 0x581e78 */ ldr x8, [x8, #0x30];
    /* 0x581e7c */ blr x8;
    /* 0x581e80 */ and w0, w0, #1;
    /* 0x581e84 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
