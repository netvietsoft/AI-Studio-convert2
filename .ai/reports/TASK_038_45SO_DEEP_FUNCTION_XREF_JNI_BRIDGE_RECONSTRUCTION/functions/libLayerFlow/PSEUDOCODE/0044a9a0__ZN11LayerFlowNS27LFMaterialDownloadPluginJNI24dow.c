// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x44a9a0
// Recovered Name: _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI24downloadProgress_destroyEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x44a9a0 | Size: 16 bytes | SHA256: c403176df4f94c1e8be162561033fc745356b1123859b5f092ee8148719323ae
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x546448)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI24downloadProgress_destroyEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x44a9a0 */ cbz x2, #0x44a9ac;
    /* 0x44a9a4 */ mov x0, x2;
    /* 0x44a9a8 */ b #0x52a280;
    return x0;
}
