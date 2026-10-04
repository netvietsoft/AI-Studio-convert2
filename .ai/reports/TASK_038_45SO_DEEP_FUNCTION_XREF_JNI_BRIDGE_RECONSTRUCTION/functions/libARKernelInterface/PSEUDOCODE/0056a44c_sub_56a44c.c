// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a44c
// Recovered Name: sub_56a44c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a44c | Size: 32 bytes | SHA256: 044b93d1286eba84081d445b87812e6a45c36b0704e043f320ef1968d890834b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetRightEarLandmark2D(JI)[F (table at 0x10cd190)

jlong sub_56a44c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x56a44c */ cbz x2, #0x56a4dc;
    /* 0x56a450 */ cmp w3, #0x13;
    /* 0x56a454 */ b.hi #0x56a4dc;
    /* 0x56a458 */ mov w8, #0x5c0;
    /* 0x56a45c */ umaddl x8, w3, w8, x2;
    /* 0x56a460 */ ldr w8, [x8, #0x1cc];
    /* 0x56a464 */ cmp w8, #1;
    /* 0x56a468 */ b.lt #0x56a4dc;
}
