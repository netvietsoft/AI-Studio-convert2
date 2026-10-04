// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b700
// Recovered Name: sub_57b700
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b700 | Size: 20 bytes | SHA256: c2e08d17a7a158b7462cb509c6e0933fa128fcd1ae860b7d5b01b63d415de9ca
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetIsIdenticalInputStream(J)Z (table at 0x10ce918)

jlong sub_57b700(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57b700 */ cbz x2, #0x57b70c;
    /* 0x57b704 */ ldrb w0, [x2, #0x1e];
    return x0;
    /* 0x57b70c */ mov w0, wzr;
    return x0;
}
