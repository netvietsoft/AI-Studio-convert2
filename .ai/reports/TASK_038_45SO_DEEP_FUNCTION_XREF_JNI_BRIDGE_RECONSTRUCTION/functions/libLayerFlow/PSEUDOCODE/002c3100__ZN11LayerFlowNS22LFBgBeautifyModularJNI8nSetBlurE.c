// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c3100
// Recovered Name: _ZN11LayerFlowNS22LFBgBeautifyModularJNI8nSetBlurEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c3100 | Size: 16 bytes | SHA256: 060081914e1c8f50843f978e1b4a6ea3be63c7c9191f6ee2eef63f44afae1387
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetBlur(JZ)V (table at 0x5324e0)

jobject _ZN11LayerFlowNS22LFBgBeautifyModularJNI8nSetBlurEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2c3100 */ tst w3, #0xff;
    /* 0x2c3104 */ cset w8, ne;
    /* 0x2c3108 */ strb w8, [x2, #0x70];
    return x0;
}
