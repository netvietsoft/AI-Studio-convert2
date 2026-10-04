// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57a900
// Recovered Name: sub_57a900
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57a900 | Size: 20 bytes | SHA256: e87d3fc80133e6330c542f26ac9a5e64dfbac997d2bf6467439f9e308eb46496
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayer(J)I (table at 0x10ce660)

jlong sub_57a900(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57a900 */ cbz x2, #0x57a90c;
    /* 0x57a904 */ mov x0, x2;
    /* 0x57a908 */ b #0x90b090;
    /* 0x57a90c */ mov w0, wzr;
    return x0;
}
