// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5712e0
// Recovered Name: sub_5712e0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5712e0 | Size: 16 bytes | SHA256: df6c314e033d6d4e5e50925dbe95256486e0dcecd3310dc2ee5616940c8b6d14
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeResetState(J)V (table at 0x10cd610)

jlong sub_5712e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x5712e0 */ cbz x2, #0x5712ec;
    /* 0x5712e4 */ mov x0, x2;
    /* 0x5712e8 */ b #0x891ff0;
    return x0;
}
