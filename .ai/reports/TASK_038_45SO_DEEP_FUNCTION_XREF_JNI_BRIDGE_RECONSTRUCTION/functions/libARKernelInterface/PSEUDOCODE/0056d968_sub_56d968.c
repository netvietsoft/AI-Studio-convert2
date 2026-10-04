// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56d968
// Recovered Name: sub_56d968
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56d968 | Size: 52 bytes | SHA256: 54dce860a37276aa1eb5c7cf6d564584ab5fa46a17829cd4a64e5414f1902d0d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFoodScore(JI)F (table at 0x10cd3d0)

jlong sub_56d968(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x56d968 */ movi d0, #0000000000000000;
    /* 0x56d96c */ cbz x2, #0x56d998;
    /* 0x56d970 */ cmp w3, #9;
    /* 0x56d974 */ b.hi #0x56d998;
    /* 0x56d978 */ mov w8, #0x34;
    /* 0x56d97c */ umaddl x8, w3, w8, x2;
    /* 0x56d980 */ ldrb w8, [x8, #0x34];
    /* 0x56d984 */ cbz w8, #0x56d998;
    /* 0x56d988 */ mov w8, w3;
    /* 0x56d98c */ mov w9, #0x34;
    /* 0x56d990 */ umaddl x8, w8, w9, x2;
    return x0;
}
