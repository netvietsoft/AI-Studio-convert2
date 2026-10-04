// Library: libPVGVideoCodec.so
// Function ID: libPVGVideoCodec::0x648c8
// Recovered Name: _ZN8PVGVIDEO12PVGVideoInfo5validEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x648c8 | Size: 20 bytes | SHA256: daa66347975f7876405278780e7af1e82e32668175577afda6c04bf79a5836fc
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN8PVGVIDEO12PVGVideoInfo5validEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x648c8 */ ldp w8, w9, [x0];
    /* 0x648cc */ cmp w8, #0;
    /* 0x648d0 */ ccmp w9, #0, #4, gt;
    /* 0x648d4 */ cset w0, gt;
    return x0;
}
