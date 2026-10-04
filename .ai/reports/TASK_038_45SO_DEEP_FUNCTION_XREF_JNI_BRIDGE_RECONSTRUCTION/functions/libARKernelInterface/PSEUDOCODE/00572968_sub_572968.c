// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x572968
// Recovered Name: sub_572968
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x572968 | Size: 36 bytes | SHA256: 449ed8ef8d5dc8aa3beac57c13e3b2ffeb465f599b0f0302cc96a58efe044be7
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetHandGestureScore(JIF)V (table at 0x10cd910)

jlong sub_572968(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x572968 */ cbz x2, #0x572988;
    /* 0x57296c */ cmp w3, #9;
    /* 0x572970 */ b.hi #0x572988;
    /* 0x572974 */ mov w8, #0xec;
    /* 0x572978 */ mov w9, #1;
    /* 0x57297c */ umaddl x8, w3, w8, x2;
    /* 0x572980 */ strb w9, [x8, #0x50];
    /* 0x572984 */ str s0, [x8, #0x54];
    return x0;
}
