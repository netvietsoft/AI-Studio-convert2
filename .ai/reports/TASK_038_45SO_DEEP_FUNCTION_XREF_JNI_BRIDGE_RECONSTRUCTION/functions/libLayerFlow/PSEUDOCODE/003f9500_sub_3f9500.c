// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3f9500
// Recovered Name: sub_3f9500
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3f9500 | Size: 2364 bytes | SHA256: 644dd850ebccf9c9e8170030fb0218fd0fba15b22c4d4cd1edfb8cacc3a1cdd5
// Callers: 0 | Callees: 11 | Imports: 21

// Calls external APIs: _ZN12MTImageKitNS11CMTIKFilter12setNetHeaderENSt6__ndk110shared_ptrINS_14CMTIKNetHeaderEEE, _ZN12MTImageKitNS12CMTIKManager23setDoubleBufferReRenderEb, _ZN12MTImageKitNS12CMTIKManager9addFilterEPNS_11CMTIKFilterElb, _ZN12MTImageKitNS14CMTIKNetHeader7isVaildEv, _ZN12MTImageKitNS15CMTIKHairFilter12initFaceDataEv, _ZN12MTImageKitNS15CMTIKHairFilterC1Ev, _ZN12MTImageKitNS19CMTIKHairVolumeInfo11setHairLineEf, _ZN12MTImageKitNS19CMTIKHairVolumeInfo12setCalvariumEf, _ZN12MTImageKitNS19CMTIKHairVolumeInfo13setFluffyHairEi, _ZN12MTImageKitNS19CMTIKHairVolumeInfo16setFluffyHairProEi, _ZN12MTImageKitNS19CMTIKHairVolumeInfo16setRepairingHairEf, _ZN12MTImageKitNS19CMTIKHairVolumeInfo20setCustomEffectParamEmf, _ZN12MTImageKitNS19CMTIKHairVolumeInfo24setFluffyHairMaterialDirENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE, _ZN12MTImageKitNS19CMTIKHairVolumeInfo24setRepairHairMaterialDirENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE, _ZN12MTImageKitNS22CMTIKHairVolumeManager24registerHairVolumeEffectERKNS_21CMTIKHairCustomEffectE, _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, _Znwm, __dynamic_cast
// Strings referenced:
//   "CLFDenseHairProcessor<%s:%d> fluffy hair pro material path is empty, materialId=%lld"
//   "CLFDenseHairProcessor<%s:%d> layer is nullptr, return false."
//   "CLFDenseHairProcessor<%s:%d> mtikManager is nullptr, return false."
//   "applyLayer"
//   "formulaRenderPlugin"

