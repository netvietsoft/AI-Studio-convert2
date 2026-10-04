// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x566118
// Recovered Name: sub_566118
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x566118 | Size: 20 bytes | SHA256: fd41fe9db7725d1f2182473398a7ad9f04315a736ea774380f31e989d05676f9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFaceID(JII)V (table at 0x10cc8a8)

jlong sub_566118(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x566118 */ cbz x2, #0x566128;
    /* 0x56611c */ mov w8, #0x38;
    /* 0x566120 */ smaddl x8, w3, w8, x2;
    /* 0x566124 */ str w4, [x8, #0x18];
    return x0;
}
