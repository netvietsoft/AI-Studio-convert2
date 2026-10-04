// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ccf1c
// Recovered Name: _ZN11LayerFlowNS18LFEffectEyeDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ccf1c | Size: 208 bytes | SHA256: cab2c3092e3bd72d291817522897192654c8d4ef5e6fa5f98988d1f909013190
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x533ea0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModular is called,addr => %p"

jobject _ZN11LayerFlowNS18LFEffectEyeDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 52 instructions
    /* 0x2ccf1c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2ccf20 */ str x21, [sp, #0x10];
    /* 0x2ccf24 */ stp x20, x19, [sp, #0x20];
    /* 0x2ccf28 */ mov x29, sp;
    /* 0x2ccf2c */ mov x19, x2;
    /* 0x2ccf30 */ nop ;
    /* 0x2ccf34 */ adr x1, #0x1e1361;
    /* 0x2ccf38 */ adrp x2, #0x1d9000;
    /* 0x2ccf3c */ add x2, x2, #0xa24;
    /* 0x2ccf40 */ mov w0, #6;
    /* 0x2ccf44 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
}
