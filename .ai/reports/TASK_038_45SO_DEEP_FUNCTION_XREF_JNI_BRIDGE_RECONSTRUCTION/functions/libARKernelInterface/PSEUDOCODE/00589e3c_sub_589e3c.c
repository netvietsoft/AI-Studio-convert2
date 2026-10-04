// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x589e3c
// Recovered Name: sub_589e3c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x589e3c | Size: 20 bytes | SHA256: c8407879b09e54c53743f79d84e199ebf581491ef321faef6e05b2a06cee4caf
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetParamType(J)I (table at 0x10d0100)

jlong sub_589e3c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x589e3c */ cbz x2, #0x589e48;
    /* 0x589e40 */ mov x0, x2;
    /* 0x589e44 */ b #0xa2b0e8;
    /* 0x589e48 */ mov w0, #-1;
    return x0;
}
