// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x572528
// Recovered Name: sub_572528
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x572528 | Size: 52 bytes | SHA256: 32f430e33187e59ba264bd4e25c4cae385668a7b6b360594cdad94b5c321f032
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetHandID(JI)I (table at 0x10cd808)

jlong sub_572528(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x572528 */ mov w0, #-1;
    /* 0x57252c */ cbz x2, #0x572558;
    /* 0x572530 */ cmp w3, #9;
    /* 0x572534 */ b.hi #0x572558;
    /* 0x572538 */ mov w8, #0xec;
    /* 0x57253c */ umaddl x8, w3, w8, x2;
    /* 0x572540 */ ldrb w8, [x8, #0x18];
    /* 0x572544 */ cbz w8, #0x572558;
    /* 0x572548 */ mov w8, w3;
    /* 0x57254c */ mov w9, #0xec;
    /* 0x572550 */ umaddl x8, w8, w9, x2;
    return x0;
}
