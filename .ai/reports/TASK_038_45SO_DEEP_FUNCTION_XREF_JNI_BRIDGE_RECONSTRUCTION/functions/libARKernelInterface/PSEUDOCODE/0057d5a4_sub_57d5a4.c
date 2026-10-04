// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d5a4
// Recovered Name: sub_57d5a4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d5a4 | Size: 12 bytes | SHA256: ef95e1e5e11afe5b8593512aa5b213dd5b75ba558fdf3c2a0c115693ef6a59e5
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCanvasDirectionType(JI)V (table at 0x10ced50)

jlong sub_57d5a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d5a4 */ cbz x2, #0x57d5ac;
    /* 0x57d5a8 */ str w3, [x2, #0x158];
    return x0;
}
