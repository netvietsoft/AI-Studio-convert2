// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f2b84
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI12nSetIsShrinkEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f2b84 | Size: 16 bytes | SHA256: 37b31465774255386ded95a4f7c027a32b2055af87e15355f687c3424a0ead34
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsShrink(JZ)V (table at 0x53ac60)

jobject _ZN11LayerFlowNS16LFTextModularJNI12nSetIsShrinkEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f2b84 */ tst w3, #0xff;
    /* 0x2f2b88 */ cset w8, ne;
    /* 0x2f2b8c */ strb w8, [x2, #0xd4];
    return x0;
}
