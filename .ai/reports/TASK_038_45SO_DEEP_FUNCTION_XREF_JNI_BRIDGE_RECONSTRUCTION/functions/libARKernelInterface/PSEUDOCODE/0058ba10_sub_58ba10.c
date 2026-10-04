// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58ba10
// Recovered Name: sub_58ba10
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58ba10 | Size: 20 bytes | SHA256: d517c0b07fc627e5009bcbeaa6a8f5d3b4b211191cadae61e76ef1d7c271246e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetDefaultValue(J)I (table at 0x10d07c0)

jlong sub_58ba10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58ba10 */ cbz x2, #0x58ba1c;
    /* 0x58ba14 */ ldr w0, [x2, #0x90];
    return x0;
    /* 0x58ba1c */ mov w0, #-1;
    return x0;
}
