// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56762c
// Recovered Name: sub_56762c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56762c | Size: 20 bytes | SHA256: 180dc4fafbb68dde552af70cab0a83e0bab483e3ffc6787313a3827e35f0399d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSet3DIndex(JIJ)V (table at 0x10ccc08)

jlong sub_56762c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x56762c */ cbz x2, #0x56763c;
    /* 0x567630 */ mov w8, #0x88;
    /* 0x567634 */ smaddl x8, w3, w8, x2;
    /* 0x567638 */ str x4, [x8, #0x68];
    return x0;
}
