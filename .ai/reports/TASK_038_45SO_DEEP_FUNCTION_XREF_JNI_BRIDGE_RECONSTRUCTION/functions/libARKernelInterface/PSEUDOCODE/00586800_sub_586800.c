// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x586800
// Recovered Name: sub_586800
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x586800 | Size: 60 bytes | SHA256: 84a1946b1e4df5a54f3d42bf4a3207e56774f2eb401a6d7bbf120b75585ba2b4
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetIsStaticShow(J)Z (table at 0x10cfc80)

jlong sub_586800(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x586800 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x586804 */ mov x29, sp;
    /* 0x586808 */ cbz x2, #0x58682c;
    /* 0x58680c */ ldr x0, [x2, #0x380];
    /* 0x586810 */ cbz x0, #0x586838;
    /* 0x586814 */ ldr x8, [x0];
    /* 0x586818 */ ldr x8, [x8, #0x30];
    /* 0x58681c */ blr x8;
    /* 0x586820 */ and w0, w0, #1;
    /* 0x586824 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
