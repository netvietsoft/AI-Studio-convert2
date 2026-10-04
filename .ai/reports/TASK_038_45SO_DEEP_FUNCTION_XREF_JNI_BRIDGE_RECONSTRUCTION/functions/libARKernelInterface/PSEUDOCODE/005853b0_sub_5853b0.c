// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5853b0
// Recovered Name: sub_5853b0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5853b0 | Size: 20 bytes | SHA256: 0ed815f269c4cec8f244287e8f2252d20afe68b7269cc13f956f817e0eccfcb1
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeTouchBegin(JFFI)V (table at 0x10cf998)

jlong sub_5853b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5853b0 */ cbz x2, #0x5853c0;
    /* 0x5853b4 */ mov x0, x2;
    /* 0x5853b8 */ mov w1, w3;
    /* 0x5853bc */ b #0x583ebc;
    return x0;
}
