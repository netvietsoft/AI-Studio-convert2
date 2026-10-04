// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56d99c
// Recovered Name: sub_56d99c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56d99c | Size: 36 bytes | SHA256: f18f272ef23a23d2a815519ffd5fe077c17cefac5b6a11ddff829a448adf323b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFoodLabel(JII)V (table at 0x10cd3e8)

jlong sub_56d99c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x56d99c */ cbz x2, #0x56d9bc;
    /* 0x56d9a0 */ cmp w3, #9;
    /* 0x56d9a4 */ b.hi #0x56d9bc;
    /* 0x56d9a8 */ mov w8, #0x34;
    /* 0x56d9ac */ mov w9, #1;
    /* 0x56d9b0 */ umaddl x8, w3, w8, x2;
    /* 0x56d9b4 */ strb w9, [x8, #0x3c];
    /* 0x56d9b8 */ str w4, [x8, #0x40];
    return x0;
}
