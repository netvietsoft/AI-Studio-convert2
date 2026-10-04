// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x118f80
// Recovered Name: sub_118f80
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x118f80 | Size: 16 bytes | SHA256: 7dfbd437b645ac73f7d207f4746058765f1e68aeb35f9f973395fd0eaf27f70d
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setAudioSmoothingTime(JI)I (table at 0x13a048)
// Calls external APIs: _ZN3PVG15PVGAudioDecoder21setAudioSmoothingTimeEd

jlong sub_118f80(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x118f80 */ cbz x2, #0x118f90;
    /* 0x118f84 */ scvtf d0, w3;
    /* 0x118f88 */ mov x0, x2;
    /* 0x118f8c */ b #0x133120;
}
