// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58269c
// Recovered Name: sub_58269c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58269c | Size: 60 bytes | SHA256: 73cf2bd1724f4da7a1f78c84b353ef08b47aa279a6b0f6dd79fdbf7d7bbb1c7a
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetVisibility(J)Z (table at 0x10cf578)

jlong sub_58269c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x58269c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x5826a0 */ mov x29, sp;
    /* 0x5826a4 */ cbz x2, #0x5826c8;
    /* 0x5826a8 */ ldr x0, [x2, #0x4a0];
    /* 0x5826ac */ cbz x0, #0x5826d4;
    /* 0x5826b0 */ ldr x8, [x0];
    /* 0x5826b4 */ ldr x8, [x8, #0x30];
    /* 0x5826b8 */ blr x8;
    /* 0x5826bc */ and w0, w0, #1;
    /* 0x5826c0 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
