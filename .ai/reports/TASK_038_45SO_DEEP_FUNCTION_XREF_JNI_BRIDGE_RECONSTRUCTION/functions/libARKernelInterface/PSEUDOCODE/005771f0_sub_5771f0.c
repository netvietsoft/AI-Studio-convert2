// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5771f0
// Recovered Name: sub_5771f0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5771f0 | Size: 20 bytes | SHA256: a9b4ab7d9e78a209990eeb32ec96f0fab5fa9616cd62ef19512d75dfec79d5a2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeOnTouchMove(JFFI)V (table at 0x10cdc88)

jlong sub_5771f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5771f0 */ cbz x2, #0x577200;
    /* 0x5771f4 */ mov x0, x2;
    /* 0x5771f8 */ mov w1, w3;
    /* 0x5771fc */ b #0x5748ec;
    return x0;
}
