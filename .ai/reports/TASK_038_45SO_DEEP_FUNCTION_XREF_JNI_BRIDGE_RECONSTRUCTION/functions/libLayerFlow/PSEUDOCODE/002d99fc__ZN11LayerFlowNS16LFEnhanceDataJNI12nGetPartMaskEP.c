// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d99fc
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI12nGetPartMaskEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d99fc | Size: 204 bytes | SHA256: 0d2b84bad7fae93272fce2fea8e116a756ea094a61d9b2b74a3e6ee9a240f0c1
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nGetPartMask(J)Lcom/layer/flow/datas/LFEnhanceData$PartMask; (table at 0x536b30)
// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _Znwm
// Strings referenced:
//   "(J)V"
//   "<init>"
//   "com/layer/flow/datas/LFEnhanceData$PartMask"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI12nGetPartMaskEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x2d99fc */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2d9a00 */ str x23, [sp, #0x10];
    /* 0x2d9a04 */ stp x22, x21, [sp, #0x20];
    /* 0x2d9a08 */ stp x20, x19, [sp, #0x30];
    /* 0x2d9a0c */ mov x29, sp;
    /* 0x2d9a10 */ ldr x8, [x0];
    /* 0x2d9a14 */ adrp x1, #0x1d8000;
    /* 0x2d9a18 */ add x1, x1, #0xa1f;
    /* 0x2d9a1c */ mov x19, x0;
    /* 0x2d9a20 */ mov x21, x2;
    /* 0x2d9a24 */ ldr x8, [x8, #0x30];
    _Znwm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    return x0;
}
