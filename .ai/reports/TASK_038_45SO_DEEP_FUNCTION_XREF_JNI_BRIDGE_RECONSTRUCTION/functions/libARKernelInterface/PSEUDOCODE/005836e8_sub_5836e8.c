// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5836e8
// Recovered Name: sub_5836e8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5836e8 | Size: 60 bytes | SHA256: 3b5dcf00df0cad02450662acb7a8b93b0b555505c517518be38f547b38ef4161
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetEnableSelected(J)Z (table at 0x10cf8a8)

jlong sub_5836e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x5836e8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x5836ec */ mov x29, sp;
    /* 0x5836f0 */ cbz x2, #0x583714;
    /* 0x5836f4 */ ldr x0, [x2, #0x920];
    /* 0x5836f8 */ cbz x0, #0x583720;
    /* 0x5836fc */ ldr x8, [x0];
    /* 0x583700 */ ldr x8, [x8, #0x30];
    /* 0x583704 */ blr x8;
    /* 0x583708 */ and w0, w0, #1;
    /* 0x58370c */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
