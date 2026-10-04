// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5825e4
// Recovered Name: sub_5825e4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5825e4 | Size: 60 bytes | SHA256: 29593725df097e07bed19cfe0d71ed62faa3bfce8446e8f8f4c476f0e5a32c12
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetMirror(J)Z (table at 0x10cf548)

jlong sub_5825e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x5825e4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x5825e8 */ mov x29, sp;
    /* 0x5825ec */ cbz x2, #0x582610;
    /* 0x5825f0 */ ldr x0, [x2, #0x3e0];
    /* 0x5825f4 */ cbz x0, #0x58261c;
    /* 0x5825f8 */ ldr x8, [x0];
    /* 0x5825fc */ ldr x8, [x8, #0x30];
    /* 0x582600 */ blr x8;
    /* 0x582604 */ and w0, w0, #1;
    /* 0x582608 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
