// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x448c78
// Recovered Name: _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI20downloadInfos_createEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x448c78 | Size: 64 bytes | SHA256: 178ff907d1aaf38884dbfbe68ce826e6dbb3943544615d5264b08e1a89e0342c
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x5462e0)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI20downloadInfos_createEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x448c78 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x448c7c */ stp x20, x19, [sp, #0x10];
    /* 0x448c80 */ mov x29, sp;
    /* 0x448c84 */ mov w0, #0x60;
    _Znwm();
    /* 0x448c8c */ mov x19, x0;
    _ZN11LayerFlowNS13DownloadInfosC2Ev();
    /* 0x448c94 */ mov x0, x19;
    /* 0x448c98 */ ldp x20, x19, [sp, #0x10];
    /* 0x448c9c */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_526544();
}
