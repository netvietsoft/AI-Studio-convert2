// Library: libaicodec.so
// Function ID: libaicodec::0x116d88
// Recovered Name: sub_116d88
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x116d88 | Size: 24 bytes | SHA256: de1a16b28a225b3f71f797994c46fa90b417bc2041352860acc2d6c2960b5e86
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setAudioInParam(JIII)I (table at 0x1ff0f8)
// Calls external APIs: _ZN7MMCodec10MediaParam15setAudioInParamEiiNS_19AUDIO_SAMPLE_FORMATE

jlong sub_116d88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x116d88 */ cbz x2, #0x116da0;
    /* 0x116d8c */ mov x0, x2;
    /* 0x116d90 */ mov w1, w3;
    /* 0x116d94 */ mov w2, w4;
    /* 0x116d98 */ mov w3, w5;
    /* 0x116d9c */ b #0x1f5220;
}
