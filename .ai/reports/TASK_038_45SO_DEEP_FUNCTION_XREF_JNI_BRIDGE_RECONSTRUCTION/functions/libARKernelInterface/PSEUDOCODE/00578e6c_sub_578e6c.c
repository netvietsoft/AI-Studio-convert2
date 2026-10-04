// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x578e6c
// Recovered Name: sub_578e6c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x578e6c | Size: 12 bytes | SHA256: 965d826ef9a77cb5d4fc2ca239a464b77ec5f7e45c7efd05f676c917934fe8e0
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetDefaultSize(JII)V (table at 0x10ce0a8)

jlong sub_578e6c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x578e6c */ cbz x2, #0x578e74;
    /* 0x578e70 */ stp w3, w4, [x2, #0x20];
    return x0;
}
