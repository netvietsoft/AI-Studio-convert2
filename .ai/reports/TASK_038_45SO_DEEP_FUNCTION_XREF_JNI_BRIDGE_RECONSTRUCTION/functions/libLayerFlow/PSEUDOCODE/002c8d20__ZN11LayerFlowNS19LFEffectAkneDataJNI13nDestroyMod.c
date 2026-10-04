// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c8d20
// Recovered Name: _ZN11LayerFlowNS19LFEffectAkneDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c8d20 | Size: 76 bytes | SHA256: 83890962d0f07de294fe231326d9f8e86f09e34844e293a06835bd2698970f32
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5331e8)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModel is called,addr => %p"

jobject _ZN11LayerFlowNS19LFEffectAkneDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2c8d20 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c8d24 */ str x19, [sp, #0x10];
    /* 0x2c8d28 */ mov x29, sp;
    /* 0x2c8d2c */ mov x19, x2;
    /* 0x2c8d30 */ nop ;
    /* 0x2c8d34 */ adr x1, #0x1e1361;
    /* 0x2c8d38 */ adrp x2, #0x1e0000;
    /* 0x2c8d3c */ add x2, x2, #0x1ae;
    /* 0x2c8d40 */ mov w0, #6;
    /* 0x2c8d44 */ mov x3, x19;
    __android_log_print();
    return x0;
}
