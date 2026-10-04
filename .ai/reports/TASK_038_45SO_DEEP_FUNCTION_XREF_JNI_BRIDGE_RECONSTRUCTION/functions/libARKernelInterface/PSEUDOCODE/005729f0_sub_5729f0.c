// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5729f0
// Recovered Name: sub_5729f0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5729f0 | Size: 36 bytes | SHA256: 51eaeea60c288ef7ba8ccde738ead62e4b2979744bc2918dedd850463dfe8520
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetNailScore(JIF)V (table at 0x10cd970)

jlong sub_5729f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x5729f0 */ cbz x2, #0x572a10;
    /* 0x5729f4 */ cmp w3, #9;
    /* 0x5729f8 */ b.hi #0x572a10;
    /* 0x5729fc */ mov w8, #0x88;
    /* 0x572a00 */ mov w9, #1;
    /* 0x572a04 */ umaddl x8, w3, w8, x2;
    /* 0x572a08 */ strb w9, [x8, #0x974];
    /* 0x572a0c */ str s0, [x8, #0x978];
    return x0;
}
