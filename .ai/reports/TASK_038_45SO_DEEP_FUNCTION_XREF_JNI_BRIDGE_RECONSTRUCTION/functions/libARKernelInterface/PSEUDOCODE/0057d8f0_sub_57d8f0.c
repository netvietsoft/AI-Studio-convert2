// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d8f0
// Recovered Name: sub_57d8f0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d8f0 | Size: 20 bytes | SHA256: 5cb149aa164cbe4b5502a23921e33ed5940c4c5d841afc669a82bf2bc706924d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerEnableRotateAdsorb(JZ)V (table at 0x10cf110)

jlong sub_57d8f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d8f0 */ cbz x2, #0x57d900;
    /* 0x57d8f4 */ tst w3, #0xff;
    /* 0x57d8f8 */ cset w8, ne;
    /* 0x57d8fc */ strb w8, [x2, #0xf4];
    return x0;
}
