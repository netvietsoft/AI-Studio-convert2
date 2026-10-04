// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5829e8
// Recovered Name: sub_5829e8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5829e8 | Size: 60 bytes | SHA256: 408c406f502e1c2599d2c3e7e60f7ffc2e5c7f844d0e66da09b1c4e187678d88
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetEnableGlobalColor(J)Z (table at 0x10cf638)

jlong sub_5829e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x5829e8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x5829ec */ mov x29, sp;
    /* 0x5829f0 */ cbz x2, #0x582a14;
    /* 0x5829f4 */ ldr x0, [x2, #0x620];
    /* 0x5829f8 */ cbz x0, #0x582a20;
    /* 0x5829fc */ ldr x8, [x0];
    /* 0x582a00 */ ldr x8, [x8, #0x30];
    /* 0x582a04 */ blr x8;
    /* 0x582a08 */ and w0, w0, #1;
    /* 0x582a0c */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
