// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58b434
// Recovered Name: sub_58b434
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58b434 | Size: 28 bytes | SHA256: cb876dfc22b929f46fce4d8dffe7453e4cc0e5e2158568e5b07071af73e2365d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetMinValue(J)F (table at 0x10d06a0)

jlong sub_58b434(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x58b434 */ cbz x2, #0x58b448;
    /* 0x58b438 */ ldr x8, [x2];
    /* 0x58b43c */ mov x0, x2;
    /* 0x58b440 */ ldr x1, [x8, #0x58];
    /* 0x58b444 */ br x1;
    /* 0x58b448 */ movi d0, #0000000000000000;
    return x0;
}
