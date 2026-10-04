// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d8dc0
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI19nSetLightCorrectionEP7_JNIEnvP8_jobjectlS4_
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d8dc0 | Size: 220 bytes | SHA256: dc8342ade6b454990268a7974b4958cd974cf682671791ecfe516477c02c804e
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nSetLightCorrection(JLcom/layer/flow/datas/LFEnhanceData$LightCorrectionParam;)V (table at 0x536800)
// Calls external APIs: _ZdlPv
// Strings referenced:
//   "com/layer/flow/datas/LFEnhanceData$LightCorrectionParam"
//   "nativeHandler"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI19nSetLightCorrectionEP7_JNIEnvP8_jobjectlS4_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x2d8dc0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d8dc4 */ str x21, [sp, #0x10];
    /* 0x2d8dc8 */ stp x20, x19, [sp, #0x20];
    /* 0x2d8dcc */ mov x29, sp;
    /* 0x2d8dd0 */ ldr x8, [x0];
    /* 0x2d8dd4 */ adrp x1, #0x1d5000;
    /* 0x2d8dd8 */ add x1, x1, #0x52c;
    /* 0x2d8ddc */ mov x20, x3;
    /* 0x2d8de0 */ mov x21, x0;
    /* 0x2d8de4 */ mov x19, x2;
    /* 0x2d8de8 */ ldr x8, [x8, #0x30];
    return x0;
    _ZdlPv();
    return x0;
}
