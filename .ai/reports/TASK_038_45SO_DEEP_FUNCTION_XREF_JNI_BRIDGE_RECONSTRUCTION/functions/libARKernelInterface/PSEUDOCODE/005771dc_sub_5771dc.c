// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5771dc
// Recovered Name: sub_5771dc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5771dc | Size: 20 bytes | SHA256: 65f2d4a9e917d324a036281df0bfb14bd66f8b6f1a74dd2e93d8bee652c33f21
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeOnTouchBegin(JFFI)V (table at 0x10cdc70)

jlong sub_5771dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5771dc */ cbz x2, #0x5771ec;
    /* 0x5771e0 */ mov x0, x2;
    /* 0x5771e4 */ mov w1, w3;
    /* 0x5771e8 */ b #0x574888;
    return x0;
}
