// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5758
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI10nSetMaskIdEP7_JNIEnvP7_jclasslP8_jstring
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5758 | Size: 164 bytes | SHA256: a5b198ce4151df6e3d9933fd39da6bb90a9ec35a32a772e0f52078b023ca9acb
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nSetMaskId(JLjava/lang/String;)V (table at 0x535a98)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI10nSetMaskIdEP7_JNIEnvP7_jclasslP8_jstring(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 41 instructions
    /* 0x2d5758 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d575c */ stp x22, x21, [sp, #0x10];
    /* 0x2d5760 */ stp x20, x19, [sp, #0x20];
    /* 0x2d5764 */ mov x29, sp;
    /* 0x2d5768 */ cbz x2, #0x2d57d0;
    /* 0x2d576c */ mov x19, x2;
    /* 0x2d5770 */ cbz x3, #0x2d57c4;
    /* 0x2d5774 */ ldr x8, [x0];
    /* 0x2d5778 */ mov x1, x3;
    /* 0x2d577c */ mov x2, xzr;
    /* 0x2d5780 */ mov x20, x0;
    sub_525b68();
    return x0;
    return x0;
}
