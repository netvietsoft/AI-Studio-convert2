// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ec390
// Recovered Name: _ZN11LayerFlowNS21LFMakeupBagModularJNI7destroyEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ec390 | Size: 12 bytes | SHA256: 0b7d89e63f0ce7bf18a13895171d644c030057206ee66f4d2737d0424922edd1
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nDestroy(J)V (table at 0x538eb0)

jobject _ZN11LayerFlowNS21LFMakeupBagModularJNI7destroyEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2ec390 */ cbz x2, #0x2ec3c8;
    /* 0x2ec394 */ ldrb w8, [x2, #8];
    /* 0x2ec398 */ tbz w8, #0, #0x2ec3c0;
}
