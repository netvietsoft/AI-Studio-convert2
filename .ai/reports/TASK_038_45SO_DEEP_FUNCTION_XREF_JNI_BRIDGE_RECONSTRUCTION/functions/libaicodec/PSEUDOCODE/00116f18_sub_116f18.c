// Library: libaicodec.so
// Function ID: libaicodec::0x116f18
// Recovered Name: sub_116f18
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x116f18 | Size: 24 bytes | SHA256: 75854faeade44bf4845c5359eb80f52d3735814903c98cf04eb1381f4d0df272
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setVideoInParam(JII)I (table at 0x1ff128)
// Calls external APIs: _ZN7MMCodec10MediaParam15setVideoInParamEiiNS_16VIDEO_PIX_FORMATE

jlong sub_116f18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x116f18 */ cbz x2, #0x116f30;
    /* 0x116f1c */ mov x0, x2;
    /* 0x116f20 */ mov w1, w3;
    /* 0x116f24 */ mov w2, w4;
    /* 0x116f28 */ mov w3, #0x64;
    /* 0x116f2c */ b #0x1f5260;
}
