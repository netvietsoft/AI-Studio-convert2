// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c8dd4
// Recovered Name: _ZN11LayerFlowNS19LFEffectAkneDataJNI19nSetAutoRemoveSpotsEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c8dd4 | Size: 16 bytes | SHA256: 54bd566ad013a864df22fac442a84e7a8f111efe232d5fbd0772941ac408f6f8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetAutoRemoveSpots(JZ)V (table at 0x533278)

jobject _ZN11LayerFlowNS19LFEffectAkneDataJNI19nSetAutoRemoveSpotsEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2c8dd4 */ tst w3, #0xff;
    /* 0x2c8dd8 */ cset w8, ne;
    /* 0x2c8ddc */ strb w8, [x2, #6];
    return x0;
}
