// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5844
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI14nSetAutoParamsEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5844 | Size: 36 bytes | SHA256: 5d3d89ad5392b617ae1430286eb364475209bb1f858c23cee09fb23e3ff96e88
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetAutoParams(JJ)V (table at 0x535ac8)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI14nSetAutoParamsEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2d5844 */ cbz x2, #0x2d5864;
    /* 0x2d5848 */ cbz x3, #0x2d5864;
    /* 0x2d584c */ ldp q2, q0, [x3, #0x10];
    /* 0x2d5850 */ ldr x8, [x3, #0x30];
    /* 0x2d5854 */ ldr q1, [x3];
    /* 0x2d5858 */ str x8, [x2, #0x50];
    /* 0x2d585c */ stp q2, q0, [x2, #0x30];
    /* 0x2d5860 */ str q1, [x2, #0x20];
    return x0;
}
