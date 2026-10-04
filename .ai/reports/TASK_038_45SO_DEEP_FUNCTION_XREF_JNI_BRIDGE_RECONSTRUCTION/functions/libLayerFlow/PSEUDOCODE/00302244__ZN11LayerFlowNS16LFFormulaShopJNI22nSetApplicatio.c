// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x302244
// Recovered Name: _ZN11LayerFlowNS16LFFormulaShopJNI22nSetApplicationContextEP7_JNIEnvP8_jobjectlS4_
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x302244 | Size: 48 bytes | SHA256: 09c38edb2e76f2adc3c633fe9a82b3e4fb02d4196d5a6a0f463c1fc3344b5399
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetApplicationCtx(JLandroid/content/Context;)V (table at 0x53bf58)

jobject _ZN11LayerFlowNS16LFFormulaShopJNI22nSetApplicationContextEP7_JNIEnvP8_jobjectlS4_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x302244 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x302248 */ str x19, [sp, #0x10];
    /* 0x30224c */ mov x29, sp;
    /* 0x302250 */ ldr x8, [x0];
    /* 0x302254 */ mov x1, x3;
    /* 0x302258 */ mov x19, x2;
    /* 0x30225c */ ldr x8, [x8, #0xa8];
    /* 0x302260 */ blr x8;
    /* 0x302264 */ str x0, [x19, #0x20];
    /* 0x302268 */ ldr x19, [sp, #0x10];
    /* 0x30226c */ ldp x29, x30, [sp], #0x20;
    return x0;
}
