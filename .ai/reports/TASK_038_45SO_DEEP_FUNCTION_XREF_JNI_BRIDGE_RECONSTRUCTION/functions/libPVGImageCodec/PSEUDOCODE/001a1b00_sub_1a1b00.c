// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x1a1b00
// Recovered Name: sub_1a1b00
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1a1b00 | Size: 16 bytes | SHA256: 5103821d40e1c721566a316706cff9e1050370f3bb745a4a577f3a6c04aab852
// Callers: 1 | Callees: 0 | Imports: 0


void sub_1a1b00(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x1a1b00 */ adrp x8, #0x4ca000;
    /* 0x1a1b04 */ add x8, x8, #0xf98;
    /* 0x1a1b08 */ str x8, [x0];
    return x0;
}
