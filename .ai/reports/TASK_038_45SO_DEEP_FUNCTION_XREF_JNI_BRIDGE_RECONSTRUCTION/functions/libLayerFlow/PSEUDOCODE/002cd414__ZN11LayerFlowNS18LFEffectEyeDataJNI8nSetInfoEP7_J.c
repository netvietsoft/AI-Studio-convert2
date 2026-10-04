// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cd414
// Recovered Name: _ZN11LayerFlowNS18LFEffectEyeDataJNI8nSetInfoEP7_JNIEnvP7_jclasslP11_jlongArray
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cd414 | Size: 328 bytes | SHA256: 39e0fb31027b4861bf2007b3c95abe96024eda3f9c9b669cb7b4bb90d5aa8ee8
// Callers: 0 | Callees: 4 | Imports: 1

// Dynamic Registration: nSetInfo(J[J)V (table at 0x533f30)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS18LFEffectEyeDataJNI8nSetInfoEP7_JNIEnvP7_jclasslP11_jlongArray(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 82 instructions
    /* 0x2cd414 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x2cd418 */ stp x26, x25, [sp, #0x10];
    /* 0x2cd41c */ stp x24, x23, [sp, #0x20];
    /* 0x2cd420 */ stp x22, x21, [sp, #0x30];
    /* 0x2cd424 */ stp x20, x19, [sp, #0x40];
    /* 0x2cd428 */ mov x29, sp;
    /* 0x2cd42c */ ldr x8, [x0];
    /* 0x2cd430 */ mov x1, x3;
    /* 0x2cd434 */ mov x19, x3;
    /* 0x2cd438 */ mov x20, x0;
    /* 0x2cd43c */ mov x21, x2;
    sub_2cd55c();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZNSt6__ndk16vectorI8EyeModelNS_9allocatorIS1_EEE21__push_back_slow_pathIRKS1_EEPS1_OT_();
    _ZN8EyeModelC2ERKS_();
    sub_526544();
}
