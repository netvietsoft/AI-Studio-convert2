// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x577764
// Recovered Name: sub_577764
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x577764 | Size: 32 bytes | SHA256: 366c4e9ff8f1aadfea3025929d086f7ff3e126f34582867d74448cd40b04c061
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetOption(JIZ)V (table at 0x10cddc0)

jlong sub_577764(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x577764 */ cbz x2, #0x577780;
    /* 0x577768 */ tst w4, #0xff;
    /* 0x57776c */ mov x0, x2;
    /* 0x577770 */ mov w1, w3;
    /* 0x577774 */ cset w8, ne;
    /* 0x577778 */ mov w2, w8;
    /* 0x57777c */ b #0x575278;
    return x0;
}
