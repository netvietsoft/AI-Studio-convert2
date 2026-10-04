// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a038
// Recovered Name: sub_56a038
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a038 | Size: 36 bytes | SHA256: aeef1a1acaa02dfe88870bf95016e15f6be3c3d62765cadbe33119129bf887c9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFaceFR(JIJ)V (table at 0x10cce18)

jlong sub_56a038(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x56a038 */ cbz x2, #0x56a058;
    /* 0x56a03c */ cmp w3, #0x13;
    /* 0x56a040 */ b.hi #0x56a058;
    /* 0x56a044 */ mov w8, #0x5c0;
    /* 0x56a048 */ mov w9, #1;
    /* 0x56a04c */ umaddl x8, w3, w8, x2;
    /* 0x56a050 */ strb w9, [x8, #0x18];
    /* 0x56a054 */ str x4, [x8, #0x20];
    return x0;
}
