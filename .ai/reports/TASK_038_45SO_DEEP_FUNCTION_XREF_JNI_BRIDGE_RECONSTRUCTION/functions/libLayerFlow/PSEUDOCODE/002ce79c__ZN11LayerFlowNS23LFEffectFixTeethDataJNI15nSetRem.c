// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ce79c
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI15nSetRemoveDirtyEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ce79c | Size: 16 bytes | SHA256: 54bd566ad013a864df22fac442a84e7a8f111efe232d5fbd0772941ac408f6f8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetRemoveDirty(JZ)V (table at 0x5343e8)

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI15nSetRemoveDirtyEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2ce79c */ tst w3, #0xff;
    /* 0x2ce7a0 */ cset w8, ne;
    /* 0x2ce7a4 */ strb w8, [x2, #6];
    return x0;
}
