// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5676a4
// Recovered Name: sub_5676a4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5676a4 | Size: 20 bytes | SHA256: 10beae59e33e2193f94562bb6d52508931ed2e3d05aa70bec0ddb733be0e5182
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetMatToImage(JIJ)V (table at 0x10ccbd8)

jlong sub_5676a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5676a4 */ cbz x2, #0x5676b4;
    /* 0x5676a8 */ mov w8, #0x88;
    /* 0x5676ac */ smaddl x8, w3, w8, x2;
    /* 0x5676b0 */ str x4, [x8, #0x60];
    return x0;
}
