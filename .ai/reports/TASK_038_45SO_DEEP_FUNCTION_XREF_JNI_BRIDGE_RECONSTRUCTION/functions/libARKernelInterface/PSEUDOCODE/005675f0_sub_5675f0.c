// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5675f0
// Recovered Name: sub_5675f0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5675f0 | Size: 20 bytes | SHA256: 8f6f0c261dbdf37896f77124cffb0b36b6598aad3d5c7c643bbf8ab5134f0bc0
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetTextureCoordinatesV1(JIJ)V (table at 0x10ccb30)

jlong sub_5675f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5675f0 */ cbz x2, #0x567600;
    /* 0x5675f4 */ mov w8, #0x88;
    /* 0x5675f8 */ smaddl x8, w3, w8, x2;
    /* 0x5675fc */ str x4, [x8, #0x28];
    return x0;
}
