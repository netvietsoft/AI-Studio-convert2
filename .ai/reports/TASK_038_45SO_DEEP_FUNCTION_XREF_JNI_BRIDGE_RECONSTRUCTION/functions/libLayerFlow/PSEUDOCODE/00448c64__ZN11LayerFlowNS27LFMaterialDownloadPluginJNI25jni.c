// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x448c64
// Recovered Name: _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI25jniOnFileDownloadProgressEP7_JNIEnvP8_jobjectlll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x448c64 | Size: 20 bytes | SHA256: 870fbe279a1a13607c172b47b80d8da85b060618d8707e78eec2a1f938ec0f10
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nOnFileDownloadProgress(JJJ)V (table at 0x5462c8)

jobject _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI25jniOnFileDownloadProgressEP7_JNIEnvP8_jobjectlll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x448c64 */ ldr x8, [x4];
    /* 0x448c68 */ mov x1, x3;
    /* 0x448c6c */ mov x0, x2;
    /* 0x448c70 */ mov x2, x8;
    /* 0x448c74 */ b #0x460c74;
}
