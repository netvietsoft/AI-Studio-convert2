// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d87b4
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI9nGetLightEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d87b4 | Size: 188 bytes | SHA256: f69506b2db8649af9d34945f44e5880457b60b87751948b3f0ec337c474586d5
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetLight(J)Lcom/layer/flow/datas/LFEnhanceData$LightParam; (table at 0x536758)
// Calls external APIs: _Znwm
// Strings referenced:
//   "(JZ)V"
//   "<init>"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI9nGetLightEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x2d87b4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d87b8 */ stp x22, x21, [sp, #0x10];
    /* 0x2d87bc */ stp x20, x19, [sp, #0x20];
    /* 0x2d87c0 */ mov x29, sp;
    /* 0x2d87c4 */ ldr x8, [x0];
    /* 0x2d87c8 */ nop ;
    /* 0x2d87cc */ adr x1, #0x1e382d;
    /* 0x2d87d0 */ mov x19, x0;
    /* 0x2d87d4 */ mov x21, x2;
    /* 0x2d87d8 */ ldr x8, [x8, #0x30];
    /* 0x2d87dc */ blr x8;
    _Znwm();
    return x0;
}
