// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d8ce8
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI19nGetLightCorrectionEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d8ce8 | Size: 216 bytes | SHA256: 14643b0b7ed95835b13df74647d7082f734a37c75b99a2fba83413aa60259466
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nGetLightCorrection(J)Lcom/layer/flow/datas/LFEnhanceData$LightCorrectionParam; (table at 0x5367e8)
// Calls external APIs: _Znwm
// Strings referenced:
//   "(JZ)V"
//   "<init>"
//   "com/layer/flow/datas/LFEnhanceData$LightCorrectionParam"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI19nGetLightCorrectionEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 54 instructions
    /* 0x2d8ce8 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2d8cec */ str x23, [sp, #0x10];
    /* 0x2d8cf0 */ stp x22, x21, [sp, #0x20];
    /* 0x2d8cf4 */ stp x20, x19, [sp, #0x30];
    /* 0x2d8cf8 */ mov x29, sp;
    /* 0x2d8cfc */ ldr x8, [x0];
    /* 0x2d8d00 */ adrp x1, #0x1d5000;
    /* 0x2d8d04 */ add x1, x1, #0x52c;
    /* 0x2d8d08 */ mov x19, x0;
    /* 0x2d8d0c */ mov x21, x2;
    /* 0x2d8d10 */ ldr x8, [x8, #0x30];
    _Znwm();
    _ZNSt6__ndk16vectorI19LightCorrectionItemNS_9allocatorIS1_EEE18__assign_with_sizeB8ne180000IPS1_S6_EEvT_T0_l();
    return x0;
}
