// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x573cdc
// Recovered Name: sub_573cdc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x573cdc | Size: 24 bytes | SHA256: 2c46abe0cf70faa68476b47a4d2495f9482f595f8895944cf0de8a86079f9dad
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetImageValidRect(JIIIII)V (table at 0x10cdaf0)

jlong sub_573cdc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x573cdc */ cbz x2, #0x573cf0;
    /* 0x573ce0 */ mov w8, #0x58;
    /* 0x573ce4 */ smaddl x8, w3, w8, x2;
    /* 0x573ce8 */ stp w4, w5, [x8, #0x10];
    /* 0x573cec */ stp w6, w7, [x8, #0x18];
    return x0;
}
