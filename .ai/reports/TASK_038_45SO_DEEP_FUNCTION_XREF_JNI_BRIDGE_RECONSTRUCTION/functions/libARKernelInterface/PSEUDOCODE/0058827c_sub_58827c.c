// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58827c
// Recovered Name: sub_58827c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58827c | Size: 60 bytes | SHA256: 3e06f770da921e90e5c918cf4a4676b03aeb70a05f4c4317f8aebbf4db5cf3db
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetIsBold(J)Z (table at 0x10cfd70)

jlong sub_58827c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x58827c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x588280 */ mov x29, sp;
    /* 0x588284 */ cbz x2, #0x5882a8;
    /* 0x588288 */ ldr x0, [x2, #0x680];
    /* 0x58828c */ cbz x0, #0x5882b4;
    /* 0x588290 */ ldr x8, [x0];
    /* 0x588294 */ ldr x8, [x8, #0x30];
    /* 0x588298 */ blr x8;
    /* 0x58829c */ and w0, w0, #1;
    /* 0x5882a0 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
