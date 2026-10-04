// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5659ac
// Recovered Name: sub_5659ac
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5659ac | Size: 40 bytes | SHA256: b0395a08d213f98392d0c7fe4a6cdd47d32678093834e74b604d023bd6af2172
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetErrorLabel(JI)I (table at 0x10cc7a0)

jlong sub_5659ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x5659ac */ cbz x2, #0x5659cc;
    /* 0x5659b0 */ ldr w8, [x2, #0xc];
    /* 0x5659b4 */ cmp w8, w3;
    /* 0x5659b8 */ b.le #0x5659cc;
    /* 0x5659bc */ mov w8, #0x198;
    /* 0x5659c0 */ smaddl x8, w3, w8, x2;
    /* 0x5659c4 */ ldr w0, [x8, #0x10];
    return x0;
    /* 0x5659cc */ mov w0, wzr;
    return x0;
}
