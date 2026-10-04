// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5886b4
// Recovered Name: sub_5886b4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5886b4 | Size: 60 bytes | SHA256: 014fee9402ef0d465139a4e7f71d0849329d147777b8ac9b842eb1fd0d0243b2
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetLeftToRight(J)Z (table at 0x10cfe90)

jlong sub_5886b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x5886b4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x5886b8 */ mov x29, sp;
    /* 0x5886bc */ cbz x2, #0x5886e0;
    /* 0x5886c0 */ ldr x0, [x2, #0x8c0];
    /* 0x5886c4 */ cbz x0, #0x5886ec;
    /* 0x5886c8 */ ldr x8, [x0];
    /* 0x5886cc */ ldr x8, [x8, #0x30];
    /* 0x5886d0 */ blr x8;
    /* 0x5886d4 */ and w0, w0, #1;
    /* 0x5886d8 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
