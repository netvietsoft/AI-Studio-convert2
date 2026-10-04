// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x568c18
// Recovered Name: sub_568c18
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x568c18 | Size: 20 bytes | SHA256: dbbf56cef499add5ba884b6b3f606ea9d24e6650f1f897b8dfab68e2d46feb8d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetIsWithoutCache(JZ)V (table at 0x10ccc98)

jlong sub_568c18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x568c18 */ cbz x2, #0x568c28;
    /* 0x568c1c */ tst w3, #0xff;
    /* 0x568c20 */ cset w8, ne;
    /* 0x568c24 */ strb w8, [x2, #8];
    return x0;
}
