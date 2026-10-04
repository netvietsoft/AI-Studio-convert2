// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3200fc
// Recovered Name: sub_3200fc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3200fc | Size: 400 bytes | SHA256: ec7dd798a5a84c22ec412d96f80370e81beaa30e4025824facb789dba9e76db7
// Callers: 0 | Callees: 9 | Imports: 5

// Dynamic Registration: nGetEnhanceModularFrom(J)J (table at 0x53c470)
// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _ZdlPv, _Znwm, __stack_chk_fail, memset

jlong sub_3200fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 100 instructions
    /* 0x3200fc */ stp x29, x30, [sp, #-0x40]!;
    /* 0x320100 */ str x28, [sp, #0x10];
    /* 0x320104 */ stp x22, x21, [sp, #0x20];
    /* 0x320108 */ stp x20, x19, [sp, #0x30];
    /* 0x32010c */ mov x29, sp;
    /* 0x320110 */ sub sp, sp, #0x230;
    /* 0x320114 */ mrs x20, tpidr_el0;
    /* 0x320118 */ ldr x8, [x20, #0x28];
    /* 0x32011c */ stur x8, [x29, #-8];
    /* 0x320120 */ ldr x8, [x2];
    /* 0x320124 */ ldr w9, [x8, #0x258];
    _ZN16LFEnhanceModularC2ERKS_();
    _Znwm();
    memset();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZN10ColorParamaSERKS_();
    _ZNSt6__ndk16vectorI19LightCorrectionItemNS_9allocatorIS1_EEE18__assign_with_sizeB8ne180000IPS1_S6_EEvT_T0_l();
    _ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEdEENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE14__assign_multiINS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEEEvT_SM_();
    sub_2c7688();
    _ZdlPv();
    _ZN10ColorParamD2Ev();
    _ZdlPv();
    return x0;
    sub_303354();
    _ZN16LFEnhanceModularD2Ev();
    sub_526544();
    __stack_chk_fail();
}
