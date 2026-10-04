// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d2b90
// Recovered Name: _ZN11LayerFlowNS23LFEffectSlimmingDataJNI18nDestroyFaceParamsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d2b90 | Size: 76 bytes | SHA256: b3a4d2e112e335ea5a2b85671bc4cca271879050d9c4809249acda4df7977161
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroyFaceParams(J)V (table at 0x535180)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyFaceParams is called,addr => %p"

jobject _ZN11LayerFlowNS23LFEffectSlimmingDataJNI18nDestroyFaceParamsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2d2b90 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d2b94 */ str x19, [sp, #0x10];
    /* 0x2d2b98 */ mov x29, sp;
    /* 0x2d2b9c */ mov x19, x2;
    /* 0x2d2ba0 */ nop ;
    /* 0x2d2ba4 */ adr x1, #0x1e1361;
    /* 0x2d2ba8 */ adrp x2, #0x1d6000;
    /* 0x2d2bac */ add x2, x2, #0x84b;
    /* 0x2d2bb0 */ mov w0, #6;
    /* 0x2d2bb4 */ mov x3, x19;
    __android_log_print();
    return x0;
}
