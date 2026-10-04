// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2eec8c
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI17nCreateBeautyGlowEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2eec8c | Size: 32 bytes | SHA256: 810dde05143d2d6865c8a5824fc08d4ef0623abb6945bdd013ee9c3869e33886
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x539c30)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI17nCreateBeautyGlowEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2eec8c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2eec90 */ mov x29, sp;
    /* 0x2eec94 */ mov w0, #0x18;
    _Znwm();
    /* 0x2eec9c */ stp xzr, xzr, [x0, #8];
    /* 0x2eeca0 */ str xzr, [x0];
    /* 0x2eeca4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
