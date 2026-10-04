// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f379c
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI10nSetIsLiveEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f379c | Size: 20 bytes | SHA256: 6df729e71405051c6f5a8fee645f404d6fced6e401c2124579a32d1e8bb337d5
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsLive(JZ)V (table at 0x53b248)

jobject _ZN11LayerFlowNS16LFTextModularJNI10nSetIsLiveEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2f379c */ and w8, w3, #0xff;
    /* 0x2f37a0 */ cmp w8, #1;
    /* 0x2f37a4 */ cset w8, eq;
    /* 0x2f37a8 */ strb w8, [x2, #0xc9];
    return x0;
}
