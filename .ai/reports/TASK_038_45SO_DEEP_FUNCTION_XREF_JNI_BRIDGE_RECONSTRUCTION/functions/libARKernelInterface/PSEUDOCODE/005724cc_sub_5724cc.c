// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5724cc
// Recovered Name: sub_5724cc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5724cc | Size: 24 bytes | SHA256: b49f4e1909ec85973178135ad6a36ddbd611f9cbaf1fc73e6324c65439d6ea91
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeReset(J)V (table at 0x10cd7a8)

jlong sub_5724cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x5724cc */ cbz x2, #0x5724e0;
    /* 0x5724d0 */ ldr x8, [x2];
    /* 0x5724d4 */ mov x0, x2;
    /* 0x5724d8 */ ldr x1, [x8, #0x18];
    /* 0x5724dc */ br x1;
    return x0;
}
