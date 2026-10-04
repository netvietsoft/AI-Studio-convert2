// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d1d40
// Recovered Name: _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI10nSetEnableEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d1d40 | Size: 16 bytes | SHA256: d86977974a782a0be3345d5735d1260a36cfd568a870a1c14b39cdc76b297b35
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetEnable(JZ)V (table at 0x534a00)

jobject _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI10nSetEnableEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2d1d40 */ tst w3, #0xff;
    /* 0x2d1d44 */ cset w8, ne;
    /* 0x2d1d48 */ strb w8, [x2, #0x20];
    return x0;
}
