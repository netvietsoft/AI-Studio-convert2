// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x577204
// Recovered Name: sub_577204
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x577204 | Size: 20 bytes | SHA256: 4ee3de761bb181bc317972098ccf752835039a4671dc008381da645845aa7305
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeOnTouchEnd(JFFI)V (table at 0x10cdca0)

jlong sub_577204(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x577204 */ cbz x2, #0x577214;
    /* 0x577208 */ mov x0, x2;
    /* 0x57720c */ mov w1, w3;
    /* 0x577210 */ b #0x574950;
    return x0;
}
