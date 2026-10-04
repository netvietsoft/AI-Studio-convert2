// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d624
// Recovered Name: sub_57d624
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d624 | Size: 12 bytes | SHA256: c8a5aa9aeecc290e5fea38a883044eebec59f40b1f1b767ff65783e5d41ea506
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerMinValue(JI)V (table at 0x10cee10)

jlong sub_57d624(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d624 */ cbz x2, #0x57d62c;
    /* 0x57d628 */ str w3, [x2, #0x18];
    return x0;
}
