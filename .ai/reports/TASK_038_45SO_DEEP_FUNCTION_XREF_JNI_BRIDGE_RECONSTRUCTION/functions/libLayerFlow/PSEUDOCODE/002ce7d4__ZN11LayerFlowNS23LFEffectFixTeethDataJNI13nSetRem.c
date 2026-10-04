// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ce7d4
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI13nSetRemoveVipEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ce7d4 | Size: 16 bytes | SHA256: 6eba8d86b65a8e3834fbbaff602454565d7dfdbd880f532fefcc029652751d90
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetRemoveVip(JZ)V (table at 0x534478)

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI13nSetRemoveVipEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2ce7d4 */ tst w3, #0xff;
    /* 0x2ce7d8 */ cset w8, ne;
    /* 0x2ce7dc */ strb w8, [x2, #0x18];
    return x0;
}
