// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f26f8
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI18nCreateLFTextPieceEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f26f8 | Size: 148 bytes | SHA256: 0b77b4ee966ee040159232e79d566286ffe74757171f9bf19f9c59a76ed364be
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x53a768)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFTextModularJNI18nCreateLFTextPieceEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x2f26f8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2f26fc */ mov x29, sp;
    /* 0x2f2700 */ mov w0, #0x198;
    _Znwm();
    /* 0x2f2708 */ movi v0.2d, #0000000000000000;
    /* 0x2f270c */ mov w8, #1;
    /* 0x2f2710 */ str xzr, [x0, #0x190];
    /* 0x2f2714 */ strb wzr, [x0, #0x190];
    /* 0x2f2718 */ stp q0, q0, [x0];
    /* 0x2f271c */ strb w8, [x0, #0x1a];
    /* 0x2f2720 */ mov x8, #0x3ff0000000000000;
    return x0;
}
