// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5662e0
// Recovered Name: sub_5662e0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5662e0 | Size: 28 bytes | SHA256: 1a7ad9c43689201e1129ba4b82fb95fd6ef0b976695d0c657535088f54ecb675
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetTriangleNum(JI)I (table at 0x10cc9c8)

jlong sub_5662e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x5662e0 */ cbz x2, #0x5662f4;
    /* 0x5662e4 */ mov w8, #0x38;
    /* 0x5662e8 */ smaddl x8, w3, w8, x2;
    /* 0x5662ec */ ldr w0, [x8, #0x40];
    return x0;
    /* 0x5662f4 */ mov w0, wzr;
    return x0;
}
