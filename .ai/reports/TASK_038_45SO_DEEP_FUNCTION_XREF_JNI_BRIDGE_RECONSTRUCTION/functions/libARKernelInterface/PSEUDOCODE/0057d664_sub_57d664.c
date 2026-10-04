// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d664
// Recovered Name: sub_57d664
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d664 | Size: 12 bytes | SHA256: e86b0a59d3004b6c72edef6f180ad0a170923d490b0b4acd2ac9bd087f854c99
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerOutlineBorderMinValue(JI)V (table at 0x10cee70)

jlong sub_57d664(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d664 */ cbz x2, #0x57d66c;
    /* 0x57d668 */ str w3, [x2, #0x20];
    return x0;
}
