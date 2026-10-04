// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x567504
// Recovered Name: sub_567504
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x567504 | Size: 20 bytes | SHA256: dbbf56cef499add5ba884b6b3f606ea9d24e6650f1f897b8dfab68e2d46feb8d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetIsWithoutCache(JZ)V (table at 0x10cca28)

jlong sub_567504(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x567504 */ cbz x2, #0x567514;
    /* 0x567508 */ tst w3, #0xff;
    /* 0x56750c */ cset w8, ne;
    /* 0x567510 */ strb w8, [x2, #8];
    return x0;
}
