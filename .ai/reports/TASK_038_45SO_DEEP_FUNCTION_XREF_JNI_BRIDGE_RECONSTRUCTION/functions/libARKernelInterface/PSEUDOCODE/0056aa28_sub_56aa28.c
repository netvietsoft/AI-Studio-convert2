// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56aa28
// Recovered Name: sub_56aa28
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56aa28 | Size: 36 bytes | SHA256: 90b20b99996de8a2db3557f15c1b31c66c2206b699e9d17603c5d41c8274ea70
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetAge(JII)V (table at 0x10ccf98)

jlong sub_56aa28(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x56aa28 */ cbz x2, #0x56aa48;
    /* 0x56aa2c */ cmp w3, #0x13;
    /* 0x56aa30 */ b.hi #0x56aa48;
    /* 0x56aa34 */ mov w8, #0x5c0;
    /* 0x56aa38 */ mov w9, #1;
    /* 0x56aa3c */ umaddl x8, w3, w8, x2;
    /* 0x56aa40 */ strb w9, [x8, #0x78];
    /* 0x56aa44 */ str w4, [x8, #0x7c];
    return x0;
}
