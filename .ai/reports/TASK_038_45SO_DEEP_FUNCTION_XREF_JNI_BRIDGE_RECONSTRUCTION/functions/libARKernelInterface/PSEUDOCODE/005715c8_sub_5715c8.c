// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5715c8
// Recovered Name: sub_5715c8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5715c8 | Size: 28 bytes | SHA256: 7b197a855c802faf19db6cf362f595715c53cb367648ff9740ece8bf6ba9c912
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetApply(JZ)V (table at 0x10cd6b8)

jlong sub_5715c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x5715c8 */ cbz x2, #0x5715e0;
    /* 0x5715cc */ and w8, w3, #0xff;
    /* 0x5715d0 */ mov x0, x2;
    /* 0x5715d4 */ cmp w8, #1;
    /* 0x5715d8 */ cset w1, eq;
    /* 0x5715dc */ b #0x892080;
    return x0;
}
