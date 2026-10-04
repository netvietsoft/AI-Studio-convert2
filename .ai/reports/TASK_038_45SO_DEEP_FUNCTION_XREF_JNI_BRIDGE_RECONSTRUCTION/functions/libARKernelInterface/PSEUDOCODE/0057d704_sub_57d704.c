// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d704
// Recovered Name: sub_57d704
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d704 | Size: 20 bytes | SHA256: 3eaf99e9a45a3b3c3516050fdf8d3b0c52dbbd1389b7bb9fd9cfc3486477ed7b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerLimitArea(JZ)V (table at 0x10cef60)

jlong sub_57d704(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d704 */ cbz x2, #0x57d714;
    /* 0x57d708 */ tst w3, #0xff;
    /* 0x57d70c */ cset w8, ne;
    /* 0x57d710 */ strb w8, [x2, #0x34];
    return x0;
}
