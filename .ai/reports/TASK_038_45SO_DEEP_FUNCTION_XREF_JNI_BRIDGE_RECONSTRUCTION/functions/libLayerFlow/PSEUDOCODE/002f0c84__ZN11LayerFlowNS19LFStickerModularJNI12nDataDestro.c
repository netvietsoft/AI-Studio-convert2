// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f0c84
// Recovered Name: _ZN11LayerFlowNS19LFStickerModularJNI12nDataDestroyEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f0c84 | Size: 12 bytes | SHA256: db94715e12673fd5e37c7559006655efcc17e6f1619736f9eb187ef295976015
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nDestroy(J)V (table at 0x53a428)

jobject _ZN11LayerFlowNS19LFStickerModularJNI12nDataDestroyEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2f0c84 */ cbz x2, #0x2f0cbc;
    /* 0x2f0c88 */ ldrb w8, [x2];
    /* 0x2f0c8c */ tbz w8, #0, #0x2f0cb4;
}
