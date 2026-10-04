// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x37e810
// Recovered Name: sub_37e810
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x37e810 | Size: 364 bytes | SHA256: 708981248cbad613b34d464022b5bd6dfc227e2e547eb241b3c831ae586db76f
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "hairCleanAlpha"
//   "optType"
//   "skinCleanAlpha"

void sub_37e810(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 91 instructions
    /* 0x37e810 */ stp x29, x30, [sp, #0x20];
    /* 0x37e814 */ stp x28, x27, [sp, #0x30];
    /* 0x37e818 */ stp x26, x25, [sp, #0x40];
    /* 0x37e81c */ stp x24, x23, [sp, #0x50];
    /* 0x37e820 */ stp x22, x21, [sp, #0x60];
    /* 0x37e824 */ stp x20, x19, [sp, #0x70];
    /* 0x37e828 */ add x29, sp, #0x20;
    /* 0x37e82c */ mrs x27, tpidr_el0;
    /* 0x37e830 */ mov x25, x3;
    /* 0x37e834 */ mov x19, x2;
    /* 0x37e838 */ ldr x8, [x27, #0x28];
    _ZNK8nlohmann16json_abi_v3_12_06detail9iter_implIKNS0_10basic_jsonINSt6__ndk13mapENS4_6vectorENS4_12basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEblmdSA_NS0_14adl_serializerENS6_IhNSA_IhEEEEvEEEeqISI_TnNS4_9enable_ifIXoosr3std7is_sameIT_SI_EE5valuesr3std7is_sameISL_NS2_ISG_EEEE5valueEDnE4typeELDn0EEEbRKSL_();
    return x0;
    _ZNK8nlohmann16json_abi_v3_12_06detail9iter_implIKNS0_10basic_jsonINSt6__ndk13mapENS4_6vectorENS4_12basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEblmdSA_NS0_14adl_serializerENS6_IhNSA_IhEEEEvEEEeqISI_TnNS4_9enable_ifIXoosr3std7is_sameIT_SI_EE5valuesr3std7is_sameISL_NS2_ISG_EEEE5valueEDnE4typeELDn0EEEbRKSL_();
    _ZNK8nlohmann16json_abi_v3_12_06detail9iter_implIKNS0_10basic_jsonINSt6__ndk13mapENS4_6vectorENS4_12basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEblmdSA_NS0_14adl_serializerENS6_IhNSA_IhEEEEvEEEdeEv();
    _ZN8nlohmann18extended_from_jsonIdEEvRKNS_16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS3_6vectorENS3_12basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEblmdS9_NS1_14adl_serializerENS5_IhNS9_IhEEEEvEEPKcRT_();
    _ZN8nlohmann18extended_from_jsonIdEEvRKNS_16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS3_6vectorENS3_12basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEblmdS9_NS1_14adl_serializerENS5_IhNS9_IhEEEEvEEPKcRT_();
    _ZN8nlohmann18extended_from_jsonIiEEvRKNS_16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS3_6vectorENS3_12basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEblmdS9_NS1_14adl_serializerENS5_IhNS9_IhEEEEvEEPKcRT_();
    sub_37e97c();
    __stack_chk_fail();
}
