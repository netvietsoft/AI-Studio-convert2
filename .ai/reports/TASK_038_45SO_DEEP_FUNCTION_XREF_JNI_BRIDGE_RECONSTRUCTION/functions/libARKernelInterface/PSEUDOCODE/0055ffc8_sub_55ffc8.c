// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55ffc8
// Recovered Name: sub_55ffc8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55ffc8 | Size: 8 bytes | SHA256: 858cefa8c9f533c9a3f6b7193db59a743f1bedf2aeeed2270d1d138fa21aed56
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLightEstimate(J[FF)V (table at 0x10cc428)

jlong sub_55ffc8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 2 instructions
    /* 0x55ffc8 */ cbz x2, #0x560040;
    /* 0x55ffcc */ str d8, [sp, #-0x30]!;
}
