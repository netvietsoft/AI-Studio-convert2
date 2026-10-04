// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ce76c
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI15nSetAiRepairAllEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ce76c | Size: 16 bytes | SHA256: 142ac1c1234967dccd71180629078cc7fbad9d8c43e4adf34b8645945ad40a4b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetAiRepairAll(JZ)V (table at 0x534388)

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI15nSetAiRepairAllEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2ce76c */ tst w3, #0xff;
    /* 0x2ce770 */ cset w8, ne;
    /* 0x2ce774 */ strb w8, [x2, #4];
    return x0;
}
