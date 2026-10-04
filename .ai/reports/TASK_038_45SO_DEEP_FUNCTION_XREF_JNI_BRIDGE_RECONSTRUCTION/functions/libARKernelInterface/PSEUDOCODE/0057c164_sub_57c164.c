// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57c164
// Recovered Name: sub_57c164
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57c164 | Size: 52 bytes | SHA256: 9993bf0f2f737ca15c949badcebeae376065519143b0e3021d0f25faec63207c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetShoulderID(JI)I (table at 0x10ce9f0)

jlong sub_57c164(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x57c164 */ mov w0, #-1;
    /* 0x57c168 */ cbz x2, #0x57c194;
    /* 0x57c16c */ cmp w3, #9;
    /* 0x57c170 */ b.hi #0x57c194;
    /* 0x57c174 */ mov w8, #0xa0;
    /* 0x57c178 */ umaddl x8, w3, w8, x2;
    /* 0x57c17c */ ldrb w8, [x8, #0x18];
    /* 0x57c180 */ cbz w8, #0x57c194;
    /* 0x57c184 */ mov w8, w3;
    /* 0x57c188 */ mov w9, #0xa0;
    /* 0x57c18c */ umaddl x8, w8, w9, x2;
    return x0;
}
