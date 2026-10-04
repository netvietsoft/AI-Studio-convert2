// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x568c74
// Recovered Name: sub_568c74
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x568c74 | Size: 28 bytes | SHA256: 5c2ac9347b8edd1051be7bdc03ec7ab8693afe3d3e2c13722fc987b072c2501a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetHasFaceDL3DReconstructorData(JIZ)V (table at 0x10ccd10)

jlong sub_568c74(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x568c74 */ cbz x2, #0x568c8c;
    /* 0x568c78 */ mov w8, #0x3d8;
    /* 0x568c7c */ tst w4, #0xff;
    /* 0x568c80 */ smaddl x8, w3, w8, x2;
    /* 0x568c84 */ cset w9, ne;
    /* 0x568c88 */ strb w9, [x8, #0x10];
    return x0;
}
