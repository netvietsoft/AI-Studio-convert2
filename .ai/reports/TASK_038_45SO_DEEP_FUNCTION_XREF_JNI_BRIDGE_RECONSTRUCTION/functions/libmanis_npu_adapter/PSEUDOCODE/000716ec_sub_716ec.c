// Library: libmanis_npu_adapter.so
// Function ID: libmanis_npu_adapter::0x716ec
// Recovered Name: sub_716ec
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x716ec | Size: 1856 bytes | SHA256: eefa1d13618ee622bfccf40a0cd8c93e5942b0fdef3fd23e8c61ad9f9f54bc3b
// Callers: 0 | Callees: 8 | Imports: 16

// Calls external APIs: _ZN2ge8Operator8SetInputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKS0_, _ZN4hiai2op10ArgMaxExt218set_attr_keep_dimsEb, _ZN4hiai2op10ArgMaxExt2C2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE, _ZN4hiai2op5CastT18set_attr_dst_dtypeEl, _ZN4hiai2op5CastT18set_attr_src_dtypeEl, _ZN4hiai2op5ConstC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE, _ZN5mizar6StatusC1Ev, _ZN5mizar8NpuUtils12SetAttrValueIiEEvRNSt6__ndk110shared_ptrIN4hiai2op5ConstEEENS2_6vectorIT_NS2_9allocatorISA_EEEEN2ge6FormatENSE_8DataTypeEb, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZNSt6__ndk119__shared_weak_countD2Ev, _ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op5CastTENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_, _ZNSt6__ndk16vectorINS_10shared_ptrIN2ge8OperatorEEENS_9allocatorIS4_EEE21__push_back_slow_pathIS4_EEPS4_OT_, _ZdlPv, _Znwm, __stack_chk_fail, memmove

void sub_716ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 464 instructions
    /* 0x716ec */ stp x29, x30, [sp, #0x80];
    /* 0x716f0 */ stp x28, x27, [sp, #0x90];
    /* 0x716f4 */ stp x26, x25, [sp, #0xa0];
    /* 0x716f8 */ stp x24, x23, [sp, #0xb0];
    /* 0x716fc */ stp x22, x21, [sp, #0xc0];
    /* 0x71700 */ stp x20, x19, [sp, #0xd0];
    /* 0x71704 */ add x29, sp, #0x80;
    /* 0x71708 */ str x8, [sp];
    /* 0x7170c */ mrs x8, tpidr_el0;
    /* 0x71710 */ mov x21, x0;
    /* 0x71714 */ str x8, [sp, #8];
    _Znwm();
    _Znwm();
    memmove();
    _Znwm();
    _ZN4hiai2op5ConstC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE();
    _ZdlPv();
    _Znwm();
    _ZN5mizar8NpuUtils12SetAttrValueIiEEvRNSt6__ndk110shared_ptrIN4hiai2op5ConstEEENS2_6vectorIT_NS2_9allocatorISA_EEEEN2ge6FormatENSE_8DataTypeEb();
    _ZdlPv();
    sub_eac10();
    _ZNSt6__ndk16vectorINS_10shared_ptrIN2ge8OperatorEEENS_9allocatorIS4_EEE21__push_back_slow_pathIS4_EEPS4_OT_();
    sub_eb300();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _Znwm();
    memmove();
    _Znwm();
    _ZN4hiai2op10ArgMaxExt2C2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE();
    _ZdlPv();
    _ZN2ge8Operator8SetInputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKS0_();
    _ZdlPv();
    _ZN2ge8Operator8SetInputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKS0_();
    _ZdlPv();
    _ZN4hiai2op10ArgMaxExt218set_attr_keep_dimsEb();
    sub_eac10();
    _ZNSt6__ndk16vectorINS_10shared_ptrIN2ge8OperatorEEENS_9allocatorIS4_EEE21__push_back_slow_pathIS4_EEPS4_OT_();
    sub_eb300();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _Znwm();
    _ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op5CastTENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_();
    _ZN2ge8Operator8SetInputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKS0_();
    _ZdlPv();
    _ZN4hiai2op5CastT18set_attr_src_dtypeEl();
    _ZN4hiai2op5CastT18set_attr_dst_dtypeEl();
    sub_eac10();
    _ZNSt6__ndk16vectorINS_10shared_ptrIN2ge8OperatorEEENS_9allocatorIS4_EEE21__push_back_slow_pathIS4_EEPS4_OT_();
    sub_eb300();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZN5mizar6StatusC1Ev();
    sub_eb300();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_eb300();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_eb300();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZdlPv();
    return x0;
    sub_72540();
    sub_72540();
    sub_71f8c();
    sub_71f8c();
    sub_71f8c();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZNSt6__ndk119__shared_weak_countD2Ev();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZNSt6__ndk119__shared_weak_countD2Ev();
    _ZdlPv();
    _ZdlPv();
    sub_7224c();
    sub_7229c();
    sub_722ec();
    _ZdlPv();
    sub_eb464();
    __stack_chk_fail();
}
