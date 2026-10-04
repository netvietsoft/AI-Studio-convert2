// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d3ff8
// Recovered Name: _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI17nSetFaceConcealerEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d3ff8 | Size: 16 bytes | SHA256: 41ce5a523156261b39efbd188a95945a376c179d262707fd43477ec7ff591a48
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetFaceConcealer(JZ)V (table at 0x535588)

jobject _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI17nSetFaceConcealerEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2d3ff8 */ tst w3, #0xff;
    /* 0x2d3ffc */ cset w8, ne;
    /* 0x2d4000 */ strb w8, [x2, #0x4d];
    return x0;
}
