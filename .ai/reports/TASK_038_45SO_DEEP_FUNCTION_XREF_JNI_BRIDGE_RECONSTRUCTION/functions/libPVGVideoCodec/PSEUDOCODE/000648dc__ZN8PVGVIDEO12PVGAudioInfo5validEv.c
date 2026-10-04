// Library: libPVGVideoCodec.so
// Function ID: libPVGVideoCodec::0x648dc
// Recovered Name: _ZN8PVGVIDEO12PVGAudioInfo5validEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x648dc | Size: 48 bytes | SHA256: ec6b8425793ba046e9b735a15073b24bdeec7b8c89721d33b6ebd983185e5d8d
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN8PVGVIDEO12PVGAudioInfo5validEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x648dc */ ldr w9, [x0];
    /* 0x648e0 */ mov x8, x0;
    /* 0x648e4 */ mov w0, wzr;
    /* 0x648e8 */ cmp w9, #1;
    /* 0x648ec */ b.lt #0x64908;
    /* 0x648f0 */ ldr w9, [x8, #4];
    /* 0x648f4 */ cmp w9, #1;
    /* 0x648f8 */ b.lt #0x64908;
    /* 0x648fc */ ldr w8, [x8, #8];
    /* 0x64900 */ cmp w8, #0;
    /* 0x64904 */ cset w0, ne;
    return x0;
}
