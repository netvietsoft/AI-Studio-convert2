// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x118dfc
// Recovered Name: sub_118dfc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x118dfc | Size: 24 bytes | SHA256: 6b2eff72530abe3714d0b8556a62a391b51cbb6f4a4cfab83457c0203d2c659a
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setAudioOutParameter(JIII)I (table at 0x13a018)
// Calls external APIs: _ZN3PVG15PVGAudioDecoder20setAudioOutParameterEiiNS_9PVGFormatE

jlong sub_118dfc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x118dfc */ cbz x2, #0x118e14;
    /* 0x118e00 */ mov x0, x2;
    /* 0x118e04 */ mov w1, w3;
    /* 0x118e08 */ mov w2, w4;
    /* 0x118e0c */ mov w3, w5;
    /* 0x118e10 */ b #0x133100;
}
