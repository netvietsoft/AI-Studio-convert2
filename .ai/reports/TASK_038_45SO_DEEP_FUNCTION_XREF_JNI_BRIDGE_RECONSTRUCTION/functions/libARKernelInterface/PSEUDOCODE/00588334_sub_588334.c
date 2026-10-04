// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x588334
// Recovered Name: sub_588334
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x588334 | Size: 60 bytes | SHA256: 358f393a7f5381e3d8a30bf4e0b0914b553ceff0e906bd98c8f703be6e6b1fd5
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetIsItalic(J)Z (table at 0x10cfda0)

jlong sub_588334(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x588334 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x588338 */ mov x29, sp;
    /* 0x58833c */ cbz x2, #0x588360;
    /* 0x588340 */ ldr x0, [x2, #0x6e0];
    /* 0x588344 */ cbz x0, #0x58836c;
    /* 0x588348 */ ldr x8, [x0];
    /* 0x58834c */ ldr x8, [x8, #0x30];
    /* 0x588350 */ blr x8;
    /* 0x588354 */ and w0, w0, #1;
    /* 0x588358 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
