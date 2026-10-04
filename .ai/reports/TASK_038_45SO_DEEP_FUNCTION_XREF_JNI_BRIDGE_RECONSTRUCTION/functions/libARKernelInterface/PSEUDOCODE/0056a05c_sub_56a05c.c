// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a05c
// Recovered Name: sub_56a05c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a05c | Size: 52 bytes | SHA256: 8f616e99d2febb3e01b0c5a0471419e07e08b5f4b51d8a7b3f8aaf60d096a8bb
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFaceFR(JI)J (table at 0x10cce30)

jlong sub_56a05c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x56a05c */ mov x0, #-1;
    /* 0x56a060 */ cbz x2, #0x56a08c;
    /* 0x56a064 */ cmp w3, #0x13;
    /* 0x56a068 */ b.hi #0x56a08c;
    /* 0x56a06c */ mov w8, #0x5c0;
    /* 0x56a070 */ umaddl x8, w3, w8, x2;
    /* 0x56a074 */ ldrb w8, [x8, #0x18];
    /* 0x56a078 */ cbz w8, #0x56a08c;
    /* 0x56a07c */ mov w8, w3;
    /* 0x56a080 */ mov w9, #0x5c0;
    /* 0x56a084 */ umaddl x8, w8, w9, x2;
    return x0;
}
