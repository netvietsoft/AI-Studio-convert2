// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55fea0
// Recovered Name: sub_55fea0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55fea0 | Size: 20 bytes | SHA256: 1d34dcead5261e94aae831acb4edff7db6d8b202726a2ee1b4d09c207ebbd9f6
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetIsFrontCamera(JZ)V (table at 0x10cc398)

jlong sub_55fea0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x55fea0 */ cbz x2, #0x55feb0;
    /* 0x55fea4 */ tst w3, #0xff;
    /* 0x55fea8 */ cset w8, ne;
    /* 0x55feac */ strb w8, [x2, #0x10];
    return x0;
}
