// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d2140
// Recovered Name: _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI18nSethasSmlieEffectEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d2140 | Size: 16 bytes | SHA256: 6c1313f4ee8c2a98b8437dce91f894fd938a414f7acb7e660e60f6fdc7b6521b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSethasSmlieEffect(JZ)V (table at 0x534d00)

jobject _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI18nSethasSmlieEffectEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2d2140 */ tst w3, #0xff;
    /* 0x2d2144 */ cset w8, ne;
    /* 0x2d2148 */ strb w8, [x2, #0x10];
    return x0;
}
