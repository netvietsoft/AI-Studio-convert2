// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56d9c0
// Recovered Name: sub_56d9c0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56d9c0 | Size: 52 bytes | SHA256: 200755d45c533e53315b119618d66c84ac954afb2b27d539699bcb05b22a7939
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFoodLabel(JI)I (table at 0x10cd400)

jlong sub_56d9c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x56d9c0 */ mov w0, #-1;
    /* 0x56d9c4 */ cbz x2, #0x56d9f0;
    /* 0x56d9c8 */ cmp w3, #9;
    /* 0x56d9cc */ b.hi #0x56d9f0;
    /* 0x56d9d0 */ mov w8, #0x34;
    /* 0x56d9d4 */ umaddl x8, w3, w8, x2;
    /* 0x56d9d8 */ ldrb w8, [x8, #0x3c];
    /* 0x56d9dc */ cbz w8, #0x56d9f0;
    /* 0x56d9e0 */ mov w8, w3;
    /* 0x56d9e4 */ mov w9, #0x34;
    /* 0x56d9e8 */ umaddl x8, w8, w9, x2;
    return x0;
}
