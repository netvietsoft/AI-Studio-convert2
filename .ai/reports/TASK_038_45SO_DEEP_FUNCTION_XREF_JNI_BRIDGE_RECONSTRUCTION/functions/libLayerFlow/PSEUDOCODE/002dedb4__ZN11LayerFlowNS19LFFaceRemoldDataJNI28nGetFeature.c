// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2dedb4
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI28nGetFeatureParamDictListKeysEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2dedb4 | Size: 336 bytes | SHA256: eaac166c3282e6c8e2846cbe3068a76198e96f01cda39e14b8f9ebff8082291c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetFeatureParamDictListKeys(JI)[Ljava/lang/String; (table at 0x537780)
// Strings referenced:
//   "java/lang/String"

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI28nGetFeatureParamDictListKeysEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 84 instructions
    /* 0x2dedb4 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2dedb8 */ str x23, [sp, #0x10];
    /* 0x2dedbc */ stp x22, x21, [sp, #0x20];
    /* 0x2dedc0 */ stp x20, x19, [sp, #0x30];
    /* 0x2dedc4 */ mov x29, sp;
    /* 0x2dedc8 */ tbnz w3, #0x1f, #0x2deecc;
    /* 0x2dedcc */ ldp x8, x9, [x2, #0x40];
    /* 0x2dedd0 */ mov x10, #-0x5555555555555556;
    /* 0x2dedd4 */ movk x10, #0xaaab;
    /* 0x2dedd8 */ sub x9, x9, x8;
    /* 0x2deddc */ asr x9, x9, #3;
    return x0;
    return x0;
}
