// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5773b8
// Recovered Name: sub_5773b8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5773b8 | Size: 16 bytes | SHA256: c90c8658037d5bc9b82dd6f685a150ada3543a324f596d5ada489cd0cd5a76f0
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeUpdateCacheData(J)V (table at 0x10cdd18)

jlong sub_5773b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x5773b8 */ cbz x2, #0x5773c4;
    /* 0x5773bc */ mov x0, x2;
    /* 0x5773c0 */ b #0x575100;
    return x0;
}
