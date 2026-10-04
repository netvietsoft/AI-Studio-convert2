// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5790d8
// Recovered Name: sub_5790d8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5790d8 | Size: 16 bytes | SHA256: 841aa474097106a3b65f43ec6b18d9ef6fb589b7665f7b7a874525c6cd1be3db
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeResetState(J)V (table at 0x10ce210)

jlong sub_5790d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x5790d8 */ cbz x2, #0x5790e4;
    /* 0x5790dc */ mov x0, x2;
    /* 0x5790e0 */ b #0x8e0a64;
    return x0;
}
