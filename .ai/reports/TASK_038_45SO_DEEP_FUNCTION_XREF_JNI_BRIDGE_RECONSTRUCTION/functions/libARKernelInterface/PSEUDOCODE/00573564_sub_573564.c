// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x573564
// Recovered Name: sub_573564
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x573564 | Size: 12 bytes | SHA256: 494556deb6f0a8ac75a0afd557e85bf04554747619708317bf9304779231bf69
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetWidthAndHeight(JFF)V (table at 0x10cda18)

jlong sub_573564(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x573564 */ cbz x2, #0x57356c;
    /* 0x573568 */ stp s0, s1, [x2, #0xc];
    return x0;
}
