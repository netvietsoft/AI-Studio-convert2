// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a1a8
// Recovered Name: sub_56a1a8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a1a8 | Size: 32 bytes | SHA256: 3457d2de13bacd00f561eda035360a55fd260e55fd9bebe781562c36008876bb
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLeftEarPointCount2D(JI)I (table at 0x10cd100)

jlong sub_56a1a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x56a1a8 */ mov w0, wzr;
    /* 0x56a1ac */ cbz x2, #0x56a1c4;
    /* 0x56a1b0 */ cmp w3, #0x13;
    /* 0x56a1b4 */ b.hi #0x56a1c4;
    /* 0x56a1b8 */ mov w8, #0x5c0;
    /* 0x56a1bc */ umaddl x8, w3, w8, x2;
    /* 0x56a1c0 */ ldr w0, [x8, #0x1cc];
    return x0;
}
