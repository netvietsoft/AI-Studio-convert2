// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cf878
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI8nSetInfoEP7_JNIEnvP7_jclasslP11_jlongArray
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cf878 | Size: 328 bytes | SHA256: 5ab448e93c9d427788a5c893ac1f7a1db132f12aa77918fa2ede465c27e1a004
// Callers: 0 | Callees: 4 | Imports: 1

// Dynamic Registration: nSetInfo(J[J)V (table at 0x534640)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI8nSetInfoEP7_JNIEnvP7_jclasslP11_jlongArray(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 82 instructions
    /* 0x2cf878 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x2cf87c */ stp x26, x25, [sp, #0x10];
    /* 0x2cf880 */ stp x24, x23, [sp, #0x20];
    /* 0x2cf884 */ stp x22, x21, [sp, #0x30];
    /* 0x2cf888 */ stp x20, x19, [sp, #0x40];
    /* 0x2cf88c */ mov x29, sp;
    /* 0x2cf890 */ ldr x8, [x0];
    /* 0x2cf894 */ mov x1, x3;
    /* 0x2cf898 */ mov x19, x3;
    /* 0x2cf89c */ mov x20, x0;
    /* 0x2cf8a0 */ mov x21, x2;
    sub_2cf9c0();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZNSt6__ndk16vectorI13FixTeethModelNS_9allocatorIS1_EEE21__push_back_slow_pathIRKS1_EEPS1_OT_();
    _ZN13FixTeethModelC2ERKS_();
    sub_526544();
}
