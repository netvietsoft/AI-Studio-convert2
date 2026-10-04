// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d1c9c
// Recovered Name: _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI8nSetInfoEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d1c9c | Size: 156 bytes | SHA256: 3a7acbc205788d129689e6316ff3d149c088a43217797e1d978a3ee36c5d00cc
// Callers: 0 | Callees: 2 | Imports: 1

// Dynamic Registration: nSetInfo(JJ)V (table at 0x5349d0)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv

jobject _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI8nSetInfoEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 39 instructions
    /* 0x2d1c9c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d1ca0 */ stp x22, x21, [sp, #0x10];
    /* 0x2d1ca4 */ stp x20, x19, [sp, #0x20];
    /* 0x2d1ca8 */ mov x29, sp;
    /* 0x2d1cac */ ldr q0, [x3];
    /* 0x2d1cb0 */ mov x19, x2;
    /* 0x2d1cb4 */ stur q0, [x2, #0x28];
    /* 0x2d1cb8 */ ldp q3, q1, [x3, #0x20];
    /* 0x2d1cbc */ ldur q0, [x3, #0x3c];
    /* 0x2d1cc0 */ ldr q2, [x3, #0x10];
    /* 0x2d1cc4 */ stur q0, [x2, #0x64];
    sub_5263b0();
    sub_5263e0();
    return x0;
}
