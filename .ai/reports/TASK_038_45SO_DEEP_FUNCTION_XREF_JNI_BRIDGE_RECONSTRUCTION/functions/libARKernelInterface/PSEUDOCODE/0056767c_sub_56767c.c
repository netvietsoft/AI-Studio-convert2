// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56767c
// Recovered Name: sub_56767c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56767c | Size: 20 bytes | SHA256: 5edf406c796b1ab6b15e4418516690caa0a3a8ab26c983bc1243dd445d27b4c1
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCameraParam(JIJ)V (table at 0x10ccb90)

jlong sub_56767c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x56767c */ cbz x2, #0x56768c;
    /* 0x567680 */ mov w8, #0x88;
    /* 0x567684 */ smaddl x8, w3, w8, x2;
    /* 0x567688 */ str x4, [x8, #0x50];
    return x0;
}
