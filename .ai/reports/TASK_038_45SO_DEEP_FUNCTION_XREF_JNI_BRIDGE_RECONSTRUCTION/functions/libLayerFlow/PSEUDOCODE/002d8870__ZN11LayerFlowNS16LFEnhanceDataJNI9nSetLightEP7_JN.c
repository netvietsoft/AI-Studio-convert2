// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d8870
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI9nSetLightEP7_JNIEnvP8_jobjectlS4_
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d8870 | Size: 220 bytes | SHA256: ccd22418ae6ef1f2051f64fc135506f1bee20b58535dde733a43093a863d406b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetLight(JLcom/layer/flow/datas/LFEnhanceData$LightParam;)V (table at 0x536770)
// Strings referenced:
//   "nativeHandler"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI9nSetLightEP7_JNIEnvP8_jobjectlS4_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x2d8870 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d8874 */ str x21, [sp, #0x10];
    /* 0x2d8878 */ stp x20, x19, [sp, #0x20];
    /* 0x2d887c */ mov x29, sp;
    /* 0x2d8880 */ ldr x8, [x0];
    /* 0x2d8884 */ nop ;
    /* 0x2d8888 */ adr x1, #0x1e382d;
    /* 0x2d888c */ mov x20, x3;
    /* 0x2d8890 */ mov x21, x0;
    /* 0x2d8894 */ mov x19, x2;
    /* 0x2d8898 */ ldr x8, [x8, #0x30];
    return x0;
    return x0;
    return x0;
}
