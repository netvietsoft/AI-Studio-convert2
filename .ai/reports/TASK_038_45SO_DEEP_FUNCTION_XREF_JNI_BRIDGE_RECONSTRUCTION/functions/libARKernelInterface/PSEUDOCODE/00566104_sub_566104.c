// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x566104
// Recovered Name: sub_566104
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x566104 | Size: 20 bytes | SHA256: 7cae5ca1bc28125bb9f45f8a25ab0f21892809284653925b7e3311a865b5f213
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFaceCount(J)I (table at 0x10cc890)

jlong sub_566104(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x566104 */ cbz x2, #0x566110;
    /* 0x566108 */ ldr w0, [x2, #0x10];
    return x0;
    /* 0x566110 */ mov w0, wzr;
    return x0;
}
