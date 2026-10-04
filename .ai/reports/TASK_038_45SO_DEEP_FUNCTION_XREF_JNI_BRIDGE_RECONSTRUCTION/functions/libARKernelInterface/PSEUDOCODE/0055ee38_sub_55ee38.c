// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55ee38
// Recovered Name: sub_55ee38
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55ee38 | Size: 36 bytes | SHA256: 7248b05020f5b25c3635f3e20fc4b48c6c780d84297706fa8e68d4d137e091e3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetAnimalID(JII)V (table at 0x10cc230)

jlong sub_55ee38(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x55ee38 */ cbz x2, #0x55ee58;
    /* 0x55ee3c */ cmp w3, #9;
    /* 0x55ee40 */ b.hi #0x55ee58;
    /* 0x55ee44 */ mov w8, #0x140;
    /* 0x55ee48 */ mov w9, #1;
    /* 0x55ee4c */ umaddl x8, w3, w8, x2;
    /* 0x55ee50 */ strb w9, [x8, #0x20];
    /* 0x55ee54 */ str w4, [x8, #0x24];
    return x0;
}
