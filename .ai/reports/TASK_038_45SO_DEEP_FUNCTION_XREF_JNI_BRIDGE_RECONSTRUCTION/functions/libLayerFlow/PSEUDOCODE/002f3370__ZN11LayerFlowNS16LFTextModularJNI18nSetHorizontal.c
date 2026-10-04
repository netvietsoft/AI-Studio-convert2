// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f3370
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI18nSetHorizontalFlipEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f3370 | Size: 16 bytes | SHA256: 97ffed2c94f19c5d7eb7aa84bf59d4ec4149980f170f8e780c2eec62328baaf2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetHorizontalFlip(JZ)V (table at 0x53b038)

jobject _ZN11LayerFlowNS16LFTextModularJNI18nSetHorizontalFlipEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f3370 */ tst w3, #0xff;
    /* 0x2f3374 */ cset w8, ne;
    /* 0x2f3378 */ strb w8, [x2, #0x3c];
    return x0;
}
