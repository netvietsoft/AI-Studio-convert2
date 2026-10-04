// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x566270
// Recovered Name: sub_566270
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x566270 | Size: 20 bytes | SHA256: 5ff09b5794bd13bf1bec1d387729647d301144c3339818f7aa21299b4b2a4d77
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetReconstructTriangleIndex(JIJ)V (table at 0x10cc980)

jlong sub_566270(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x566270 */ cbz x2, #0x566280;
    /* 0x566274 */ mov w8, #0x38;
    /* 0x566278 */ smaddl x8, w3, w8, x2;
    /* 0x56627c */ str x4, [x8, #0x38];
    return x0;
}
