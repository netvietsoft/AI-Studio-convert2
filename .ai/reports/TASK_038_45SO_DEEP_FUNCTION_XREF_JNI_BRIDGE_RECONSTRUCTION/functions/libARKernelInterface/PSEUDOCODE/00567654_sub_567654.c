// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x567654
// Recovered Name: sub_567654
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x567654 | Size: 20 bytes | SHA256: e99ac4972f458a480a01ec7a537433d46858d2dfa5b44d2ebfbb486e002f33a6
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLandmark(JII)V (table at 0x10ccc38)

jlong sub_567654(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x567654 */ cbz x2, #0x567664;
    /* 0x567658 */ mov w8, #0x88;
    /* 0x56765c */ smaddl x8, w3, w8, x2;
    /* 0x567660 */ str w4, [x8, #0x78];
    return x0;
}
