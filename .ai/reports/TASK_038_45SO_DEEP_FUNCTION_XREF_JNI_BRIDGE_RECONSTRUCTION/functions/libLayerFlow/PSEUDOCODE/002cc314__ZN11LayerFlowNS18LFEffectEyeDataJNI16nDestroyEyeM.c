// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cc314
// Recovered Name: _ZN11LayerFlowNS18LFEffectEyeDataJNI16nDestroyEyeModelEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cc314 | Size: 124 bytes | SHA256: c161544d13bc2c95d0b4c3216c96c9dae34c8a6fee8a76ece0b7b7a9e55d8e2c
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x533dc8)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyEyeModel is called,addr => %p"

jobject _ZN11LayerFlowNS18LFEffectEyeDataJNI16nDestroyEyeModelEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 31 instructions
    /* 0x2cc314 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2cc318 */ str x19, [sp, #0x10];
    /* 0x2cc31c */ mov x29, sp;
    /* 0x2cc320 */ mov x19, x2;
    /* 0x2cc324 */ nop ;
    /* 0x2cc328 */ adr x1, #0x1e1361;
    /* 0x2cc32c */ adrp x2, #0x1d1000;
    /* 0x2cc330 */ add x2, x2, #0x998;
    /* 0x2cc334 */ mov w0, #6;
    /* 0x2cc338 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
}