void sub_3f9500(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 591 instructions
    /* 0x3f9500 */ stp x29, x30, [sp, #0x10];
    /* 0x3f9504 */ stp x28, x27, [sp, #0x20];
    /* 0x3f9508 */ stp x26, x25, [sp, #0x30];
    /* 0x3f950c */ stp x24, x23, [sp, #0x40];
    /* 0x3f9510 */ stp x22, x21, [sp, #0x50];
    /* 0x3f9514 */ stp x20, x19, [sp, #0x60];
    /* 0x3f9518 */ add x29, sp, #0x10;
    /* 0x3f951c */ sub sp, sp, #0x4d0;
    /* 0x3f9520 */ mrs x24, tpidr_el0;
    /* 0x3f9524 */ mov x25, x0;
    /* 0x3f9528 */ ldr x8, [x24, #0x28];
    __dynamic_cast();
    sub_5263b0();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN11LayerFlowNS17CLFDenseHairLayer10getModularEv();
    _ZN11LayerFlowNS16CLFBaseProcessor16getFilterFromMgrEl();
    __dynamic_cast();
    _Znwm();
    _ZN12MTImageKitNS15CMTIKHairFilterC1Ev();
    _ZN12MTImageKitNS12CMTIKManager9addFilterEPNS_11CMTIKFilterElb();
    _ZN12MTImageKitNS15CMTIKHairFilter12initFaceDataEv();
    _ZNK11LayerFlowNS14CLFFormulaShop10findPluginENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE();
    __dynamic_cast();
    sub_5263b0();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZdlPv();
    _ZNK11LayerFlowNS22CLFFormulaRenderPlugin12getFreeTokenEv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    sub_2bc260();
    _ZdlPv();
    _Znwm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE14__assign_multiINS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEEEvT_SM_();
    _ZN12MTImageKitNS14CMTIKNetHeader7isVaildEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    sub_5263b0();
    _ZN12MTImageKitNS11CMTIKFilter12setNetHeaderENSt6__ndk110shared_ptrINS_14CMTIKNetHeaderEEE();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZN11LayerFlowNS12CLFNetHeaderD2Ev();
    _ZdlPv();
    _ZNSt6__ndk16__treeINS_12__value_typeIiN12MTImageKitNS19CMTIKHairVolumeInfoEEENS_19__map_value_compareIiS4_NS_4lessIiEELb1EEENS_9allocatorIS4_EEE25__emplace_unique_key_argsIiJRKNS_21piecewise_construct_tENS_5tupleIJRKiEEENSG_IJEEEEEENS_4pairINS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEERKT_DpOT0_();
    _ZN12MTImageKitNS19CMTIKHairVolumeInfo16setRepairingHairEf();
    _ZN11LayerFlowNS17CLFDenseHairLayer17getMaterialPathByEl();
    _ZNSt6__ndk16__treeINS_12__value_typeIiN12MTImageKitNS19CMTIKHairVolumeInfoEEENS_19__map_value_compareIiS4_NS_4lessIiEELb1EEENS_9allocatorIS4_EEE25__emplace_unique_key_argsIiJRKNS_21piecewise_construct_tENS_5tupleIJRKiEEENSG_IJEEEEEENS_4pairINS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEERKT_DpOT0_();
    _ZN12MTImageKitNS19CMTIKHairVolumeInfo20setCustomEffectParamEmf();
    _ZN11LayerFlowNS17CLFDenseHairLayer17getMaterialPathByEl();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZN12MTImageKitNS22CMTIKHairVolumeManager24registerHairVolumeEffectERKNS_21CMTIKHairCustomEffectE();
    _ZdlPv();
    _ZNSt6__ndk16__treeINS_12__value_typeIiN12MTImageKitNS19CMTIKHairVolumeInfoEEENS_19__map_value_compareIiS4_NS_4lessIiEELb1EEENS_9allocatorIS4_EEE25__emplace_unique_key_argsIiJRKNS_21piecewise_construct_tENS_5tupleIJRKiEEENSG_IJEEEEEENS_4pairINS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEERKT_DpOT0_();
    _ZN12MTImageKitNS19CMTIKHairVolumeInfo11setHairLineEf();
    _ZNSt6__ndk16__treeINS_12__value_typeIiN12MTImageKitNS19CMTIKHairVolumeInfoEEENS_19__map_value_compareIiS4_NS_4lessIiEELb1EEENS_9allocatorIS4_EEE25__emplace_unique_key_argsIiJRKNS_21piecewise_construct_tENS_5tupleIJRKiEEENSG_IJEEEEEENS_4pairINS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEERKT_DpOT0_();
    _ZN12MTImageKitNS19CMTIKHairVolumeInfo13setFluffyHairEi();
    _ZNSt6__ndk16__treeINS_12__value_typeIiN12MTImageKitNS19CMTIKHairVolumeInfoEEENS_19__map_value_compareIiS4_NS_4lessIiEELb1EEENS_9allocatorIS4_EEE25__emplace_unique_key_argsIiJRKNS_21piecewise_construct_tENS_5tupleIJRKiEEENSG_IJEEEEEENS_4pairINS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEERKT_DpOT0_();
    _ZN12MTImageKitNS19CMTIKHairVolumeInfo12setCalvariumEf();
    _ZNSt6__ndk16__treeINS_12__value_typeIiN12MTImageKitNS19CMTIKHairVolumeInfoEEENS_19__map_value_compareIiS4_NS_4lessIiEELb1EEENS_9allocatorIS4_EEE25__emplace_unique_key_argsIiJRKNS_21piecewise_construct_tENS_5tupleIJRKiEEENSG_IJEEEEEENS_4pairINS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEERKT_DpOT0_();
    _ZN12MTImageKitNS19CMTIKHairVolumeInfo16setFluffyHairProEi();
    _ZN11LayerFlowNS17CLFDenseHairLayer17getMaterialPathByEl();
    _ZdlPv();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    sub_2bc260();
    _ZN12MTImageKitNS19CMTIKHairVolumeInfo24setRepairHairMaterialDirENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE();
    sub_2bc260();
    _ZN12MTImageKitNS19CMTIKHairVolumeInfo24setFluffyHairMaterialDirENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE();
    _ZdlPv();
    _ZdlPv();
    _ZN12MTImageKitNS12CMTIKManager23setDoubleBufferReRenderEb();
}
