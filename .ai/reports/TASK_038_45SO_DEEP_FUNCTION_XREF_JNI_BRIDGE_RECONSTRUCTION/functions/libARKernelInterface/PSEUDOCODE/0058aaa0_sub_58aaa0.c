// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58aaa0
// Recovered Name: sub_58aaa0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58aaa0 | Size: 28 bytes | SHA256: 40a9cb07e359dec6aa9b0c44e895ca38413c4e3a262faba19a41c44797fd12ea
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCurrentValue(JZ)V (table at 0x10d04c0)

jlong sub_58aaa0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x58aaa0 */ cbz x2, #0x58aab8;
    /* 0x58aaa4 */ and w8, w3, #0xff;
    /* 0x58aaa8 */ mov x0, x2;
    /* 0x58aaac */ cmp w8, #1;
    /* 0x58aab0 */ cset w1, eq;
    /* 0x58aab4 */ b #0xa2d6f4;
    return x0;
}
