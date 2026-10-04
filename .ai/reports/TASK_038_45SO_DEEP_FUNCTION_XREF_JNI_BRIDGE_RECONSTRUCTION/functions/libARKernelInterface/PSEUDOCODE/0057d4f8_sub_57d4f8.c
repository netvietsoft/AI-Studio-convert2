// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d4f8
// Recovered Name: sub_57d4f8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d4f8 | Size: 20 bytes | SHA256: 98b4ce033178980b6a3e3aabe1864e910bf651ae669bc0dd73d6239ade856472
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCanvasSize(JII)V (table at 0x10ced20)

jlong sub_57d4f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d4f8 */ cbz x2, #0x57d508;
    /* 0x57d4fc */ mov w8, w3;
    /* 0x57d500 */ orr x8, x8, x4, lsl #32;
    /* 0x57d504 */ str x8, [x2];
    return x0;
}
