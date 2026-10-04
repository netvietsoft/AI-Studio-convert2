// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d774
// Recovered Name: sub_57d774
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d774 | Size: 12 bytes | SHA256: e7d15a3622917ea96bb345177faf3e8d462f07ad862cdce9dbe9c2c44f8fbc5c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerDoubleTouchRotateValue(JI)V (table at 0x10ceff0)

jlong sub_57d774(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d774 */ cbz x2, #0x57d77c;
    /* 0x57d778 */ str w3, [x2, #0x40];
    return x0;
}
