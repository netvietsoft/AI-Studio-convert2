// Library: libglide-webp.so
// Function ID: libglide-webp::0x12890
// Recovered Name: sub_12890
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x12890 | Size: 60 bytes | SHA256: d1c5e07487508993cf8d93f06544a809602641e481fceedbb6182eb1a2fc58d5
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: __cxa_atexit, __cxa_finalize

void sub_12890(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x12890 */ adrp x0, #0x64000;
    /* 0x12894 */ add x0, x0, #0x8d0;
    /* 0x12898 */ b #0x11ee0;
    return x0;
    /* 0x128a0 */ b #0x1289c;
    /* 0x128a4 */ cbz x0, #0x128ac;
    /* 0x128a8 */ br x0;
    return x0;
    /* 0x128b0 */ adrp x8, #0x12000;
    /* 0x128b4 */ add x8, x8, #0x8a4;
    /* 0x128b8 */ adrp x2, #0x64000;
}
