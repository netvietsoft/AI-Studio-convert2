// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee4f4
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI15nSetToneUniformEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee4f4 | Size: 16 bytes | SHA256: 4a46da72bfe597137f967500b0d44c2910c2f85da5a72dcbe508c21ec436e1f7
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetToneUniform(JZ)V (table at 0x539768)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI15nSetToneUniformEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2ee4f4 */ tst w3, #0xff;
    /* 0x2ee4f8 */ cset w8, ne;
    /* 0x2ee4fc */ strb w8, [x2, #0x74];
    return x0;
}
