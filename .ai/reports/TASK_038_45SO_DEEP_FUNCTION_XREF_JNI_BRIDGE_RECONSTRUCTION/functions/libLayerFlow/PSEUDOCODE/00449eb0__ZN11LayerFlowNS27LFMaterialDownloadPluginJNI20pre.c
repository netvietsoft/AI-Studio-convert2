// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x449eb0
// Recovered Name: _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI20preparedInfos_createEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x449eb0 | Size: 64 bytes | SHA256: 6b69b513723602b1170c34a9b8ef89d828f50d5fab0ba9270125b0aabe82d247
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x546340)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI20preparedInfos_createEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x449eb0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x449eb4 */ stp x20, x19, [sp, #0x10];
    /* 0x449eb8 */ mov x29, sp;
    /* 0x449ebc */ mov w0, #0xf0;
    _Znwm();
    /* 0x449ec4 */ mov x19, x0;
    _ZN11LayerFlowNS21PreparedDownloadInfosC2Ev();
    /* 0x449ecc */ mov x0, x19;
    /* 0x449ed0 */ ldp x20, x19, [sp, #0x10];
    /* 0x449ed4 */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_526544();
}
