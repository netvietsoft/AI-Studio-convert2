// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58ac1c
// Recovered Name: sub_58ac1c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58ac1c | Size: 20 bytes | SHA256: 01f710352e6aac5bc884382b498897f4b91a988a5109ab92eecb774b9f329ed6
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetParamCount(J)I (table at 0x10d0538)

jlong sub_58ac1c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58ac1c */ cbz x2, #0x58ac28;
    /* 0x58ac20 */ mov x0, x2;
    /* 0x58ac24 */ b #0xa2d7b4;
    /* 0x58ac28 */ mov w0, wzr;
    return x0;
}
