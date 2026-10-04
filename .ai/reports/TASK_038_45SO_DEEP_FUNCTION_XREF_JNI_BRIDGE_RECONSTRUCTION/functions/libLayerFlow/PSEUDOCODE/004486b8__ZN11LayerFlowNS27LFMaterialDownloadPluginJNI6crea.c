// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x4486b8
// Recovered Name: _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI6createEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x4486b8 | Size: 96 bytes | SHA256: 610b697fe114f18da9f1867028e7c6da7a65be77d296cca986db2bbbe1c2a77e
// Callers: 0 | Callees: 3 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x546238)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI6createEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 24 instructions
    /* 0x4486b8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x4486bc */ str x21, [sp, #0x10];
    /* 0x4486c0 */ stp x20, x19, [sp, #0x20];
    /* 0x4486c4 */ mov x29, sp;
    /* 0x4486c8 */ mov x21, x0;
    /* 0x4486cc */ mov w0, #0xe0;
    /* 0x4486d0 */ mov x19, x1;
    _Znwm();
    /* 0x4486d8 */ mov x20, x0;
    _ZN11LayerFlowNS27LFMaterialDownloadPluginJNIC2Ev();
    /* 0x4486e0 */ mov x0, x20;
    _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI10bindToJObjEP7_JNIEnvP8_jobject();
    return x0;
    _ZdlPv();
    sub_526544();
}
