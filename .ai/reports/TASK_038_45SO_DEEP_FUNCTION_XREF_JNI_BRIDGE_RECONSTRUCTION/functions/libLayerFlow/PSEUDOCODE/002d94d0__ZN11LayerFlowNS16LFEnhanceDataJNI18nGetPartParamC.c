// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d94d0
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI18nGetPartParamColorEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d94d0 | Size: 232 bytes | SHA256: 348cd68bf29131db126fc4748be8ba212deb777dd4bd96f4b661de5faacad4da
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nGetPartParamColor(J)Lcom/layer/flow/datas/LFEnhanceData$ColorParam; (table at 0x536aa0)
// Calls external APIs: _Znwm
// Strings referenced:
//   "(JZ)V"
//   "<init>"
//   "com/layer/flow/datas/LFEnhanceData$ColorParam"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI18nGetPartParamColorEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x2d94d0 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2d94d4 */ str x23, [sp, #0x10];
    /* 0x2d94d8 */ stp x22, x21, [sp, #0x20];
    /* 0x2d94dc */ stp x20, x19, [sp, #0x30];
    /* 0x2d94e0 */ mov x29, sp;
    /* 0x2d94e4 */ ldr x8, [x0];
    /* 0x2d94e8 */ adrp x1, #0x1e5000;
    /* 0x2d94ec */ add x1, x1, #0xe43;
    /* 0x2d94f0 */ mov x19, x0;
    /* 0x2d94f4 */ mov x20, x2;
    /* 0x2d94f8 */ ldr x8, [x8, #0x30];
    _Znwm();
    _ZN10ColorParamaSERKS_();
    return x0;
}
