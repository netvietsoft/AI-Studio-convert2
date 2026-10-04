// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x572908
// Recovered Name: sub_572908
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x572908 | Size: 44 bytes | SHA256: 1114be7e7daa7b8af1d1a96320de8235d7b4a3236a0834a0214e2be8fac9e278
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetHandGesture(JII)V (table at 0x10cd8e0)

jlong sub_572908(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x572908 */ cbz x2, #0x572930;
    /* 0x57290c */ cmp w3, #9;
    /* 0x572910 */ b.hi #0x572930;
    /* 0x572914 */ mov w8, #0xec;
    /* 0x572918 */ cmp w4, #0xf;
    /* 0x57291c */ umaddl x8, w3, w8, x2;
    /* 0x572920 */ cset w9, lo;
    /* 0x572924 */ csinv w10, w4, wzr, lo;
    /* 0x572928 */ strb w9, [x8, #0x48];
    /* 0x57292c */ str w10, [x8, #0x4c];
    return x0;
}
