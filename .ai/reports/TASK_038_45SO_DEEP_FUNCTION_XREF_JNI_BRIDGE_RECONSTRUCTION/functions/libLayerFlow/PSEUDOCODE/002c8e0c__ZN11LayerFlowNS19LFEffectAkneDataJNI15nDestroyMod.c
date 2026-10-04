// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c8e0c
// Recovered Name: _ZN11LayerFlowNS19LFEffectAkneDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c8e0c | Size: 108 bytes | SHA256: 24da14f5d54603176880abfad043ed663c32587cc9c3bc1c19d1ea654d838b4a
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5332f0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModular is called,addr => %p"

jobject _ZN11LayerFlowNS19LFEffectAkneDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x2c8e0c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c8e10 */ str x19, [sp, #0x10];
    /* 0x2c8e14 */ mov x29, sp;
    /* 0x2c8e18 */ mov x19, x2;
    /* 0x2c8e1c */ nop ;
    /* 0x2c8e20 */ adr x1, #0x1e1361;
    /* 0x2c8e24 */ adrp x2, #0x1d9000;
    /* 0x2c8e28 */ add x2, x2, #0xa24;
    /* 0x2c8e2c */ mov w0, #6;
    /* 0x2c8e30 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    return x0;
}
