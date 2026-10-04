// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5960
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI11nSetModularEP7_JNIEnvP7_jclasslP8_jstring
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5960 | Size: 164 bytes | SHA256: 2a998fadaef52a271386873097469dfb71e08ebdbc27120cac45081672c6cc8c
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nSetModular(JLjava/lang/String;)V (table at 0x535b40)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI11nSetModularEP7_JNIEnvP7_jclasslP8_jstring(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 41 instructions
    /* 0x2d5960 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d5964 */ stp x22, x21, [sp, #0x10];
    /* 0x2d5968 */ stp x20, x19, [sp, #0x20];
    /* 0x2d596c */ mov x29, sp;
    /* 0x2d5970 */ cbz x2, #0x2d59d8;
    /* 0x2d5974 */ mov x19, x2;
    /* 0x2d5978 */ cbz x3, #0x2d59cc;
    /* 0x2d597c */ ldr x8, [x0];
    /* 0x2d5980 */ mov x1, x3;
    /* 0x2d5984 */ mov x2, xzr;
    /* 0x2d5988 */ mov x20, x0;
    sub_525b68();
    return x0;
    return x0;
}
