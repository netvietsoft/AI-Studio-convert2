// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x44a0e4
// Recovered Name: _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI32preparedInfos_getToDownloadInfosEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x44a0e4 | Size: 224 bytes | SHA256: df68de93fa1b7289bb64f4b85c1447cb52a01e890b10348b5eed6abc2181ff20
// Callers: 0 | Callees: 6 | Imports: 2

// Dynamic Registration: nGetToDownloadInfos(J)J (table at 0x5463a0)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI32preparedInfos_getToDownloadInfosEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 56 instructions
    /* 0x44a0e4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x44a0e8 */ str x21, [sp, #0x10];
    /* 0x44a0ec */ stp x20, x19, [sp, #0x20];
    /* 0x44a0f0 */ mov x29, sp;
    /* 0x44a0f4 */ mov w0, #0x60;
    /* 0x44a0f8 */ mov x20, x2;
    _Znwm();
    /* 0x44a100 */ mov x19, x0;
    _ZN11LayerFlowNS13DownloadInfosC2Ev();
    /* 0x44a108 */ add x8, x20, #0x60;
    /* 0x44a10c */ cmp x19, x8;
    _ZNSt6__ndk16vectorIN11LayerFlowNS11CLFMaterialENS_9allocatorIS2_EEE18__assign_with_sizeB8ne180000IPS2_S7_EEvT_T0_l();
    _ZNSt6__ndk16vectorIN11LayerFlowNS11CLFFontInfoENS_9allocatorIS2_EEE18__assign_with_sizeB8ne180000IPS2_S7_EEvT_T0_l();
    _ZNSt6__ndk16vectorIN11LayerFlowNS14CLFAiModelInfoENS_9allocatorIS2_EEE18__assign_with_sizeB8ne180000IPS2_S7_EEvT_T0_l();
    _ZNSt6__ndk16vectorIN11LayerFlowNS11CLFFileInfoENS_9allocatorIS2_EEE18__assign_with_sizeB8ne180000IPS2_S7_EEvT_T0_l();
    return x0;
    _ZdlPv();
    sub_526544();
}
