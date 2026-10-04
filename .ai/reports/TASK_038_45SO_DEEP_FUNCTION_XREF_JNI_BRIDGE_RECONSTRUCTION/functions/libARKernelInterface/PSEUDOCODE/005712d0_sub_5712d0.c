// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5712d0
// Recovered Name: sub_5712d0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5712d0 | Size: 16 bytes | SHA256: cd00b0e8cef4e3b5060b5c5f1e45a83d4d09d16b00c7a82a29d298d85d9a96a8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeControlResetState(J)V (table at 0x10cd5f8)

jlong sub_5712d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x5712d0 */ cbz x2, #0x5712dc;
    /* 0x5712d4 */ mov x0, x2;
    /* 0x5712d8 */ b #0x891fc0;
    return x0;
}
