// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f4870
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI11nAnimCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f4870 | Size: 32 bytes | SHA256: aca36bd81403e67b27b5f9c0c0bd066368af3d51680241c7f87d0c0450eb06c5
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x53b890)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFTextModularJNI11nAnimCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2f4870 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2f4874 */ mov x29, sp;
    /* 0x2f4878 */ mov w0, #0x20;
    _Znwm();
    /* 0x2f4880 */ movi v0.2d, #0000000000000000;
    /* 0x2f4884 */ stp q0, q0, [x0];
    /* 0x2f4888 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
