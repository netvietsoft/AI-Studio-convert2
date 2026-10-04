// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5661e4
// Recovered Name: sub_5661e4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5661e4 | Size: 20 bytes | SHA256: 99dc449a548f3bbf60fd88769b4be5bed5509acff49e00f1f6982e6da2c1f491
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetReconstructStandTextureCoordinates(JIJ)V (table at 0x10cc920)

jlong sub_5661e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5661e4 */ cbz x2, #0x5661f4;
    /* 0x5661e8 */ mov w8, #0x38;
    /* 0x5661ec */ smaddl x8, w3, w8, x2;
    /* 0x5661f0 */ str x4, [x8, #0x48];
    return x0;
}
