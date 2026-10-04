// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d33b4
// Recovered Name: _ZN11LayerFlowNS23LFEffectSlimmingDataJNI13nSetBgProtectEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d33b4 | Size: 20 bytes | SHA256: 6b77cc85d79064c4633db79fc658dd5743d5e559de5e49aca2ddf012322899ae
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetBgProtect(JZ)V (table at 0x534f40)

jobject _ZN11LayerFlowNS23LFEffectSlimmingDataJNI13nSetBgProtectEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2d33b4 */ and w8, w3, #0xff;
    /* 0x2d33b8 */ cmp w8, #1;
    /* 0x2d33bc */ cset w8, eq;
    /* 0x2d33c0 */ strb w8, [x2, #0x20];
    return x0;
}
