// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5632dc
// Recovered Name: sub_5632dc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5632dc | Size: 12 bytes | SHA256: 85e43ff40ad490f0725d1cbb9d803d4a51da2da8a2f2a665c08be225212959e9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetWidthAndHeight(JII)V (table at 0x10cc6e0)

jlong sub_5632dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x5632dc */ cbz x2, #0x5632e4;
    /* 0x5632e0 */ stp w3, w4, [x2, #0xc];
    return x0;
}
