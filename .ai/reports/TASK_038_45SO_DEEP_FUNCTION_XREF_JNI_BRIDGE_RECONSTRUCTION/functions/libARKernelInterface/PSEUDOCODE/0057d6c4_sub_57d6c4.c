// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d6c4
// Recovered Name: sub_57d6c4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d6c4 | Size: 12 bytes | SHA256: f252fabf8c473d12be6e7d471070c1de5618124f7dad8595a4939505a975ee2e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerOutlineBorderMarginTop(JI)V (table at 0x10cef00)

jlong sub_57d6c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d6c4 */ cbz x2, #0x57d6cc;
    /* 0x57d6c8 */ str w3, [x2, #0x2c];
    return x0;
}
