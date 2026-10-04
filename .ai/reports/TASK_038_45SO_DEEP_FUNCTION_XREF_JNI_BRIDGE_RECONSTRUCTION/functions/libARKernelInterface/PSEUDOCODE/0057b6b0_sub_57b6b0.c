// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b6b0
// Recovered Name: sub_57b6b0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b6b0 | Size: 20 bytes | SHA256: 587b155878dfa7a07d953a5958aa9ee3df424e87e9abc43c8f723052db97e333
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetIsCaptureFrame(J)Z (table at 0x10ce8b8)

jlong sub_57b6b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57b6b0 */ cbz x2, #0x57b6bc;
    /* 0x57b6b4 */ ldrb w0, [x2, #0x1c];
    return x0;
    /* 0x57b6bc */ mov w0, wzr;
    return x0;
}
