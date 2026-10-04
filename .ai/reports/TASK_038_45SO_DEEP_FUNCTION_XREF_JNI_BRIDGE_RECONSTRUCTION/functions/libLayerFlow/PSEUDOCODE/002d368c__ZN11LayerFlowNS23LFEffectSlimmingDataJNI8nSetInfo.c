// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d368c
// Recovered Name: _ZN11LayerFlowNS23LFEffectSlimmingDataJNI8nSetInfoEP7_JNIEnvP7_jclasslP11_jlongArray
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d368c | Size: 320 bytes | SHA256: dc8ce024637c962a66e4d730528f36b04db0563fcaa658d0aa1bcb4ad8b96039
// Callers: 0 | Callees: 4 | Imports: 1

// Dynamic Registration: nSetInfo(J[J)V (table at 0x534f70)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS23LFEffectSlimmingDataJNI8nSetInfoEP7_JNIEnvP7_jclasslP11_jlongArray(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 80 instructions
    /* 0x2d368c */ stp x29, x30, [sp, #-0x50]!;
    /* 0x2d3690 */ stp x26, x25, [sp, #0x10];
    /* 0x2d3694 */ stp x24, x23, [sp, #0x20];
    /* 0x2d3698 */ stp x22, x21, [sp, #0x30];
    /* 0x2d369c */ stp x20, x19, [sp, #0x40];
    /* 0x2d36a0 */ mov x29, sp;
    /* 0x2d36a4 */ ldr x8, [x0];
    /* 0x2d36a8 */ mov x1, x3;
    /* 0x2d36ac */ mov x19, x3;
    /* 0x2d36b0 */ mov x20, x0;
    /* 0x2d36b4 */ mov x21, x2;
    sub_2d37cc();
    _ZdlPv();
    _ZdlPv();
    _ZNSt6__ndk16vectorI13SlimmingModelNS_9allocatorIS1_EEE21__push_back_slow_pathIRKS1_EEPS1_OT_();
    _ZNSt6__ndk19allocatorI13SlimmingModelE9constructB8ne180000IS1_JRKS1_EEEvPT_DpOT0_();
    sub_526544();
}
