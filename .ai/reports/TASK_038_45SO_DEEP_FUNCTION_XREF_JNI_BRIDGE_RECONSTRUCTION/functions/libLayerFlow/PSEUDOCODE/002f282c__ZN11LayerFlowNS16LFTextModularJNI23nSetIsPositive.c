// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f282c
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI23nSetIsPositiveDirectionEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f282c | Size: 16 bytes | SHA256: 03a45e5dc2d04c95359f02b208362bb4e73c5ae8b1ea67de3709d82740441a3b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsPositiveDirection(JZ)V (table at 0x53a8a0)

jobject _ZN11LayerFlowNS16LFTextModularJNI23nSetIsPositiveDirectionEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f282c */ tst w3, #0xff;
    /* 0x2f2830 */ cset w8, ne;
    /* 0x2f2834 */ strb w8, [x2, #0x1a];
    return x0;
}
