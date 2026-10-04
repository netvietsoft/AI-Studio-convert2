// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d718
// Recovered Name: sub_57d718
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d718 | Size: 20 bytes | SHA256: 5c7c7d8bdb6507a7409205125f9484a22cd44dfc84df3cc727f120094b513b67
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerLimitArea(J)Z (table at 0x10cef78)

jlong sub_57d718(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d718 */ cbz x2, #0x57d724;
    /* 0x57d71c */ ldrb w0, [x2, #0x34];
    return x0;
    /* 0x57d724 */ mov w0, wzr;
    return x0;
}
