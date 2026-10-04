// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f3598
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI14nSetTextPiecesEP7_JNIEnvP8_jobjectlP11_jlongArray
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f3598 | Size: 480 bytes | SHA256: 29fe12f90e8abaac7b897a605f9f31ad6715fa321e696a08f8e7d0fec4c6f7de
// Callers: 0 | Callees: 3 | Imports: 1

// Dynamic Registration: nSetTextPieces(J[J)V (table at 0x53b1e8)
// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_

jobject _ZN11LayerFlowNS16LFTextModularJNI14nSetTextPiecesEP7_JNIEnvP8_jobjectlP11_jlongArray(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 120 instructions
    /* 0x2f3598 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x2f359c */ str x27, [sp, #0x10];
    /* 0x2f35a0 */ stp x26, x25, [sp, #0x20];
    /* 0x2f35a4 */ stp x24, x23, [sp, #0x30];
    /* 0x2f35a8 */ stp x22, x21, [sp, #0x40];
    /* 0x2f35ac */ stp x20, x19, [sp, #0x50];
    /* 0x2f35b0 */ mov x29, sp;
    /* 0x2f35b4 */ ldr x8, [x0];
    /* 0x2f35b8 */ mov x1, x3;
    /* 0x2f35bc */ mov x19, x3;
    /* 0x2f35c0 */ mov x20, x0;
    sub_2f5bb0();
    _ZN11LFTextPieceD2Ev();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk123__optional_storage_baseINS_6vectorI17LFTextUnionConfigNS_9allocatorIS2_EEEELb0EE13__assign_fromB8ne180000IRKNS_27__optional_copy_assign_baseIS5_Lb0EEEEEvOT_();
}
