// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f28ec
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI12nSetIsStrokeEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f28ec | Size: 16 bytes | SHA256: c5ebde74cf2196d57114058f633528fb75ab1d22aee76f5684ac15c0a9609fc9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsStroke(JZ)V (table at 0x53a960)

jobject _ZN11LayerFlowNS16LFTextModularJNI12nSetIsStrokeEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f28ec */ tst w3, #0xff;
    /* 0x2f28f0 */ cset w8, ne;
    /* 0x2f28f4 */ strb w8, [x2, #0x48];
    return x0;
}
