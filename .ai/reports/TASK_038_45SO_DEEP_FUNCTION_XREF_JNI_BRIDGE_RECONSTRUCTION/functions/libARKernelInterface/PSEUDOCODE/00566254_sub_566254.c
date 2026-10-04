// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x566254
// Recovered Name: sub_566254
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x566254 | Size: 28 bytes | SHA256: 7d163bac78c2d8e7e93cf080cd5cc4be0e0c5626931bf01aa4473d901ca6ee5b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetVertexNum(JI)I (table at 0x10cc968)

jlong sub_566254(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x566254 */ cbz x2, #0x566268;
    /* 0x566258 */ mov w8, #0x38;
    /* 0x56625c */ smaddl x8, w3, w8, x2;
    /* 0x566260 */ ldr w0, [x8, #0x30];
    return x0;
    /* 0x566268 */ mov w0, wzr;
    return x0;
}
