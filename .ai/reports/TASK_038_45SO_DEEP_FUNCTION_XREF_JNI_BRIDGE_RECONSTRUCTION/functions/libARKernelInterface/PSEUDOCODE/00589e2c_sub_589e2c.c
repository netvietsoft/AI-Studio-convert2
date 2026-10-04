// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x589e2c
// Recovered Name: sub_589e2c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x589e2c | Size: 16 bytes | SHA256: 6b203cdf8c7908ac1d1579e780de1e560f34d806c4625f6b891fc9d5dba2799e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeDispatch(J)V (table at 0x10d00e8)

jlong sub_589e2c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x589e2c */ cbz x2, #0x589e38;
    /* 0x589e30 */ mov x0, x2;
    /* 0x589e34 */ b #0xa2b07c;
    return x0;
}
