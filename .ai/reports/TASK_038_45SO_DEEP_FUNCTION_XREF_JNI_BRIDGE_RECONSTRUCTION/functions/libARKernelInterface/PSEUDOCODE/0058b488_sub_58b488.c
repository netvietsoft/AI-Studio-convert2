// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58b488
// Recovered Name: sub_58b488
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58b488 | Size: 28 bytes | SHA256: 2c4883956108e089e0ff046910a4950616a1b8a53e33e3165d2c73eb157d4f2a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetCurrentValue(J)F (table at 0x10d06e8)

jlong sub_58b488(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x58b488 */ cbz x2, #0x58b49c;
    /* 0x58b48c */ ldr x8, [x2];
    /* 0x58b490 */ mov x0, x2;
    /* 0x58b494 */ ldr x1, [x8, #0x70];
    /* 0x58b498 */ br x1;
    /* 0x58b49c */ movi d0, #0000000000000000;
    return x0;
}
