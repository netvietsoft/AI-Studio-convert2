// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d4010
// Recovered Name: _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI15nSetHairRemovalEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d4010 | Size: 16 bytes | SHA256: f6e0cded7ff1d16fd2e17b3a5e6082fa90cbf3e1333cd2ada2e2dae06dab0427
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetHairRemoval(JZ)V (table at 0x5355b8)

jobject _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI15nSetHairRemovalEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2d4010 */ tst w3, #0xff;
    /* 0x2d4014 */ cset w8, ne;
    /* 0x2d4018 */ strb w8, [x2, #0x4e];
    return x0;
}
