// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cc1cc
// Recovered Name: _ZN11LayerFlowNS18LFEffectEyeDataJNI24nDestroyCatchLightParamsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cc1cc | Size: 76 bytes | SHA256: ab095c71bb0e9871ab279b4bc348de96b5762386f1d7d321dc6dc6053e576fe8
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x533b88)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyCatchLightParams is called,addr => %p"

jobject _ZN11LayerFlowNS18LFEffectEyeDataJNI24nDestroyCatchLightParamsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2cc1cc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2cc1d0 */ str x19, [sp, #0x10];
    /* 0x2cc1d4 */ mov x29, sp;
    /* 0x2cc1d8 */ mov x19, x2;
    /* 0x2cc1dc */ nop ;
    /* 0x2cc1e0 */ adr x1, #0x1e1361;
    /* 0x2cc1e4 */ adrp x2, #0x1db000;
    /* 0x2cc1e8 */ add x2, x2, #0xde8;
    /* 0x2cc1ec */ mov w0, #6;
    /* 0x2cc1f0 */ mov x3, x19;
    __android_log_print();
    return x0;
}
