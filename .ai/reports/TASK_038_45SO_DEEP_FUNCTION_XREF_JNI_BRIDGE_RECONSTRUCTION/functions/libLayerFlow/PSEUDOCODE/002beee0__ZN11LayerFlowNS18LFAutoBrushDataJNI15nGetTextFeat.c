// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2beee0
// Recovered Name: _ZN11LayerFlowNS18LFAutoBrushDataJNI15nGetTextFeatureEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2beee0 | Size: 228 bytes | SHA256: 2141dab264e97c94d79bd59cfaa57553d9b69d33a7dd99e6e252ab785479de15
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nGetTextFeature(J)J (table at 0x531b20)
// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _Znwm

jobject _ZN11LayerFlowNS18LFAutoBrushDataJNI15nGetTextFeatureEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 57 instructions
    /* 0x2beee0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2beee4 */ stp x22, x21, [sp, #0x10];
    /* 0x2beee8 */ stp x20, x19, [sp, #0x20];
    /* 0x2beeec */ mov x29, sp;
    /* 0x2beef0 */ mov w0, #0xd0;
    /* 0x2beef4 */ mov x19, x2;
    _Znwm();
    /* 0x2beefc */ movi v0.2d, #0000000000000000;
    /* 0x2bef00 */ mov x21, x0;
    /* 0x2bef04 */ mov x22, x19;
    /* 0x2bef08 */ mov x8, #-0x4010000000000000;
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk16vectorI11LFTextPieceNS_9allocatorIS1_EEE18__assign_with_sizeB8ne180000IPS1_S6_EEvT_T0_l();
    return x0;
}
