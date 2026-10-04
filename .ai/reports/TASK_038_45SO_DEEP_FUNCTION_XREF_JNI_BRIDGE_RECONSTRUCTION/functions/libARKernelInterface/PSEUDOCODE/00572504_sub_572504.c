// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x572504
// Recovered Name: sub_572504
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x572504 | Size: 36 bytes | SHA256: 09a0f67f1b8dd413b7161ee745257d8474bd8c3f17f3905d1c0c5b482162b03e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetHandID(JII)V (table at 0x10cd7f0)

jlong sub_572504(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x572504 */ cbz x2, #0x572524;
    /* 0x572508 */ cmp w3, #9;
    /* 0x57250c */ b.hi #0x572524;
    /* 0x572510 */ mov w8, #0xec;
    /* 0x572514 */ mov w9, #1;
    /* 0x572518 */ umaddl x8, w3, w8, x2;
    /* 0x57251c */ strb w9, [x8, #0x18];
    /* 0x572520 */ str w4, [x8, #0x1c];
    return x0;
}
