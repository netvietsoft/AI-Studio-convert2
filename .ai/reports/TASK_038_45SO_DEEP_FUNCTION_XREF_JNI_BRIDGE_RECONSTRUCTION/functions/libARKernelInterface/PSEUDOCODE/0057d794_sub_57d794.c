// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d794
// Recovered Name: sub_57d794
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d794 | Size: 20 bytes | SHA256: e58db50d807296424e7f32f895f2cb0ea3a1a934aafd58206b0c417aac5f56ac
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetEnableMoveAdsorb(JZ)V (table at 0x10cf020)

jlong sub_57d794(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d794 */ cbz x2, #0x57d7a4;
    /* 0x57d798 */ tst w3, #0xff;
    /* 0x57d79c */ cset w8, ne;
    /* 0x57d7a0 */ strb w8, [x2, #0x44];
    return x0;
}
