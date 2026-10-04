// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d6da4
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI17nDestroyColorItemEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d6da4 | Size: 12 bytes | SHA256: db94715e12673fd5e37c7559006655efcc17e6f1619736f9eb187ef295976015
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nDestroy(J)V (table at 0x536020)

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI17nDestroyColorItemEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2d6da4 */ cbz x2, #0x2d6ddc;
    /* 0x2d6da8 */ ldrb w8, [x2];
    /* 0x2d6dac */ tbz w8, #0, #0x2d6dd4;
}
