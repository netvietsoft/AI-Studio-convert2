// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58876c
// Recovered Name: sub_58876c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58876c | Size: 60 bytes | SHA256: 141cc62a323fcd4b84c738ea8a204f2c1e3d25f81c1a5a81f7e2ffb69f3cae04
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetWrap(J)Z (table at 0x10cfec0)

jlong sub_58876c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x58876c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x588770 */ mov x29, sp;
    /* 0x588774 */ cbz x2, #0x588798;
    /* 0x588778 */ ldr x0, [x2, #0x920];
    /* 0x58877c */ cbz x0, #0x5887a4;
    /* 0x588780 */ ldr x8, [x0];
    /* 0x588784 */ ldr x8, [x8, #0x30];
    /* 0x588788 */ blr x8;
    /* 0x58878c */ and w0, w0, #1;
    /* 0x588790 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
