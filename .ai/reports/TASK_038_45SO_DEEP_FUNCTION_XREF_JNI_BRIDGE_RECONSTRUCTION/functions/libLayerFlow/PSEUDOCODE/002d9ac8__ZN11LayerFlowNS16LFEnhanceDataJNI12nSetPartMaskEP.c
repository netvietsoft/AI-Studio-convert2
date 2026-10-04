// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d9ac8
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI12nSetPartMaskEP7_JNIEnvP8_jobjectlS4_
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d9ac8 | Size: 220 bytes | SHA256: e5d5d9672695152be0221ec14156147eae07d05dbdeaf6b66b51b0072bdcb26e
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nSetPartMask(JLcom/layer/flow/datas/LFEnhanceData$PartMask;)V (table at 0x536b48)
// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _ZdlPv
// Strings referenced:
//   "com/layer/flow/datas/LFEnhanceData$PartMask"
//   "nativeHandler"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI12nSetPartMaskEP7_JNIEnvP8_jobjectlS4_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x2d9ac8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d9acc */ str x21, [sp, #0x10];
    /* 0x2d9ad0 */ stp x20, x19, [sp, #0x20];
    /* 0x2d9ad4 */ mov x29, sp;
    /* 0x2d9ad8 */ ldr x8, [x0];
    /* 0x2d9adc */ adrp x1, #0x1d8000;
    /* 0x2d9ae0 */ add x1, x1, #0xa1f;
    /* 0x2d9ae4 */ mov x20, x3;
    /* 0x2d9ae8 */ mov x21, x0;
    /* 0x2d9aec */ mov x19, x2;
    /* 0x2d9af0 */ ldr x8, [x8, #0x30];
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    return x0;
    return x0;
    _ZdlPv();
    return x0;
}
