// Library: libaicodec.so
// Function ID: libaicodec::0x117340
// Recovered Name: sub_117340
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x117340 | Size: 16 bytes | SHA256: 86e695ddb3483201d2eac84c605b68dec765c4961e04588ac523d369b42b4b99
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setVideoOutCodec(JI)I (table at 0x1ff158)
// Calls external APIs: _ZN7MMCodec10MediaParam16setVideoOutCodecENS_11MT_CODEC_IDE

jlong sub_117340(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x117340 */ cbz x2, #0x117350;
    /* 0x117344 */ mov x0, x2;
    /* 0x117348 */ mov w1, w3;
    /* 0x11734c */ b #0x1f52e0;
}
