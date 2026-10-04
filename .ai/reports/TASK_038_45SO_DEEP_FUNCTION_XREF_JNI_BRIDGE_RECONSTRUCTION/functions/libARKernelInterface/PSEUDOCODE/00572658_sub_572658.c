// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x572658
// Recovered Name: sub_572658
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x572658 | Size: 36 bytes | SHA256: 64fe3af92862ed2a991529a4c52b1f0c8af99e032e23607b8f704a13725fd7ea
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetHandPoint(JIFF)V (table at 0x10cd850)

jlong sub_572658(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x572658 */ cbz x2, #0x572678;
    /* 0x57265c */ cmp w3, #9;
    /* 0x572660 */ b.hi #0x572678;
    /* 0x572664 */ mov w8, #0xec;
    /* 0x572668 */ mov w9, #1;
    /* 0x57266c */ umaddl x8, w3, w8, x2;
    /* 0x572670 */ strb w9, [x8, #0x34];
    /* 0x572674 */ stp s0, s1, [x8, #0x38];
    return x0;
}
