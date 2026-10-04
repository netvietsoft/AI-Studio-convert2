// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x1a1b10
// Recovered Name: sub_1a1b10
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1a1b10 | Size: 24 bytes | SHA256: c7f47982a5b67760a75b8534a6fdb7e539dea81ba63329d5d7b4e23d00712cac
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdlPv

void sub_1a1b10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x1a1b10 */ adrp x8, #0x4ca000;
    /* 0x1a1b14 */ add x8, x8, #0xf98;
    /* 0x1a1b18 */ str x8, [x0];
    return x0;
    return x0;
    /* 0x1a1b24 */ b #0x4c2ce0;
}
