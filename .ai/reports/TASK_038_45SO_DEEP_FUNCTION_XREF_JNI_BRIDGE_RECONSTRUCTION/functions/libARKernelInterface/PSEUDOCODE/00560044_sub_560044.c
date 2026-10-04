// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x560044
// Recovered Name: sub_560044
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x560044 | Size: 36 bytes | SHA256: c6f5f217c98db75eed8bb9935eecd4abf7d63e98f4c7119086e4b4b6c86aea44
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetARPlaneCount(JI)V (table at 0x10cc440)

jlong sub_560044(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x560044 */ cbz x2, #0x560064;
    /* 0x560048 */ cmp w3, #1;
    /* 0x56004c */ b.lt #0x560060;
    /* 0x560050 */ mov w8, #1;
    /* 0x560054 */ str w3, [x2, #0xcc];
    /* 0x560058 */ strb w8, [x2, #0xc8];
    return x0;
    /* 0x560060 */ strb wzr, [x2, #0xc8];
    return x0;
}
