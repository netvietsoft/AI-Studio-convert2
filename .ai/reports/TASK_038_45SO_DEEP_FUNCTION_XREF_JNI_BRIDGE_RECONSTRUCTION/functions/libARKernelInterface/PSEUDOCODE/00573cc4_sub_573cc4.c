// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x573cc4
// Recovered Name: sub_573cc4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x573cc4 | Size: 24 bytes | SHA256: b49f4e1909ec85973178135ad6a36ddbd611f9cbaf1fc73e6324c65439d6ea91
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeReset(J)V (table at 0x10cdad8)

jlong sub_573cc4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x573cc4 */ cbz x2, #0x573cd8;
    /* 0x573cc8 */ ldr x8, [x2];
    /* 0x573ccc */ mov x0, x2;
    /* 0x573cd0 */ ldr x1, [x8, #0x18];
    /* 0x573cd4 */ br x1;
    return x0;
}
