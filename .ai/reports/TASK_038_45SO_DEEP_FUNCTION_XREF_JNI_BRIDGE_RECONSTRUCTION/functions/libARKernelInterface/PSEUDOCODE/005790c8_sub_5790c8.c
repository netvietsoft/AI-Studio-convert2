// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5790c8
// Recovered Name: sub_5790c8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5790c8 | Size: 16 bytes | SHA256: 83ce112b160b663d964258bc050bb778f268bbd005c92cc7d382621a6ffdd0b4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativePartControlResetState(J)V (table at 0x10ce1f8)

jlong sub_5790c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x5790c8 */ cbz x2, #0x5790d4;
    /* 0x5790cc */ mov x0, x2;
    /* 0x5790d0 */ b #0x8e0a4c;
    return x0;
}
