// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b1f0
// Recovered Name: sub_57b1f0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b1f0 | Size: 24 bytes | SHA256: b49f4e1909ec85973178135ad6a36ddbd611f9cbaf1fc73e6324c65439d6ea91
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeReset(J)V (table at 0x10ce7c8)

jlong sub_57b1f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x57b1f0 */ cbz x2, #0x57b204;
    /* 0x57b1f4 */ ldr x8, [x2];
    /* 0x57b1f8 */ mov x0, x2;
    /* 0x57b1fc */ ldr x1, [x8, #0x18];
    /* 0x57b200 */ br x1;
    return x0;
}
