// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b5ec
// Recovered Name: sub_57b5ec
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b5ec | Size: 20 bytes | SHA256: 332c66c0756f6ab522427afdfd56fd04b7a6fa76bc87809d071cbaebadf5361f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetPreviewResolution(JII)V (table at 0x10ce870)

jlong sub_57b5ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57b5ec */ cbz x2, #0x57b5fc;
    /* 0x57b5f0 */ mov w8, w3;
    /* 0x57b5f4 */ orr x8, x8, x4, lsl #32;
    /* 0x57b5f8 */ stur x8, [x2, #0x14];
    return x0;
}
