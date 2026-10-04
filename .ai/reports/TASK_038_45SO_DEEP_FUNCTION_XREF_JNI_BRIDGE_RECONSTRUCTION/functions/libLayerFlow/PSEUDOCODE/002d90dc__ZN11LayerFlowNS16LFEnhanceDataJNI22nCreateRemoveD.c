// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d90dc
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI22nCreateRemoveDustParamEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d90dc | Size: 36 bytes | SHA256: c1c539c0f32b9aa6ec76151237beab47666c50efb7fee1479d7aa3323d3d82a3
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreateRemoveDustParam()J (table at 0x536848)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI22nCreateRemoveDustParamEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2d90dc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d90e0 */ mov x29, sp;
    /* 0x2d90e4 */ mov w0, #0x30;
    _Znwm();
    /* 0x2d90ec */ movi v0.2d, #0000000000000000;
    /* 0x2d90f0 */ stp q0, q0, [x0];
    /* 0x2d90f4 */ str q0, [x0, #0x20];
    /* 0x2d90f8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
