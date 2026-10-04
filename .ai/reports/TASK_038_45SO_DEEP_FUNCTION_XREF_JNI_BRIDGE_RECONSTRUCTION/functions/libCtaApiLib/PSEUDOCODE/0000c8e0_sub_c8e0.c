// Library: libCtaApiLib.so
// Function ID: libCtaApiLib::0xc8e0
// Recovered Name: sub_c8e0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc8e0 | Size: 592 bytes | SHA256: fbcfb0ff91eafec3269bc907fadbfafd5fe9095ca502b26bb2fd4532d8201987
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __cxa_atexit

void sub_c8e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 148 instructions
    /* 0xc8e0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xc8e4 */ adrp x1, #0x88000;
    /* 0xc8e8 */ adrp x0, #0x2c000;
    /* 0xc8ec */ mov x29, sp;
    /* 0xc8f0 */ str x19, [sp, #0x10];
    /* 0xc8f4 */ adrp x19, #0x88000;
    /* 0xc8f8 */ add x19, x19, #0;
    /* 0xc8fc */ add x1, x1, #0x190;
    /* 0xc900 */ mov x2, x19;
    /* 0xc904 */ add x0, x0, #0x5b8;
    __cxa_atexit();
    return x0;
    return x0;
    return x0;
    return x0;
}
