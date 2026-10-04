// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5773a8
// Recovered Name: sub_5773a8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5773a8 | Size: 16 bytes | SHA256: 9e9df3e7975a40e96748f54a73b15f235ade8e8c28205cebb69f49bcd657d377
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeRelease(J)V (table at 0x10cdd00)

jlong sub_5773a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x5773a8 */ cbz x2, #0x5773b4;
    /* 0x5773ac */ mov x0, x2;
    /* 0x5773b0 */ b #0x5749f8;
    return x0;
}
