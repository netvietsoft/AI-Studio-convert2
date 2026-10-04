// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d684
// Recovered Name: sub_57d684
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d684 | Size: 12 bytes | SHA256: a7a06cf6f23fdfb7f8b82abf56683d8430c4c0c21f1e76a7c3c46ef7e9bc9900
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerOutlineBorderMarginLeft(JI)V (table at 0x10ceea0)

jlong sub_57d684(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d684 */ cbz x2, #0x57d68c;
    /* 0x57d688 */ str w3, [x2, #0x24];
    return x0;
}
