// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x1a1ba4
// Recovered Name: _ZN8PVGIMAGE16getPVGIccProfileENS_14ColorSpaceTypeE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1a1ba4 | Size: 16 bytes | SHA256: 2350e07a1cd48373707cda286bbf00c1c491163ab634e27d0acffd05962bfde0
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN8PVGIMAGE16getPVGIccProfileENS_14ColorSpaceTypeE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x1a1ba4 */ adrp x8, #0x4ec000;
    /* 0x1a1ba8 */ add x8, x8, #0x518;
    /* 0x1a1bac */ ldr x0, [x8, w0, sxtw #3];
    return x0;
}
