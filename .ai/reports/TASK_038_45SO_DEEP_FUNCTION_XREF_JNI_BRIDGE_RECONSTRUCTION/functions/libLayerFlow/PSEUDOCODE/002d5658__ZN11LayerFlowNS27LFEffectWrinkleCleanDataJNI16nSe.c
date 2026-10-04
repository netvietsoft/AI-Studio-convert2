// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5658
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI16nSetUseAutoCleanEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5658 | Size: 20 bytes | SHA256: 5ec612f4937c9e9de384080dd31799eda371b41a997dc20e9476dec7e5520671
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetUseAutoClean(JZ)V (table at 0x5359d8)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI16nSetUseAutoCleanEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2d5658 */ cbz x2, #0x2d5668;
    /* 0x2d565c */ tst w3, #0xff;
    /* 0x2d5660 */ cset w8, ne;
    /* 0x2d5664 */ strb w8, [x2, #0x28];
    return x0;
}
