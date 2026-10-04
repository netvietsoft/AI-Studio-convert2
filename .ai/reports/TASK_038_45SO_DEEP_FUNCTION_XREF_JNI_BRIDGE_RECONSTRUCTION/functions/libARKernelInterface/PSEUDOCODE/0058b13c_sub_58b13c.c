// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58b13c
// Recovered Name: sub_58b13c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58b13c | Size: 24 bytes | SHA256: 8ca686e0b3a6b8415d00ba0dda8b1601af6700b39dba0d1fba8c2c6fe782ba16
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCurrentOpacityValue(JF)V (table at 0x10d0610)

jlong sub_58b13c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x58b13c */ cbz x2, #0x58b150;
    /* 0x58b140 */ ldr x8, [x2];
    /* 0x58b144 */ mov x0, x2;
    /* 0x58b148 */ ldr x1, [x8, #0x80];
    /* 0x58b14c */ br x1;
    return x0;
}
