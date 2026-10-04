// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f0c64
// Recovered Name: _ZN11LayerFlowNS19LFStickerModularJNI11nDataCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f0c64 | Size: 32 bytes | SHA256: 9ad861369e477d6aa8e78b802c2dce756a3cbb3562832888d57488ceabb270c7
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x53a410)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS19LFStickerModularJNI11nDataCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2f0c64 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2f0c68 */ mov x29, sp;
    /* 0x2f0c6c */ mov w0, #0x18;
    _Znwm();
    /* 0x2f0c74 */ stp xzr, xzr, [x0, #8];
    /* 0x2f0c78 */ str xzr, [x0];
    /* 0x2f0c7c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
