// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d5d0
// Recovered Name: sub_57d5d0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d5d0 | Size: 20 bytes | SHA256: b51b1c1220f689cc7420a085c41002f368c125a16e12ffc2652605bb57dea358
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetClickEventTimeValue(J)J (table at 0x10ced98)

jlong sub_57d5d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d5d0 */ cbz x2, #0x57d5dc;
    /* 0x57d5d4 */ ldr x0, [x2, #8];
    return x0;
    /* 0x57d5dc */ mov x0, xzr;
    return x0;
}
