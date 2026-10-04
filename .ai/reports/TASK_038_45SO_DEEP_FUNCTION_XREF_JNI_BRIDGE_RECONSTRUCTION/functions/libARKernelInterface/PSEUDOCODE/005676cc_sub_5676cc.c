// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5676cc
// Recovered Name: sub_5676cc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5676cc | Size: 28 bytes | SHA256: 3819b96aa97be3b2a23be746861dc5e8e945c4ea5bed090e731a91f2708f7864
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetHasFace3DReconstructorData(JIZ)V (table at 0x10ccbf0)

jlong sub_5676cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x5676cc */ cbz x2, #0x5676e4;
    /* 0x5676d0 */ mov w8, #0x88;
    /* 0x5676d4 */ tst w4, #0xff;
    /* 0x5676d8 */ smaddl x8, w3, w8, x2;
    /* 0x5676dc */ cset w9, ne;
    /* 0x5676e0 */ strb w9, [x8, #0x10];
    return x0;
}
