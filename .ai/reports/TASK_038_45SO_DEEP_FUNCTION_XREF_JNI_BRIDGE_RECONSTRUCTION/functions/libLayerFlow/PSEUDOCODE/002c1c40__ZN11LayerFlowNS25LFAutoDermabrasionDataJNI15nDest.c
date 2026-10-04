// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c1c40
// Recovered Name: _ZN11LayerFlowNS25LFAutoDermabrasionDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c1c40 | Size: 12 bytes | SHA256: 0b7d89e63f0ce7bf18a13895171d644c030057206ee66f4d2737d0424922edd1
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nDestroy(J)V (table at 0x531da8)

jobject _ZN11LayerFlowNS25LFAutoDermabrasionDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2c1c40 */ cbz x2, #0x2c1c78;
    /* 0x2c1c44 */ ldrb w8, [x2, #8];
    /* 0x2c1c48 */ tbz w8, #0, #0x2c1c70;
}
