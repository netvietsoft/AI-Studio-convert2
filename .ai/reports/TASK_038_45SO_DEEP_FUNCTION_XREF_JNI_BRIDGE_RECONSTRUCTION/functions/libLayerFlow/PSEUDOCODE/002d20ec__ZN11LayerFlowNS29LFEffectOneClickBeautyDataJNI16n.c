// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d20ec
// Recovered Name: _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI16nDestroyMaterialEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d20ec | Size: 76 bytes | SHA256: 40c9a86e6ea25e0d5f51a438814b1bcb30bacdbebb9c2551fc9119552f73fe8e
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x534cd0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "iklf_"
//   "nDestroyMaterial is called,addr => %p"

jobject _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI16nDestroyMaterialEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2d20ec */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d20f0 */ str x19, [sp, #0x10];
    /* 0x2d20f4 */ mov x29, sp;
    /* 0x2d20f8 */ mov x19, x2;
    /* 0x2d20fc */ adrp x1, #0x1e1000;
    /* 0x2d2100 */ add x1, x1, #0x361;
    /* 0x2d2104 */ adrp x2, #0x1eb000;
    /* 0x2d2108 */ add x2, x2, #0x952;
    /* 0x2d210c */ mov w0, #6;
    /* 0x2d2110 */ mov x3, x19;
    __android_log_print();
    return x0;
}
