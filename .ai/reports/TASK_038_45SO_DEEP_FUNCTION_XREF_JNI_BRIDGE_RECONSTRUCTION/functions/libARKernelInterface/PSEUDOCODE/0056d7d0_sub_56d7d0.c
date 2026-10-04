// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56d7d0
// Recovered Name: sub_56d7d0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56d7d0 | Size: 12 bytes | SHA256: e27dab6673c9f68a103003dd6bd22b3f7a02ab3b334ef57a9643b2612a349705
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFoodCount(JI)V (table at 0x10cd328)

jlong sub_56d7d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x56d7d0 */ cbz x2, #0x56d7d8;
    /* 0x56d7d4 */ str w3, [x2, #0xc];
    return x0;
}
