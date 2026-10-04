// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58b450
// Recovered Name: sub_58b450
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58b450 | Size: 28 bytes | SHA256: 99989e8c09d7bd1180a4bc4c6a9f4ef85a8692c1dacf7a6731d97a27cdbf54fc
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetMaxValue(J)F (table at 0x10d06b8)

jlong sub_58b450(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x58b450 */ cbz x2, #0x58b464;
    /* 0x58b454 */ ldr x8, [x2];
    /* 0x58b458 */ mov x0, x2;
    /* 0x58b45c */ ldr x1, [x8, #0x60];
    /* 0x58b460 */ br x1;
    /* 0x58b464 */ fmov s0, #1.00000000;
    return x0;
}
