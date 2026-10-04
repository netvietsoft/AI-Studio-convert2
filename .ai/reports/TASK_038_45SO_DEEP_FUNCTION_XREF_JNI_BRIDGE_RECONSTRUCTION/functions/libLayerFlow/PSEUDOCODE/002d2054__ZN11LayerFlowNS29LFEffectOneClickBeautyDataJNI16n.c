// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d2054
// Recovered Name: _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI16nSetHas_do_smileEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d2054 | Size: 16 bytes | SHA256: 4d9a2b2863279c682ba5b245c3344ea251de9064231cafc4c4168d5b74b20aa3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetHas_do_smile(JZ)V (table at 0x534bc8)

jobject _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI16nSetHas_do_smileEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2d2054 */ tst w3, #0xff;
    /* 0x2d2058 */ cset w8, ne;
    /* 0x2d205c */ strb w8, [x2, #0x38];
    return x0;
}
