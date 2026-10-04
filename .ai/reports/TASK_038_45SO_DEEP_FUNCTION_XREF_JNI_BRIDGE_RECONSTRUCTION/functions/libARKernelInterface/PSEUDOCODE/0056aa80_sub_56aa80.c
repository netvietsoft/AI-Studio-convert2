// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56aa80
// Recovered Name: sub_56aa80
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56aa80 | Size: 52 bytes | SHA256: e8f30c24676cee8e83aada1b2cd524cf90877b3155474b8ada10c58f5426e144
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetChildAgeType(JII)V (table at 0x10ccfc8)

jlong sub_56aa80(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x56aa80 */ cbz x2, #0x56aab0;
    /* 0x56aa84 */ cmp w3, #0x13;
    /* 0x56aa88 */ b.hi #0x56aab0;
    /* 0x56aa8c */ mov w8, #0x5c0;
    /* 0x56aa90 */ cmp w4, #0;
    /* 0x56aa94 */ mov w9, #1;
    /* 0x56aa98 */ umaddl x8, w3, w8, x2;
    /* 0x56aa9c */ csetm w10, ne;
    /* 0x56aaa0 */ cmp w4, #1;
    /* 0x56aaa4 */ csinc w10, w10, wzr, ne;
    /* 0x56aaa8 */ strb w9, [x8, #0x80];
    return x0;
}
