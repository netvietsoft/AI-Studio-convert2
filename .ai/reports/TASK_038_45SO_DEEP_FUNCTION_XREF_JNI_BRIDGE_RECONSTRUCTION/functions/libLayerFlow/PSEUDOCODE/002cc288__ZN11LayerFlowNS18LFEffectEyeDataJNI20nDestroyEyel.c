// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cc288
// Recovered Name: _ZN11LayerFlowNS18LFEffectEyeDataJNI20nDestroyEyelidParamsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cc288 | Size: 76 bytes | SHA256: e060fd43dc70f0176ece9f71d93c86afe510f5e58151bd379ece4edf2a73a533
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x533cf0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyEyelidParams is called,addr => %p"

jobject _ZN11LayerFlowNS18LFEffectEyeDataJNI20nDestroyEyelidParamsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2cc288 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2cc28c */ str x19, [sp, #0x10];
    /* 0x2cc290 */ mov x29, sp;
    /* 0x2cc294 */ mov x19, x2;
    /* 0x2cc298 */ nop ;
    /* 0x2cc29c */ adr x1, #0x1e1361;
    /* 0x2cc2a0 */ adrp x2, #0x1d1000;
    /* 0x2cc2a4 */ add x2, x2, #0x96e;
    /* 0x2cc2a8 */ mov w0, #6;
    /* 0x2cc2ac */ mov x3, x19;
    __android_log_print();
    return x0;
}
