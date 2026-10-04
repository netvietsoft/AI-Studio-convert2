// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d644
// Recovered Name: sub_57d644
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d644 | Size: 12 bytes | SHA256: a20bc12c513bfe5d38c782c3e24daf1319e68fb296e0fba78afbada8f3911710
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerMaxValue(JI)V (table at 0x10cee40)

jlong sub_57d644(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d644 */ cbz x2, #0x57d64c;
    /* 0x57d648 */ str w3, [x2, #0x1c];
    return x0;
}
