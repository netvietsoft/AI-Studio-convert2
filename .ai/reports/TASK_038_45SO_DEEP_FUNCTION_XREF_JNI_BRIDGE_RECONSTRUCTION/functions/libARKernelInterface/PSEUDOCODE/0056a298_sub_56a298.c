// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a298
// Recovered Name: sub_56a298
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a298 | Size: 32 bytes | SHA256: 3c6e4a18e370e3147633894df67d5aa1a07ce911a0425ff082d7b86c62326655
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLeftEarLandmark2D(JI)[F (table at 0x10cd130)

jlong sub_56a298(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x56a298 */ cbz x2, #0x56a330;
    /* 0x56a29c */ cmp w3, #0x13;
    /* 0x56a2a0 */ b.hi #0x56a330;
    /* 0x56a2a4 */ mov w8, #0x5c0;
    /* 0x56a2a8 */ umaddl x8, w3, w8, x2;
    /* 0x56a2ac */ ldr w9, [x8, #0x1cc];
    /* 0x56a2b0 */ cmp w9, #1;
    /* 0x56a2b4 */ b.lt #0x56a330;
}
