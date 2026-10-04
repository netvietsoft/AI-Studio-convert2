// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ca138
// Recovered Name: _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI13nSetBgProtectEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ca138 | Size: 16 bytes | SHA256: 6eba8d86b65a8e3834fbbaff602454565d7dfdbd880f532fefcc029652751d90
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetBgProtect(JZ)V (table at 0x533650)

jobject _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI13nSetBgProtectEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2ca138 */ tst w3, #0xff;
    /* 0x2ca13c */ cset w8, ne;
    /* 0x2ca140 */ strb w8, [x2, #0x18];
    return x0;
}
