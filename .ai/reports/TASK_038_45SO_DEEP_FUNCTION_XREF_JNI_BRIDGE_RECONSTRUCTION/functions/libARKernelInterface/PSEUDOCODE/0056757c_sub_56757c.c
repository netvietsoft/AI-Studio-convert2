// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56757c
// Recovered Name: sub_56757c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56757c | Size: 20 bytes | SHA256: 606b22dcc53d79371f533269904785d6a653b2ceeebd5c45e884d58eb9241302
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetMeshTriangleNumWithoutLips(JII)V (table at 0x10ccab8)

jlong sub_56757c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x56757c */ cbz x2, #0x56758c;
    /* 0x567580 */ mov w8, #0x88;
    /* 0x567584 */ smaddl x8, w3, w8, x2;
    /* 0x567588 */ str w4, [x8, #0x44];
    return x0;
}
