// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d760
// Recovered Name: sub_57d760
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d760 | Size: 20 bytes | SHA256: 9daf6069d1463654ae9b94088f99db958351e1a693ebf0a2c57180106f79f18c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerMarginLimitOnlyMove(J)Z (table at 0x10cefd8)

jlong sub_57d760(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d760 */ cbz x2, #0x57d76c;
    /* 0x57d764 */ ldrb w0, [x2, #0x3c];
    return x0;
    /* 0x57d76c */ mov w0, wzr;
    return x0;
}
