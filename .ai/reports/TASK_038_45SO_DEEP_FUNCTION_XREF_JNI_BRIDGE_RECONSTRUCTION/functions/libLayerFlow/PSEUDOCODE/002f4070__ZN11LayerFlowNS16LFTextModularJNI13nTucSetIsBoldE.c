// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f4070
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI13nTucSetIsBoldEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f4070 | Size: 16 bytes | SHA256: 00fed124f6f1edb900ed5e79cdc2b20dc277e9dcd77a54d9bcf12c110baed7e4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nTucSetIsBold(JZ)V (table at 0x53b6f8)

jobject _ZN11LayerFlowNS16LFTextModularJNI13nTucSetIsBoldEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f4070 */ tst w3, #0xff;
    /* 0x2f4074 */ cset w8, ne;
    /* 0x2f4078 */ strb w8, [x2, #0xb3];
    return x0;
}
