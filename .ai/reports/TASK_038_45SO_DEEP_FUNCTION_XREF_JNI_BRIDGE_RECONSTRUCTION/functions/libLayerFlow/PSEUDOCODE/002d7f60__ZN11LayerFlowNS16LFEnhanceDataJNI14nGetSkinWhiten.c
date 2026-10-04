// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d7f60
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI14nGetSkinWhitenEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d7f60 | Size: 176 bytes | SHA256: b95aab340573540c8a08815f711dcaef513201e7feb1a0e2a849cc417b4ab0ea
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetSkinWhiten(J)Lcom/layer/flow/datas/LFEnhanceData$SkinWhitenParam; (table at 0x536398)
// Calls external APIs: _Znwm
// Strings referenced:
//   "(JZ)V"
//   "<init>"
//   "com/layer/flow/datas/LFEnhanceData$SkinWhitenParam"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI14nGetSkinWhitenEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x2d7f60 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d7f64 */ stp x22, x21, [sp, #0x10];
    /* 0x2d7f68 */ stp x20, x19, [sp, #0x20];
    /* 0x2d7f6c */ mov x29, sp;
    /* 0x2d7f70 */ ldr x8, [x0];
    /* 0x2d7f74 */ adrp x1, #0x1e6000;
    /* 0x2d7f78 */ add x1, x1, #0xca8;
    /* 0x2d7f7c */ mov x19, x0;
    /* 0x2d7f80 */ mov x21, x2;
    /* 0x2d7f84 */ ldr x8, [x8, #0x30];
    /* 0x2d7f88 */ blr x8;
    _Znwm();
    return x0;
}
