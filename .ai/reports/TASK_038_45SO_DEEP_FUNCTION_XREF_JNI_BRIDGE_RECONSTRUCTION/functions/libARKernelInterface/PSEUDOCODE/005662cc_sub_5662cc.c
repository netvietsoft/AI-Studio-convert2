// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5662cc
// Recovered Name: sub_5662cc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5662cc | Size: 20 bytes | SHA256: cd5395fccc6eacd7f1d38e62b53a432577c5a0faec95375c75f1892c83bc97c4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetTriangleNum(JII)V (table at 0x10cc9b0)

jlong sub_5662cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5662cc */ cbz x2, #0x5662dc;
    /* 0x5662d0 */ mov w8, #0x38;
    /* 0x5662d4 */ smaddl x8, w3, w8, x2;
    /* 0x5662d8 */ str w4, [x8, #0x40];
    return x0;
}
