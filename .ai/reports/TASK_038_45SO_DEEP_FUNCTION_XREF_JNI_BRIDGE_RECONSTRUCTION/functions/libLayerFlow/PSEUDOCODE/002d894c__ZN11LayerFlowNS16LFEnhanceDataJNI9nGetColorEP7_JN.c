// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d894c
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI9nGetColorEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d894c | Size: 232 bytes | SHA256: fae02be0a30e40ad6141753b43d7a7b7d40d6bca68f45e0018c54d602992a0e5
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nGetColor(J)Lcom/layer/flow/datas/LFEnhanceData$ColorParam; (table at 0x536788)
// Calls external APIs: _Znwm
// Strings referenced:
//   "(JZ)V"
//   "<init>"
//   "com/layer/flow/datas/LFEnhanceData$ColorParam"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI9nGetColorEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x2d894c */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2d8950 */ str x23, [sp, #0x10];
    /* 0x2d8954 */ stp x22, x21, [sp, #0x20];
    /* 0x2d8958 */ stp x20, x19, [sp, #0x30];
    /* 0x2d895c */ mov x29, sp;
    /* 0x2d8960 */ ldr x8, [x0];
    /* 0x2d8964 */ adrp x1, #0x1e5000;
    /* 0x2d8968 */ add x1, x1, #0xe43;
    /* 0x2d896c */ mov x19, x0;
    /* 0x2d8970 */ mov x20, x2;
    /* 0x2d8974 */ ldr x8, [x8, #0x30];
    _Znwm();
    _ZN10ColorParamaSERKS_();
    return x0;
}
