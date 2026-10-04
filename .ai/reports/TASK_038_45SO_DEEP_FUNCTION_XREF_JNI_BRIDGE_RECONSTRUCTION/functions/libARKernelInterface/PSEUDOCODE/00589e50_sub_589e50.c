// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x589e50
// Recovered Name: sub_589e50
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x589e50 | Size: 20 bytes | SHA256: 65daa1189fc920ce85f26cec06d94b0f92d2105e3869c2a92bb632ca3f61f1b3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetParamFlag(J)I (table at 0x10d0118)

jlong sub_589e50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x589e50 */ cbz x2, #0x589e5c;
    /* 0x589e54 */ mov x0, x2;
    /* 0x589e58 */ b #0xa2b0f0;
    /* 0x589e5c */ mov w0, wzr;
    return x0;
}
