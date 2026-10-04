// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56b430
// Recovered Name: sub_56b430
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56b430 | Size: 40 bytes | SHA256: c860a33f2cfa370953d7e3bb211548f635c9a35279a05cc86c0d81798e0eb793
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetEyeLid(JIII)V (table at 0x10cd1d8)

jlong sub_56b430(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x56b430 */ cbz x2, #0x56b454;
    /* 0x56b434 */ cmp w3, #0x13;
    /* 0x56b438 */ b.hi #0x56b454;
    /* 0x56b43c */ mov w8, #0x5c0;
    /* 0x56b440 */ mov w9, #1;
    /* 0x56b444 */ umaddl x8, w3, w8, x2;
    /* 0x56b448 */ strb w9, [x8, #0x3b8];
    /* 0x56b44c */ str w4, [x8, #0x3bc];
    /* 0x56b450 */ str w5, [x8, #0x3c0];
    return x0;
}
