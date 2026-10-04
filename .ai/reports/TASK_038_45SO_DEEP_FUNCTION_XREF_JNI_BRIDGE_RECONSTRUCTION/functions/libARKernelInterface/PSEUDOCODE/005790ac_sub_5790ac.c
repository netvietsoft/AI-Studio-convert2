// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5790ac
// Recovered Name: sub_5790ac
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5790ac | Size: 28 bytes | SHA256: 32bfba567cf52ec67a526aaf683e3c101783a03070bac11f86a5514a4e9c439b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetPartControlVisible(JZ)V (table at 0x10ce1e0)

jlong sub_5790ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x5790ac */ cbz x2, #0x5790c4;
    /* 0x5790b0 */ and w8, w3, #0xff;
    /* 0x5790b4 */ mov x0, x2;
    /* 0x5790b8 */ cmp w8, #1;
    /* 0x5790bc */ cset w1, eq;
    /* 0x5790c0 */ b #0x8e0a30;
    return x0;
}
