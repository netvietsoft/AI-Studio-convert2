// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a4ec
// Recovered Name: sub_56a4ec
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a4ec | Size: 28 bytes | SHA256: b5d82d1b148fac346476358c20b710db12c914366fca920dfb9abccbd08988f9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetPointCount2D(JII)V (table at 0x10cce78)

jlong sub_56a4ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x56a4ec */ cbz x2, #0x56a504;
    /* 0x56a4f0 */ cmp w3, #0x13;
    /* 0x56a4f4 */ b.hi #0x56a504;
    /* 0x56a4f8 */ mov w8, #0x5c0;
    /* 0x56a4fc */ umaddl x8, w3, w8, x2;
    /* 0x56a500 */ str w4, [x8, #0x44];
    return x0;
}
