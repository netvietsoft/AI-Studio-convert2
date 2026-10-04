// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d55b8
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI17nSetForeheadLevelEP7_JNIEnvP7_jclassld
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d55b8 | Size: 12 bytes | SHA256: 158b13e22050f15d2efc09624c5ac2820b1ec6373c51ed1f465e79298cccc630
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetForeheadLevel(JD)V (table at 0x5358e8)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI17nSetForeheadLevelEP7_JNIEnvP7_jclassld(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2d55b8 */ cbz x2, #0x2d55c0;
    /* 0x2d55bc */ str d0, [x2];
    return x0;
}
