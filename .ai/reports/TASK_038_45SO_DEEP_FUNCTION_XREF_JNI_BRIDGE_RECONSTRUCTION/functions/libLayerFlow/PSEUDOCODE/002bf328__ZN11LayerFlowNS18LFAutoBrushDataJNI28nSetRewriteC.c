// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2bf328
// Recovered Name: _ZN11LayerFlowNS18LFAutoBrushDataJNI28nSetRewriteChildrenMaterialsEP7_JNIEnvP8_jobjectlP11_jlongArray
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2bf328 | Size: 288 bytes | SHA256: 2feb528f5f0f0bd8e70f78758f37623442036bf43cc436e0262b7e800b8d399d
// Callers: 0 | Callees: 4 | Imports: 0

// Dynamic Registration: nSetRewriteChildrenMaterials(J[J)V (table at 0x531c70)

jobject _ZN11LayerFlowNS18LFAutoBrushDataJNI28nSetRewriteChildrenMaterialsEP7_JNIEnvP8_jobjectlP11_jlongArray(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 72 instructions
    /* 0x2bf328 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x2bf32c */ stp x26, x25, [sp, #0x10];
    /* 0x2bf330 */ stp x24, x23, [sp, #0x20];
    /* 0x2bf334 */ stp x22, x21, [sp, #0x30];
    /* 0x2bf338 */ stp x20, x19, [sp, #0x40];
    /* 0x2bf33c */ mov x29, sp;
    /* 0x2bf340 */ mov x22, x2;
    /* 0x2bf344 */ mov x21, x0;
    /* 0x2bf348 */ mov x19, x3;
    /* 0x2bf34c */ ldr x1, [x22, #0x38]!;
    /* 0x2bf350 */ mov x0, x22;
    sub_2c0a8c();
    sub_2c0a8c();
    _ZNSt6__ndk16vectorI26LFRewriteChildrenMaterialsNS_9allocatorIS1_EEE21__push_back_slow_pathIRKS1_EEPS1_OT_();
    _ZN26LFRewriteChildrenMaterialsC2ERKS_();
    return x0;
    sub_526544();
}
