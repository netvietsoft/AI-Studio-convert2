// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f2a9c
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI14nSetShowPinyinEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f2a9c | Size: 16 bytes | SHA256: 15c847ae9bce206a3de2d631ed6ac32a8b99a1ba3ce6c2a932d929507b1a360d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetShowPinyin(JZ)V (table at 0x53ab40)

jobject _ZN11LayerFlowNS16LFTextModularJNI14nSetShowPinyinEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f2a9c */ tst w3, #0xff;
    /* 0x2f2aa0 */ cset w8, ne;
    /* 0x2f2aa4 */ strb w8, [x2, #0xa4];
    return x0;
}
