// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5660f8
// Recovered Name: sub_5660f8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5660f8 | Size: 12 bytes | SHA256: 83563f87990bf95322f1c57857f1b41982bd6ca894261dcff3d7a6cab4f17e31
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFaceCount(JI)V (table at 0x10cc878)

jlong sub_5660f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x5660f8 */ cbz x2, #0x566100;
    /* 0x5660fc */ str w3, [x2, #0x10];
    return x0;
}
