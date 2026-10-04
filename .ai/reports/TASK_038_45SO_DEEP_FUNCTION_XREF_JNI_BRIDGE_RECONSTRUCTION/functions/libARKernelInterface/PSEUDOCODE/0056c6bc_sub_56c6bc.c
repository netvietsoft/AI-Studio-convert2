// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56c6bc
// Recovered Name: sub_56c6bc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56c6bc | Size: 56 bytes | SHA256: ff28f2190f317c4501fcd3c630c05b073f70b2d86eba8e4c18f40d2e8b4d436f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetExpressionInfo(JIIJIJ)V (table at 0x10cd250)

jlong sub_56c6bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x56c6bc */ cbz x2, #0x56c6f0;
    /* 0x56c6c0 */ cmp w3, #0x13;
    /* 0x56c6c4 */ b.hi #0x56c6f0;
    /* 0x56c6c8 */ cbz w4, #0x56c6f0;
    /* 0x56c6cc */ cbz w6, #0x56c6f0;
    /* 0x56c6d0 */ mov w8, #0x5c0;
    /* 0x56c6d4 */ mov w9, #1;
    /* 0x56c6d8 */ umaddl x8, w3, w8, x2;
    /* 0x56c6dc */ str x5, [x8, #0x538];
    /* 0x56c6e0 */ str w4, [x8, #0x540];
    /* 0x56c6e4 */ str x7, [x8, #0x548];
    return x0;
}
