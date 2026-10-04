// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d5c4
// Recovered Name: sub_57d5c4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d5c4 | Size: 12 bytes | SHA256: 731f43eeb68e77c716717d8aa5d34e40df44e79b61f736823b463465bbe9502c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetClickEventTimeValue(JJ)V (table at 0x10ced80)

jlong sub_57d5c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d5c4 */ cbz x2, #0x57d5cc;
    /* 0x57d5c8 */ str x3, [x2, #8];
    return x0;
}
