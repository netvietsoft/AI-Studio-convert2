// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2bdfcc
// Recovered Name: _ZN11LayerFlowNS19LFAutoBeautyDataJNI21nCreateAutoBeautyModeEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2bdfcc | Size: 28 bytes | SHA256: 70492c4369c34fbb39c7c1943c7a7485701161b80187b94534b418423d08586a
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x531808)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS19LFAutoBeautyDataJNI21nCreateAutoBeautyModeEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x2bdfcc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2bdfd0 */ mov x29, sp;
    /* 0x2bdfd4 */ mov w0, #0x10;
    _Znwm();
    /* 0x2bdfdc */ stp xzr, xzr, [x0];
    /* 0x2bdfe0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
