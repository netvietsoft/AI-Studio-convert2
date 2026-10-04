// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x588f28
// Recovered Name: sub_588f28
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x588f28 | Size: 60 bytes | SHA256: 3855e9330d934a9fed70fb3e091605f7bbc54c98f6e8b9e5145e286cff44e399
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetIsVisible(J)Z (table at 0x10d0058)

jlong sub_588f28(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x588f28 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x588f2c */ mov x29, sp;
    /* 0x588f30 */ cbz x2, #0x588f54;
    /* 0x588f34 */ ldr x0, [x2, #0xe60];
    /* 0x588f38 */ cbz x0, #0x588f60;
    /* 0x588f3c */ ldr x8, [x0];
    /* 0x588f40 */ ldr x8, [x8, #0x30];
    /* 0x588f44 */ blr x8;
    /* 0x588f48 */ and w0, w0, #1;
    /* 0x588f4c */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
