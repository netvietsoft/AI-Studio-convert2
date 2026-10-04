// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d7d20
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI14nGetCurveColorEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d7d20 | Size: 320 bytes | SHA256: d547345bc2119e7ca797167128b2659a090556b7621fb539d8772ded372073b5
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nGetCurveColor(J)Lcom/layer/flow/datas/LFEnhanceData$CurveColorParam; (table at 0x536368)
// Calls external APIs: _Znwm
// Strings referenced:
//   "(JZ)V"
//   "<init>"
//   "com/layer/flow/datas/LFEnhanceData$CurveColorParam"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI14nGetCurveColorEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 80 instructions
    /* 0x2d7d20 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2d7d24 */ stp x24, x23, [sp, #0x10];
    /* 0x2d7d28 */ stp x22, x21, [sp, #0x20];
    /* 0x2d7d2c */ stp x20, x19, [sp, #0x30];
    /* 0x2d7d30 */ mov x29, sp;
    /* 0x2d7d34 */ ldr x8, [x0];
    /* 0x2d7d38 */ adrp x1, #0x1d5000;
    /* 0x2d7d3c */ add x1, x1, #0x495;
    /* 0x2d7d40 */ mov x19, x0;
    /* 0x2d7d44 */ mov x20, x2;
    /* 0x2d7d48 */ ldr x8, [x8, #0x30];
    _Znwm();
    sub_2dbb0c();
    sub_2dbb0c();
    sub_2dbb0c();
    sub_2dbb0c();
    return x0;
}
