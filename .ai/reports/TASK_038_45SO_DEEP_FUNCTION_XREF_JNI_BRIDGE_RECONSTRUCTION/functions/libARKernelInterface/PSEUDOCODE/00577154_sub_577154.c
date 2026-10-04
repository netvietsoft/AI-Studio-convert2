// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x577154
// Recovered Name: sub_577154
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x577154 | Size: 16 bytes | SHA256: bc4909899454d9b64cc08c535fbb167fd075aa12e8ff2f15a3e5430a93d59074
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeClearCallbackObject(J)V (table at 0x10cdc28)

jlong sub_577154(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x577154 */ cbz x2, #0x577160;
    /* 0x577158 */ mov x0, x2;
    /* 0x57715c */ b #0x574758;
    return x0;
}
