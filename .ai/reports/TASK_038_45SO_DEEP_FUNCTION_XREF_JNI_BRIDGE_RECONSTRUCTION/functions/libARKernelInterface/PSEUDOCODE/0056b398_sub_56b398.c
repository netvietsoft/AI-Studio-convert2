// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56b398
// Recovered Name: sub_56b398
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56b398 | Size: 28 bytes | SHA256: 7779033891feb42973a5bdf97515606f1503099a53a8b6fa76e3ee2f05d5ba29
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFaceEmotionFactor(JI)[F (table at 0x10cd1c0)

jlong sub_56b398(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x56b398 */ cbz x2, #0x56b420;
    /* 0x56b39c */ cmp w3, #0x13;
    /* 0x56b3a0 */ b.hi #0x56b420;
    /* 0x56b3a4 */ mov w8, #0x5c0;
    /* 0x56b3a8 */ umaddl x8, w3, w8, x2;
    /* 0x56b3ac */ ldrb w8, [x8, #0x318];
    /* 0x56b3b0 */ cbz w8, #0x56b420;
}
