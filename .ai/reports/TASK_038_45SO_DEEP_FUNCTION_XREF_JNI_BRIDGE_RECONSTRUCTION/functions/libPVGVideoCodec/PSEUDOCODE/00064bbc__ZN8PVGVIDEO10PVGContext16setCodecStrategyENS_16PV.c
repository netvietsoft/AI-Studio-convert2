// Library: libPVGVideoCodec.so
// Function ID: libPVGVideoCodec::0x64bbc
// Recovered Name: _ZN8PVGVIDEO10PVGContext16setCodecStrategyENS_16PVGCodecStrategyE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x64bbc | Size: 16 bytes | SHA256: b3bde855ca41f602316c640efb7840488212b897007476ae61af6763fb4fd29a
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN8PVGVIDEO10PVGContext16setCodecStrategyENS_16PVGCodecStrategyE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x64bbc */ mov x8, x0;
    /* 0x64bc0 */ mov w0, wzr;
    /* 0x64bc4 */ str x1, [x8, #0x38];
    return x0;
}
