// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c9ff8
// Recovered Name: _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI18nDestroyAutoParamsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c9ff8 | Size: 76 bytes | SHA256: 125ad01eb99268d88279cc8a4403cc0b3a14d5434a087a6b2ff83f3c8ee75042
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5334e8)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyAutoParams is called,addr => %p"

jobject _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI18nDestroyAutoParamsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2c9ff8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c9ffc */ str x19, [sp, #0x10];
    /* 0x2ca000 */ mov x29, sp;
    /* 0x2ca004 */ mov x19, x2;
    /* 0x2ca008 */ nop ;
    /* 0x2ca00c */ adr x1, #0x1e1361;
    /* 0x2ca010 */ adrp x2, #0x1ee000;
    /* 0x2ca014 */ add x2, x2, #0xaad;
    /* 0x2ca018 */ mov w0, #6;
    /* 0x2ca01c */ mov x3, x19;
    __android_log_print();
    return x0;
}
