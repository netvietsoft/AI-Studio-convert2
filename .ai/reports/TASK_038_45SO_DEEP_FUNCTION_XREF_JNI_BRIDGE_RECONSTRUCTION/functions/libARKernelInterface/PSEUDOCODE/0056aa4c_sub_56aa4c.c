// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56aa4c
// Recovered Name: sub_56aa4c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56aa4c | Size: 52 bytes | SHA256: da51c7933b88b0b0d1a16c76b487176f5cc20ff71794ba86f9294cad3f2cb2a7
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetAge(JI)I (table at 0x10ccfb0)

jlong sub_56aa4c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x56aa4c */ mov w0, #-1;
    /* 0x56aa50 */ cbz x2, #0x56aa7c;
    /* 0x56aa54 */ cmp w3, #0x13;
    /* 0x56aa58 */ b.hi #0x56aa7c;
    /* 0x56aa5c */ mov w8, #0x5c0;
    /* 0x56aa60 */ umaddl x8, w3, w8, x2;
    /* 0x56aa64 */ ldrb w8, [x8, #0x78];
    /* 0x56aa68 */ cbz w8, #0x56aa7c;
    /* 0x56aa6c */ mov w8, w3;
    /* 0x56aa70 */ mov w9, #0x5c0;
    /* 0x56aa74 */ umaddl x8, w8, w9, x2;
    return x0;
}
