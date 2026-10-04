// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d8e9c
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI12nGetCreativeEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d8e9c | Size: 220 bytes | SHA256: 6bee1498516e4e81449f4493f846ce66e361d33bf5cc3c69054df3ec1599463d
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nGetCreative(J)Lcom/layer/flow/datas/LFEnhanceData$CreativeParam; (table at 0x536818)
// Calls external APIs: _Znwm
// Strings referenced:
//   "(J)V"
//   "<init>"
//   "com/layer/flow/datas/LFEnhanceData$CreativeParam"

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI12nGetCreativeEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x2d8e9c */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2d8ea0 */ str x23, [sp, #0x10];
    /* 0x2d8ea4 */ stp x22, x21, [sp, #0x20];
    /* 0x2d8ea8 */ stp x20, x19, [sp, #0x30];
    /* 0x2d8eac */ mov x29, sp;
    /* 0x2d8eb0 */ ldr x8, [x0];
    /* 0x2d8eb4 */ adrp x1, #0x1dd000;
    /* 0x2d8eb8 */ add x1, x1, #0xf91;
    /* 0x2d8ebc */ mov x19, x0;
    /* 0x2d8ec0 */ mov x21, x2;
    /* 0x2d8ec4 */ ldr x8, [x8, #0x30];
    _Znwm();
    _ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEdEENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE14__assign_multiINS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEEEvT_SM_();
    return x0;
}
