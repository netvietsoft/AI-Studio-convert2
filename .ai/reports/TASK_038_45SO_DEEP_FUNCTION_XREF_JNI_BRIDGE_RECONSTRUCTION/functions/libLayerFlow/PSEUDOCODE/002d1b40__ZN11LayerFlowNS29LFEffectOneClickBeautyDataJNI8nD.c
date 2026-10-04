// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d1b40
// Recovered Name: _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI8nDestroyEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d1b40 | Size: 84 bytes | SHA256: f155a6ccddc2ddf30846682e252cd94e3b0d9cf57f719680676fa78f0379410d
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x534970)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "iklf_"
//   "nDestroy is called,addr => %p"

jobject _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI8nDestroyEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 21 instructions
    /* 0x2d1b40 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d1b44 */ str x19, [sp, #0x10];
    /* 0x2d1b48 */ mov x29, sp;
    /* 0x2d1b4c */ mov x19, x2;
    /* 0x2d1b50 */ adrp x1, #0x1e1000;
    /* 0x2d1b54 */ add x1, x1, #0x361;
    /* 0x2d1b58 */ adrp x2, #0x1ce000;
    /* 0x2d1b5c */ add x2, x2, #0x42b;
    /* 0x2d1b60 */ mov w0, #6;
    /* 0x2d1b64 */ mov x3, x19;
    __android_log_print();
    _ZN23LFOneClickBeautyModularD1Ev();
    return x0;
}
