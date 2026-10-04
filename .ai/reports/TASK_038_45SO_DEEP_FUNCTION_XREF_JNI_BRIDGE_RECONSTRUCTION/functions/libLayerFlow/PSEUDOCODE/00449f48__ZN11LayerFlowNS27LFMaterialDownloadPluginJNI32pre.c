// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x449f48
// Recovered Name: _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI32preparedInfos_getLocalExistInfosEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x449f48 | Size: 220 bytes | SHA256: 488fbacb0bda53e58d6b6089ccf53912a5ab3cc4e7aba85522963dfa68a48bfe
// Callers: 0 | Callees: 6 | Imports: 2

// Dynamic Registration: nGetLocalExistInfos(J)J (table at 0x546370)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI32preparedInfos_getLocalExistInfosEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x449f48 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x449f4c */ str x21, [sp, #0x10];
    /* 0x449f50 */ stp x20, x19, [sp, #0x20];
    /* 0x449f54 */ mov x29, sp;
    /* 0x449f58 */ mov w0, #0x60;
    /* 0x449f5c */ mov x20, x2;
    _Znwm();
    /* 0x449f64 */ mov x19, x0;
    _ZN11LayerFlowNS13DownloadInfosC2Ev();
    /* 0x449f6c */ cmp x19, x20;
    /* 0x449f70 */ b.eq #0x449ffc;
    _ZNSt6__ndk16vectorIN11LayerFlowNS11CLFMaterialENS_9allocatorIS2_EEE18__assign_with_sizeB8ne180000IPS2_S7_EEvT_T0_l();
    _ZNSt6__ndk16vectorIN11LayerFlowNS11CLFFontInfoENS_9allocatorIS2_EEE18__assign_with_sizeB8ne180000IPS2_S7_EEvT_T0_l();
    _ZNSt6__ndk16vectorIN11LayerFlowNS14CLFAiModelInfoENS_9allocatorIS2_EEE18__assign_with_sizeB8ne180000IPS2_S7_EEvT_T0_l();
    _ZNSt6__ndk16vectorIN11LayerFlowNS11CLFFileInfoENS_9allocatorIS2_EEE18__assign_with_sizeB8ne180000IPS2_S7_EEvT_T0_l();
    return x0;
    _ZdlPv();
    sub_526544();
}
