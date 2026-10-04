// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d6e4
// Recovered Name: sub_57d6e4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d6e4 | Size: 12 bytes | SHA256: c9aaa9e34a3ed38b16c40eac26d09d050a0f9068caa06e425ec9cb2be33e80ca
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerOutlineBorderMarginBottom(JI)V (table at 0x10cef30)

jlong sub_57d6e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d6e4 */ cbz x2, #0x57d6ec;
    /* 0x57d6e8 */ str w3, [x2, #0x30];
    return x0;
}
