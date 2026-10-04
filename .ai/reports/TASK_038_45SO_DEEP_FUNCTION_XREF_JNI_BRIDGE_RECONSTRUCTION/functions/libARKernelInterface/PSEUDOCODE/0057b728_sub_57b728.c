// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b728
// Recovered Name: sub_57b728
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b728 | Size: 20 bytes | SHA256: 3f7ba2cea20a1554f232fb5eeff9d626d1396f3e59e18e3e75edc46df8a578bd
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetIsFirstFrame(J)Z (table at 0x10ce948)

jlong sub_57b728(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57b728 */ cbz x2, #0x57b734;
    /* 0x57b72c */ ldrb w0, [x2, #0x1f];
    return x0;
    /* 0x57b734 */ mov w0, wzr;
    return x0;
}
