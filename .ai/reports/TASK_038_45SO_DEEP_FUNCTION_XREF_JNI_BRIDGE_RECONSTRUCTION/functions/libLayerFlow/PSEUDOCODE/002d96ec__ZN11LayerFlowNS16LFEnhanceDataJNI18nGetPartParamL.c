// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d96ec
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI18nGetPartParamLightEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d96ec | Size: 188 bytes | SHA256: 2762cb4e8cecd8297368b53e6eef721f3140832c554bce1c1ef65632b6726c88
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetPartParamLight(J)Lcom/layer/flow/datas/LFEnhanceData$LightParam; (table at 0x536ad0)
// Calls external APIs: _Znwm
// Strings referenced:
//   "(JZ)V"
//   "<init>"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI18nGetPartParamLightEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x2d96ec */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d96f0 */ stp x22, x21, [sp, #0x10];
    /* 0x2d96f4 */ stp x20, x19, [sp, #0x20];
    /* 0x2d96f8 */ mov x29, sp;
    /* 0x2d96fc */ ldr x8, [x0];
    /* 0x2d9700 */ nop ;
    /* 0x2d9704 */ adr x1, #0x1e382d;
    /* 0x2d9708 */ mov x19, x0;
    /* 0x2d970c */ mov x21, x2;
    /* 0x2d9710 */ ldr x8, [x8, #0x30];
    /* 0x2d9714 */ blr x8;
    _Znwm();
    return x0;
}
