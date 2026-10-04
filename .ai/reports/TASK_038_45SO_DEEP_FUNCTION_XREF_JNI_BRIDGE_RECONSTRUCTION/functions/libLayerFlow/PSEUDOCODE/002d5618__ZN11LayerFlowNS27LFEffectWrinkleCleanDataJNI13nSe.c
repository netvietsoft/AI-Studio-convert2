// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5618
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI13nSetNasoLevelEP7_JNIEnvP7_jclassld
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5618 | Size: 12 bytes | SHA256: 732ddd9f939ec7b38bbd1c97b3e3223b46bea76b150e2f5485e28d4dc02c42bb
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetNasoLevel(JD)V (table at 0x535978)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI13nSetNasoLevelEP7_JNIEnvP7_jclassld(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2d5618 */ cbz x2, #0x2d5620;
    /* 0x2d561c */ str d0, [x2, #0x18];
    return x0;
}
