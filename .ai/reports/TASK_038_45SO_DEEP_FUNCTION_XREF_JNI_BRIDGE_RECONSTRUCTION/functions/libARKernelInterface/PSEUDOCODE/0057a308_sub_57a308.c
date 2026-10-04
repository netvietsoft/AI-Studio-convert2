// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57a308
// Recovered Name: sub_57a308
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57a308 | Size: 16 bytes | SHA256: 9870135ed395d61e3c005b2cf07fa3dc8f8dbd0f4c115ee750d9742d72061bdd
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativePauseBGM(J)V (table at 0x10ce588)

jlong sub_57a308(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x57a308 */ cbz x2, #0x57a314;
    /* 0x57a30c */ mov x0, x2;
    /* 0x57a310 */ b #0x90ac84;
    return x0;
}
