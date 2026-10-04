// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c9960
// Recovered Name: _ZN11LayerFlowNS25LFEffectAutoMosaicDataJNI9nSetModesEP7_JNIEnvP7_jclasslP11_jlongArray
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c9960 | Size: 352 bytes | SHA256: e00db11c87e7bcbf92253d826e8425ec4cab3f573a53d19d891df5b18d1b52ab
// Callers: 0 | Callees: 4 | Imports: 1

// Dynamic Registration: nSetModes(J[J)V (table at 0x5334d0)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS25LFEffectAutoMosaicDataJNI9nSetModesEP7_JNIEnvP7_jclasslP11_jlongArray(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 88 instructions
    /* 0x2c9960 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x2c9964 */ stp x26, x25, [sp, #0x10];
    /* 0x2c9968 */ stp x24, x23, [sp, #0x20];
    /* 0x2c996c */ stp x22, x21, [sp, #0x30];
    /* 0x2c9970 */ stp x20, x19, [sp, #0x40];
    /* 0x2c9974 */ mov x29, sp;
    /* 0x2c9978 */ ldr x8, [x0];
    /* 0x2c997c */ mov x1, x3;
    /* 0x2c9980 */ mov x19, x3;
    /* 0x2c9984 */ mov x20, x0;
    /* 0x2c9988 */ mov x21, x2;
    sub_2c9ac0();
    _ZdlPv();
    _ZNSt6__ndk16vectorI14AutoMosaicModeNS_9allocatorIS1_EEE21__push_back_slow_pathIRKS1_EEPS1_OT_();
    sub_2bc260();
    sub_526544();
}
