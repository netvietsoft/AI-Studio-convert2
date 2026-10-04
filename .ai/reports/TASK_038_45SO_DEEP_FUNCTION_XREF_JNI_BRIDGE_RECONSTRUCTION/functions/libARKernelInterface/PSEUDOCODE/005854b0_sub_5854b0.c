// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5854b0
// Recovered Name: sub_5854b0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5854b0 | Size: 20 bytes | SHA256: 97238f697c60299e1b4c2db6b6b5c5b9f23d699b8a4ead7177d51bb78d33eb12
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetSelectedLayer(J)J (table at 0x10cfa40)

jlong sub_5854b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5854b0 */ cbz x2, #0x5854bc;
    /* 0x5854b4 */ mov x0, x2;
    /* 0x5854b8 */ b #0x584374;
    /* 0x5854bc */ mov x0, xzr;
    return x0;
}
