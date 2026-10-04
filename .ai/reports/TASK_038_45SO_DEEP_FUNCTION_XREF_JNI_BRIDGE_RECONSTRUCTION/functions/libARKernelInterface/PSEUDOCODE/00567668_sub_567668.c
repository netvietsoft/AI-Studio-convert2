// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x567668
// Recovered Name: sub_567668
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x567668 | Size: 20 bytes | SHA256: c1ab67dbbb2cdc16d9691b560e07dd0c1aebe4a40ff710fa50b9e13ee00c504e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetVertexNormals(JIJ)V (table at 0x10ccb78)

jlong sub_567668(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x567668 */ cbz x2, #0x567678;
    /* 0x56766c */ mov w8, #0x88;
    /* 0x567670 */ smaddl x8, w3, w8, x2;
    /* 0x567674 */ str x4, [x8, #0x38];
    return x0;
}
