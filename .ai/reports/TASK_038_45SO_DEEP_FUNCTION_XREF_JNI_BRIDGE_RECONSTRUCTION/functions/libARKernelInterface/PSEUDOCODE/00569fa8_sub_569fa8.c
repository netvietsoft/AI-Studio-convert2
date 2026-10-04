// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x569fa8
// Recovered Name: sub_569fa8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x569fa8 | Size: 24 bytes | SHA256: b49f4e1909ec85973178135ad6a36ddbd611f9cbaf1fc73e6324c65439d6ea91
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeReset(J)V (table at 0x10ccda0)

jlong sub_569fa8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x569fa8 */ cbz x2, #0x569fbc;
    /* 0x569fac */ ldr x8, [x2];
    /* 0x569fb0 */ mov x0, x2;
    /* 0x569fb4 */ ldr x1, [x8, #0x18];
    /* 0x569fb8 */ br x1;
    return x0;
}
