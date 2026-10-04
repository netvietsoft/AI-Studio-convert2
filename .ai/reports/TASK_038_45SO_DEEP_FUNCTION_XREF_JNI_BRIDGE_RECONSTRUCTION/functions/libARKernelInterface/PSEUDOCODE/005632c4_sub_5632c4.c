// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5632c4
// Recovered Name: sub_5632c4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5632c4 | Size: 24 bytes | SHA256: b49f4e1909ec85973178135ad6a36ddbd611f9cbaf1fc73e6324c65439d6ea91
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeReset(J)V (table at 0x10cc6c8)

jlong sub_5632c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x5632c4 */ cbz x2, #0x5632d8;
    /* 0x5632c8 */ ldr x8, [x2];
    /* 0x5632cc */ mov x0, x2;
    /* 0x5632d0 */ ldr x1, [x8, #0x18];
    /* 0x5632d4 */ br x1;
    return x0;
}
