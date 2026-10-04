// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5675ac
// Recovered Name: sub_5675ac
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5675ac | Size: 20 bytes | SHA256: cf5ee3110d983628d629a5288b48e6e3bc3efbb9d5b6ad72628dc166f6c8c752
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetMeshVertexNum(JII)V (table at 0x10ccae8)

jlong sub_5675ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5675ac */ cbz x2, #0x5675bc;
    /* 0x5675b0 */ mov w8, #0x88;
    /* 0x5675b4 */ smaddl x8, w3, w8, x2;
    /* 0x5675b8 */ str w4, [x8, #0x18];
    return x0;
}
