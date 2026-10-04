// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3c1c38
// Recovered Name: _ZN11LayerFlowNS24LFFormulaRenderPluginJNI10enableDumpEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3c1c38 | Size: 188 bytes | SHA256: c323eaca2971be7cd8fc0aad7096f3ce57abeeb4c5d5b8aa5cdfa8b33ecb557d
// Callers: 0 | Callees: 2 | Imports: 1

// Dynamic Registration: nEnableDump(JZ)V (table at 0x540450)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv

jobject _ZN11LayerFlowNS24LFFormulaRenderPluginJNI10enableDumpEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x3c1c38 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x3c1c3c */ str x21, [sp, #0x10];
    /* 0x3c1c40 */ stp x20, x19, [sp, #0x20];
    /* 0x3c1c44 */ mov x29, sp;
    /* 0x3c1c48 */ ldr x21, [x2, #8];
    /* 0x3c1c4c */ cbz x21, #0x3c1c94;
    /* 0x3c1c50 */ ldr x19, [x2, #0x10];
    /* 0x3c1c54 */ mov w20, w3;
    /* 0x3c1c58 */ cbz x19, #0x3c1ca4;
    /* 0x3c1c5c */ add x1, x19, #8;
    /* 0x3c1c60 */ mov w0, #1;
    sub_5263b0();
    sub_5263e0();
    return x0;
    return x0;
}
