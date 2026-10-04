// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x448c28
// Recovered Name: _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI29jniOnMaterialDownloadProgressEP7_JNIEnvP8_jobjectlll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x448c28 | Size: 20 bytes | SHA256: eb5ac70388a2f65878e516ebbf4b37f167e0a53181d1216543144e94d489c533
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nOnMaterialDownloadProgress(JJJ)V (table at 0x546280)

jobject _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI29jniOnMaterialDownloadProgressEP7_JNIEnvP8_jobjectlll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x448c28 */ ldr x8, [x4];
    /* 0x448c2c */ mov x1, x3;
    /* 0x448c30 */ mov x0, x2;
    /* 0x448c34 */ mov x2, x8;
    /* 0x448c38 */ b #0x46092c;
}
