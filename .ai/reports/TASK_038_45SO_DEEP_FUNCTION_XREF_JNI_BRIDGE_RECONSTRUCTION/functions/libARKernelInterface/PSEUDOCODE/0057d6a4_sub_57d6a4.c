// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d6a4
// Recovered Name: sub_57d6a4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d6a4 | Size: 12 bytes | SHA256: 1520e3333cf150d542128780c370952535d4d98155c9de2e220839902efc4261
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerOutlineBorderMarginRight(JI)V (table at 0x10ceed0)

jlong sub_57d6a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d6a4 */ cbz x2, #0x57d6ac;
    /* 0x57d6a8 */ str w3, [x2, #0x28];
    return x0;
}
