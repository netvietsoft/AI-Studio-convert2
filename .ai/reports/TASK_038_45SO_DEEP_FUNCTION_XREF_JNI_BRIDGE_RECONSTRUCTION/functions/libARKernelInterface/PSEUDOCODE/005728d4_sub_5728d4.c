// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5728d4
// Recovered Name: sub_5728d4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5728d4 | Size: 52 bytes | SHA256: a37b4d6ba162a26d9bae8bf5a270558bff03c213fb7c981a146d9c6572d295bd
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetHandScore(JI)F (table at 0x10cd8c8)

jlong sub_5728d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x5728d4 */ movi d0, #0000000000000000;
    /* 0x5728d8 */ cbz x2, #0x572904;
    /* 0x5728dc */ cmp w3, #9;
    /* 0x5728e0 */ b.hi #0x572904;
    /* 0x5728e4 */ mov w8, #0xec;
    /* 0x5728e8 */ umaddl x8, w3, w8, x2;
    /* 0x5728ec */ ldrb w8, [x8, #0x40];
    /* 0x5728f0 */ cbz w8, #0x572904;
    /* 0x5728f4 */ mov w8, w3;
    /* 0x5728f8 */ mov w9, #0xec;
    /* 0x5728fc */ umaddl x8, w8, w9, x2;
    return x0;
}
