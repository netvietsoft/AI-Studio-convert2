// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x118ec0
// Recovered Name: sub_118ec0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x118ec0 | Size: 20 bytes | SHA256: 5c8be594b4faf1a5402c70e195dd114a50abd1d64ee094169e4d8074a893618e
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setEnablePositiveValue(JZ)I (table at 0x13a030)
// Calls external APIs: _ZN3PVG15PVGAudioDecoder22setEnablePositiveValueEb

jlong sub_118ec0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x118ec0 */ cbz x2, #0x118ed4;
    /* 0x118ec4 */ tst w3, #0xff;
    /* 0x118ec8 */ mov x0, x2;
    /* 0x118ecc */ cset w1, ne;
    /* 0x118ed0 */ b #0x133110;
}
