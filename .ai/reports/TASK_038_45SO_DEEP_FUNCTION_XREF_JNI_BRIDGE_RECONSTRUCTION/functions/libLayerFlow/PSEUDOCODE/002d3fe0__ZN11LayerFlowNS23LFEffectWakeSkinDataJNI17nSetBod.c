// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d3fe0
// Recovered Name: _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI17nSetBodyConcealerEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d3fe0 | Size: 16 bytes | SHA256: c8db097673e8f698ad091c87f3714fac9b6e1d317f8580ff2ba959616fc72f8a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetBodyConcealer(JZ)V (table at 0x535558)

jobject _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI17nSetBodyConcealerEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2d3fe0 */ tst w3, #0xff;
    /* 0x2d3fe4 */ cset w8, ne;
    /* 0x2d3fe8 */ strb w8, [x2, #0x4c];
    return x0;
}
