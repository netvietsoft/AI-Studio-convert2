// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55fed4
// Recovered Name: sub_55fed4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55fed4 | Size: 20 bytes | SHA256: 1b0f438af8284d39dbbf140f4091ea36d77f0f7bb24edf4e25b3a1d7b67c40e1
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetDeviceOrientationType(J)I (table at 0x10cc3e0)

jlong sub_55fed4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x55fed4 */ cbz x2, #0x55fee0;
    /* 0x55fed8 */ ldr w0, [x2, #0x14];
    return x0;
    /* 0x55fee0 */ mov w0, #5;
    return x0;
}
