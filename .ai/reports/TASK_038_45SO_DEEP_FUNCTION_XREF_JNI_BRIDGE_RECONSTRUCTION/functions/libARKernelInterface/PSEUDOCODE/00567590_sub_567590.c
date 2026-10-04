// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x567590
// Recovered Name: sub_567590
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x567590 | Size: 28 bytes | SHA256: 2f0acf49de9a728ba4b7e1274caf97375191b5bb750bbcdbf6e20a4c3a65c2c3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetMeshTriangleNumWithoutLips(JI)I (table at 0x10ccad0)

jlong sub_567590(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x567590 */ cbz x2, #0x5675a4;
    /* 0x567594 */ mov w8, #0x88;
    /* 0x567598 */ smaddl x8, w3, w8, x2;
    /* 0x56759c */ ldr w0, [x8, #0x44];
    return x0;
    /* 0x5675a4 */ mov w0, wzr;
    return x0;
}
