// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f2954
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI12nSetIsShadowEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f2954 | Size: 16 bytes | SHA256: a63bd9001bb1d88dfef3c71897dd161eeb245f00cec16796cbe2c62a3ec5d3cd
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsShadow(JZ)V (table at 0x53aa50)

jobject _ZN11LayerFlowNS16LFTextModularJNI12nSetIsShadowEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f2954 */ tst w3, #0xff;
    /* 0x2f2958 */ cset w8, ne;
    /* 0x2f295c */ strb w8, [x2, #0x60];
    return x0;
}
