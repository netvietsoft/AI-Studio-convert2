// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56aaf8
// Recovered Name: sub_56aaf8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56aaf8 | Size: 72 bytes | SHA256: 5b823a03d05cd439a39704bba477a794ee96930a73f80767edd37ffee5f5b807
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetPosEstimate(JIFFFFFF)V (table at 0x10ccff8)

jlong sub_56aaf8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x56aaf8 */ cbz x2, #0x56ab3c;
    /* 0x56aafc */ cmp w3, #0x13;
    /* 0x56ab00 */ b.hi #0x56ab3c;
    /* 0x56ab04 */ mov w8, #0x5c0;
    /* 0x56ab08 */ fcmp s0, s0;
    /* 0x56ab0c */ umaddl x8, w3, w8, x2;
    /* 0x56ab10 */ b.vs #0x56ab38;
    /* 0x56ab14 */ mov w9, w3;
    /* 0x56ab18 */ mov w10, #0x5c0;
    /* 0x56ab1c */ umaddl x9, w9, w10, x2;
    /* 0x56ab20 */ mov w10, #1;
    return x0;
    return x0;
}
