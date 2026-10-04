// Library: libaicodec.so
// Function ID: libaicodec::0x117400
// Recovered Name: sub_117400
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x117400 | Size: 16 bytes | SHA256: aed5a9e6567c09f38c17c163443a0354ff8d0db56a2dc5475d20f3ad9f9a7cb0
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setVideoOutProfile(JI)I (table at 0x1ff170)
// Calls external APIs: _ZN7MMCodec10MediaParam18setVideoOutProfileENS_16MT_CODEC_PROFILEE

jlong sub_117400(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x117400 */ cbz x2, #0x117410;
    /* 0x117404 */ mov x0, x2;
    /* 0x117408 */ mov w1, w3;
    /* 0x11740c */ b #0x1f52f0;
}
