// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11903c
// Recovered Name: sub_11903c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11903c | Size: 20 bytes | SHA256: 0b07dd407c34d5f8ba0fea5fee1fab50261f013b3846fcc998e98243a65b2e9b
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setAudioDecoderParam(JJJ)I (table at 0x13a060)
// Calls external APIs: _ZN3PVG15PVGAudioDecoder20setAudioDecoderParamEdd

jlong sub_11903c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x11903c */ cbz x2, #0x119050;
    /* 0x119040 */ scvtf d0, x3;
    /* 0x119044 */ scvtf d1, x4;
    /* 0x119048 */ mov x0, x2;
    /* 0x11904c */ b #0x133130;
}
