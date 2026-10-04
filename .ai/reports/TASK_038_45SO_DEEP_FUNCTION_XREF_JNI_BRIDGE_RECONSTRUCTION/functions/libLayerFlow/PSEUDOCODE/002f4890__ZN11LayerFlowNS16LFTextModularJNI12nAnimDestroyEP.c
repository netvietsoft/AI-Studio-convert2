// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f4890
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI12nAnimDestroyEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f4890 | Size: 12 bytes | SHA256: 0b7d89e63f0ce7bf18a13895171d644c030057206ee66f4d2737d0424922edd1
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nDestroy(J)V (table at 0x53b8a8)

jobject _ZN11LayerFlowNS16LFTextModularJNI12nAnimDestroyEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2f4890 */ cbz x2, #0x2f48c8;
    /* 0x2f4894 */ ldrb w8, [x2, #8];
    /* 0x2f4898 */ tbz w8, #0, #0x2f48c0;
}
