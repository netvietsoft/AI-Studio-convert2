// Library: libCtaApiLib.so
// Function ID: libCtaApiLib::0xc7c0
// Recovered Name: sub_c7c0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc7c0 | Size: 192 bytes | SHA256: bab3115419d4edec7a9460afe59017e2bcb642039b2390850cd6d388c5fa1fb4
// Callers: 8 | Callees: 0 | Imports: 2

// Calls external APIs: __cxa_atexit, __cxa_finalize

void sub_c7c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 48 instructions
    /* 0xc7c0 */ adrp x2, #0x87000;
    /* 0xc7c4 */ ldr x2, [x2, #0xe60];
    /* 0xc7c8 */ cbz x2, #0xc7e4;
    /* 0xc7cc */ add x3, x0, #0x10;
    /* 0xc7d0 */ ldaxr w2, [x3];
    /* 0xc7d4 */ sub w4, w2, #1;
    /* 0xc7d8 */ stlxr w5, w4, [x3];
    /* 0xc7dc */ cbz w5, #0xc7f0;
    /* 0xc7e0 */ b #0xc7d0;
    /* 0xc7e4 */ ldr w2, [x0, #0x10];
    /* 0xc7e8 */ sub w3, w2, #1;
    return x0;
    return x0;
}
