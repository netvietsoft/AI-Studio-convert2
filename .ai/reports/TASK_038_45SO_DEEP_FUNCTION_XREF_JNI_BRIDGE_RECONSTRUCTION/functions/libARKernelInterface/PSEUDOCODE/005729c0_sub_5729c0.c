// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5729c0
// Recovered Name: sub_5729c0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5729c0 | Size: 12 bytes | SHA256: 97bdb9c3f9d8932463bec70430ec811ef3b07d22833d8ba3d40f67c33c00d185
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetNailCount(JI)V (table at 0x10cd940)

jlong sub_5729c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x5729c0 */ cbz x2, #0x5729c8;
    /* 0x5729c4 */ str w3, [x2, #0x950];
    return x0;
}
