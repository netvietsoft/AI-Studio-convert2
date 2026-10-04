// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a18c
// Recovered Name: sub_56a18c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a18c | Size: 28 bytes | SHA256: 110af0cd1bbb7e8b3783c49f69a753e721176c7f38f639b1dca3c9478d89b889
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLeftEarPointCount2D(JII)V (table at 0x10cd0e8)

jlong sub_56a18c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x56a18c */ cbz x2, #0x56a1a4;
    /* 0x56a190 */ cmp w3, #0x13;
    /* 0x56a194 */ b.hi #0x56a1a4;
    /* 0x56a198 */ mov w8, #0x5c0;
    /* 0x56a19c */ umaddl x8, w3, w8, x2;
    /* 0x56a1a0 */ str w4, [x8, #0x1cc];
    return x0;
}
