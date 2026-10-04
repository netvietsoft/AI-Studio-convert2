// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d780
// Recovered Name: sub_57d780
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d780 | Size: 20 bytes | SHA256: 8e844914f50f6349c6b7b115bfc349de05b8769165d115479107e67519bdecd6
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerDoubleTouchRotateValue(J)I (table at 0x10cf008)

jlong sub_57d780(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d780 */ cbz x2, #0x57d78c;
    /* 0x57d784 */ ldr w0, [x2, #0x40];
    return x0;
    /* 0x57d78c */ mov w0, wzr;
    return x0;
}
