// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56754c
// Recovered Name: sub_56754c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56754c | Size: 20 bytes | SHA256: db49edf3419a9ff31f563ba48863455593d121f13e4b9aaf9ed2484e3e4761a4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetMeshTriangleNum(JII)V (table at 0x10cca88)

jlong sub_56754c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x56754c */ cbz x2, #0x56755c;
    /* 0x567550 */ mov w8, #0x88;
    /* 0x567554 */ smaddl x8, w3, w8, x2;
    /* 0x567558 */ str w4, [x8, #0x40];
    return x0;
}
