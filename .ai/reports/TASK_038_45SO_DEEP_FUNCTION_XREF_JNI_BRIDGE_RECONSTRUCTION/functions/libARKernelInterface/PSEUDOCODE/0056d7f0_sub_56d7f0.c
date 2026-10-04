// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56d7f0
// Recovered Name: sub_56d7f0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56d7f0 | Size: 36 bytes | SHA256: 8a9e8db35e0610e1abf49b64c2be040009d4fe2bdc5fa4d6540999f1123d0bb2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFoodID(JII)V (table at 0x10cd358)

jlong sub_56d7f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x56d7f0 */ cbz x2, #0x56d810;
    /* 0x56d7f4 */ cmp w3, #9;
    /* 0x56d7f8 */ b.hi #0x56d810;
    /* 0x56d7fc */ mov w8, #0x34;
    /* 0x56d800 */ mov w9, #1;
    /* 0x56d804 */ umaddl x8, w3, w8, x2;
    /* 0x56d808 */ strb w9, [x8, #0x18];
    /* 0x56d80c */ str w4, [x8, #0x1c];
    return x0;
}
