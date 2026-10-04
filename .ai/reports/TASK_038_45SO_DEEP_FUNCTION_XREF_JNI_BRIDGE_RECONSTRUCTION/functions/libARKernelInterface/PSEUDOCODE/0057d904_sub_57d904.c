// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d904
// Recovered Name: sub_57d904
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d904 | Size: 20 bytes | SHA256: 4747fd611f24a799de7e7595ec1eeb173aceb9b685468734622d5d682cc18eb8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerEnableRotateAdsorb(J)Z (table at 0x10cf128)

jlong sub_57d904(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d904 */ cbz x2, #0x57d910;
    /* 0x57d908 */ ldrb w0, [x2, #0xf4];
    return x0;
    /* 0x57d910 */ mov w0, wzr;
    return x0;
}
