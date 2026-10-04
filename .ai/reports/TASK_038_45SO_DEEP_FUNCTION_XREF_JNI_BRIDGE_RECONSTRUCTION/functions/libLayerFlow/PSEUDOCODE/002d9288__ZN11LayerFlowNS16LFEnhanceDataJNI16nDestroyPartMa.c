// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d9288
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI16nDestroyPartMaskEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d9288 | Size: 12 bytes | SHA256: db94715e12673fd5e37c7559006655efcc17e6f1619736f9eb187ef295976015
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nDestroyPartMask(J)V (table at 0x5368f0)

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI16nDestroyPartMaskEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2d9288 */ cbz x2, #0x2d92c0;
    /* 0x2d928c */ ldrb w8, [x2];
    /* 0x2d9290 */ tbz w8, #0, #0x2d92b8;
}
