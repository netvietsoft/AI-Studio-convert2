// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56612c
// Recovered Name: sub_56612c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56612c | Size: 20 bytes | SHA256: b426526e9c5167efd8308d974d360de8d8e58a2951d4b9f3c2592591f76123bd
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetReconstructVertexs(JIJ)V (table at 0x10cc8c0)

jlong sub_56612c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x56612c */ cbz x2, #0x56613c;
    /* 0x566130 */ mov w8, #0x38;
    /* 0x566134 */ smaddl x8, w3, w8, x2;
    /* 0x566138 */ str x4, [x8, #0x20];
    return x0;
}
