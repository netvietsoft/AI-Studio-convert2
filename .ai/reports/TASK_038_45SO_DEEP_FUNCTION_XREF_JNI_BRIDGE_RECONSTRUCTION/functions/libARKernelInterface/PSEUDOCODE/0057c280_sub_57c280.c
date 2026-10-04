// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57c280
// Recovered Name: sub_57c280
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57c280 | Size: 36 bytes | SHA256: 1a311abadc2b35ff1abec7e365b352e74f270a4397bf728648cec80502ee1fb3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetShoulderRectScore(JIF)V (table at 0x10cea38)

jlong sub_57c280(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x57c280 */ cbz x2, #0x57c2a0;
    /* 0x57c284 */ cmp w3, #9;
    /* 0x57c288 */ b.hi #0x57c2a0;
    /* 0x57c28c */ mov w8, #0xa0;
    /* 0x57c290 */ mov w9, #1;
    /* 0x57c294 */ umaddl x8, w3, w8, x2;
    /* 0x57c298 */ strb w9, [x8, #0x34];
    /* 0x57c29c */ str s0, [x8, #0x38];
    return x0;
}
