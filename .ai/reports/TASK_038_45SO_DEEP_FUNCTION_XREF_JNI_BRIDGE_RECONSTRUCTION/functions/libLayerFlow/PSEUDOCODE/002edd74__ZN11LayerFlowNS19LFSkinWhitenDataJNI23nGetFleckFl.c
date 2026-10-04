// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2edd74
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI23nGetFleckFlowForceLocalEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2edd74 | Size: 20 bytes | SHA256: ccdbd46b8edcfe148e2f730e87a313772b2649841b9d6af2c1f71187133de96c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetFleckFlowForceLocal(J)Z (table at 0x539540)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI23nGetFleckFlowForceLocalEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2edd74 */ cbz x2, #0x2edd80;
    /* 0x2edd78 */ ldrb w0, [x2];
    return x0;
    /* 0x2edd80 */ mov w0, wzr;
    return x0;
}
