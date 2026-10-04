// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58b3bc
// Recovered Name: sub_58b3bc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58b3bc | Size: 24 bytes | SHA256: 9d57de405136a46bcd5b33a6694e330b3e573c6384f310325455ac4620751ef4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeDispatch(J)V (table at 0x10d0688)

jlong sub_58b3bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x58b3bc */ cbz x2, #0x58b3d0;
    /* 0x58b3c0 */ ldr x8, [x2];
    /* 0x58b3c4 */ mov x0, x2;
    /* 0x58b3c8 */ ldr x1, [x8, #0x48];
    /* 0x58b3cc */ br x1;
    return x0;
}
