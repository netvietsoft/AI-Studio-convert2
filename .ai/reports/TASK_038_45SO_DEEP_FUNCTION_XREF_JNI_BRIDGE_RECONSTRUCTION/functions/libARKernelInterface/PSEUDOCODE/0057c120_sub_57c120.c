// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57c120
// Recovered Name: sub_57c120
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57c120 | Size: 12 bytes | SHA256: e27dab6673c9f68a103003dd6bd22b3f7a02ab3b334ef57a9643b2612a349705
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetShoulderCount(JI)V (table at 0x10ce9a8)

jlong sub_57c120(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57c120 */ cbz x2, #0x57c128;
    /* 0x57c124 */ str w3, [x2, #0xc];
    return x0;
}
