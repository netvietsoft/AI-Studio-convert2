// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a948
// Recovered Name: sub_56a948
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a948 | Size: 44 bytes | SHA256: 1c7b8deb7b8991f1ed09f3ac9f9a5c377b33c93595a8e9d21bae34d04a0bd1af
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetRace(JII)V (table at 0x10ccf38)

jlong sub_56a948(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x56a948 */ cbz x2, #0x56a970;
    /* 0x56a94c */ cmp w3, #0x13;
    /* 0x56a950 */ b.hi #0x56a970;
    /* 0x56a954 */ mov w8, #0x5c0;
    /* 0x56a958 */ cmp w4, #8;
    /* 0x56a95c */ mov w9, #1;
    /* 0x56a960 */ umaddl x8, w3, w8, x2;
    /* 0x56a964 */ csinv w10, w4, wzr, lo;
    /* 0x56a968 */ strb w9, [x8, #0x5c8];
    /* 0x56a96c */ str w10, [x8, #0x5cc];
    return x0;
}
