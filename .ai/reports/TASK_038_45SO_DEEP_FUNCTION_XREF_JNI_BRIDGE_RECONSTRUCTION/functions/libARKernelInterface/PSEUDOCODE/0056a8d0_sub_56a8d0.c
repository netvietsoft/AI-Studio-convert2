// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a8d0
// Recovered Name: sub_56a8d0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a8d0 | Size: 56 bytes | SHA256: 8606a6408a427887c2f0553ace432a2bfc5ef0c27d6a0ea8f385c9eca6dff295
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetGender(JII)V (table at 0x10ccf08)

jlong sub_56a8d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x56a8d0 */ cbz x2, #0x56a904;
    /* 0x56a8d4 */ cmp w3, #0x13;
    /* 0x56a8d8 */ b.hi #0x56a904;
    /* 0x56a8dc */ mov w8, #0x5c0;
    /* 0x56a8e0 */ cmp w4, #1;
    /* 0x56a8e4 */ mov w9, #3;
    /* 0x56a8e8 */ umaddl x8, w3, w8, x2;
    /* 0x56a8ec */ csinc w9, w9, wzr, ne;
    /* 0x56a8f0 */ cmp w4, #2;
    /* 0x56a8f4 */ mov w10, #1;
    /* 0x56a8f8 */ csel w9, w4, w9, eq;
    return x0;
}
