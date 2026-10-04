// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x577434
// Recovered Name: sub_577434
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x577434 | Size: 20 bytes | SHA256: 88eaa9c0be62f8ca0a4cde59429b4fc306886a1273efd6670f8d3d337aeec07c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeVoidOperation(JI)V (table at 0x10cdd60)

jlong sub_577434(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x577434 */ cbz x2, #0x577444;
    /* 0x577438 */ mov x0, x2;
    /* 0x57743c */ mov w1, w3;
    /* 0x577440 */ b #0x575188;
    return x0;
}
