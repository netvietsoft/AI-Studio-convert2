// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a004
// Recovered Name: sub_56a004
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a004 | Size: 52 bytes | SHA256: 6ed460356e3802f877572f22db9fac89559d6725a4121681d5bbb75f9dd8292e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFaceID(JI)I (table at 0x10cce00)

jlong sub_56a004(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x56a004 */ mov w0, #-1;
    /* 0x56a008 */ cbz x2, #0x56a034;
    /* 0x56a00c */ cmp w3, #0x13;
    /* 0x56a010 */ b.hi #0x56a034;
    /* 0x56a014 */ mov w8, #0x5c0;
    /* 0x56a018 */ umaddl x8, w3, w8, x2;
    /* 0x56a01c */ ldrb w8, [x8, #0x28];
    /* 0x56a020 */ cbz w8, #0x56a034;
    /* 0x56a024 */ mov w8, w3;
    /* 0x56a028 */ mov w9, #0x5c0;
    /* 0x56a02c */ umaddl x8, w8, w9, x2;
    return x0;
}
