// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x567604
// Recovered Name: sub_567604
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x567604 | Size: 20 bytes | SHA256: 3e142926f511e2396d379b4f880738d3ce5b35d531cf88d7126c9cd0103b09fc
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetTextureCoordinatesV2(JIJ)V (table at 0x10ccb48)

jlong sub_567604(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x567604 */ cbz x2, #0x567614;
    /* 0x567608 */ mov w8, #0x88;
    /* 0x56760c */ smaddl x8, w3, w8, x2;
    /* 0x567610 */ str x4, [x8, #0x30];
    return x0;
}
