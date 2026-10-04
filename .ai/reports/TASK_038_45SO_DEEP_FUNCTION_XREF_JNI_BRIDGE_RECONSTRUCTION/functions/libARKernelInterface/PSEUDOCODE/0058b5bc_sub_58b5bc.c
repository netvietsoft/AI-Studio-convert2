// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58b5bc
// Recovered Name: sub_58b5bc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58b5bc | Size: 24 bytes | SHA256: 95445e7c757b42dcf8c6a6221d6f9995fcff5e67e223b1226abde71c78342024
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCurrentValue(JF)V (table at 0x10d0730)

jlong sub_58b5bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x58b5bc */ cbz x2, #0x58b5d0;
    /* 0x58b5c0 */ ldr x8, [x2];
    /* 0x58b5c4 */ mov x0, x2;
    /* 0x58b5c8 */ ldr x1, [x8, #0xa0];
    /* 0x58b5cc */ br x1;
    return x0;
}
