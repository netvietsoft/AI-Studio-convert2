// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f4040
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI18nTucSetIsUnderlineEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f4040 | Size: 16 bytes | SHA256: 4757d898e6e364b32c693e7f0ca197aa9877bfe16ba515d1969abf783b59035f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nTucSetIsUnderline(JZ)V (table at 0x53b698)

jobject _ZN11LayerFlowNS16LFTextModularJNI18nTucSetIsUnderlineEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f4040 */ tst w3, #0xff;
    /* 0x2f4044 */ cset w8, ne;
    /* 0x2f4048 */ strb w8, [x2, #0xb1];
    return x0;
}
