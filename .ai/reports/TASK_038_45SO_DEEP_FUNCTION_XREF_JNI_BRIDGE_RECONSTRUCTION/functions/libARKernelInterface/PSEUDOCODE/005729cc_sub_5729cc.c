// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5729cc
// Recovered Name: sub_5729cc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5729cc | Size: 36 bytes | SHA256: 63e97f569acde10533677e1d0db8da8d624eb4130d977bdba91e5d78bfc824fd
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetNailID(JII)V (table at 0x10cd958)

jlong sub_5729cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x5729cc */ cbz x2, #0x5729ec;
    /* 0x5729d0 */ cmp w3, #9;
    /* 0x5729d4 */ b.hi #0x5729ec;
    /* 0x5729d8 */ mov w8, #0x88;
    /* 0x5729dc */ mov w9, #1;
    /* 0x5729e0 */ umaddl x8, w3, w8, x2;
    /* 0x5729e4 */ strb w9, [x8, #0x958];
    /* 0x5729e8 */ str w4, [x8, #0x95c];
    return x0;
}
