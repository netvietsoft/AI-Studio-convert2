// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5818d8
// Recovered Name: sub_5818d8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5818d8 | Size: 32 bytes | SHA256: 92161acf00fa234c702e406a99a01f52ab236943ef6282a94531bf2d0d05baf1
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetTotalTime(J)F (table at 0x10cf290)

jlong sub_5818d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x5818d8 */ cbz x2, #0x5818f0;
    /* 0x5818dc */ ldr x0, [x2, #0xe0];
    /* 0x5818e0 */ cbz x0, #0x5818f8;
    /* 0x5818e4 */ ldr x8, [x0];
    /* 0x5818e8 */ ldr x1, [x8, #0x30];
    /* 0x5818ec */ br x1;
    /* 0x5818f0 */ movi d0, #0000000000000000;
    return x0;
}
