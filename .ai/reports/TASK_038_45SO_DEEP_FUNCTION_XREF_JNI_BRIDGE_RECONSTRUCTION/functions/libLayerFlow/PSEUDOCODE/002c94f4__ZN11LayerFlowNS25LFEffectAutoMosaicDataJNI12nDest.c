// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c94f4
// Recovered Name: _ZN11LayerFlowNS25LFEffectAutoMosaicDataJNI12nDestroyModeEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c94f4 | Size: 92 bytes | SHA256: 27060975e01befd1c565ddef5feeaabd6f6a34e1523ab7fa268b99af1df1bea7
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x533398)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyMode is called,addr => %p"

jobject _ZN11LayerFlowNS25LFEffectAutoMosaicDataJNI12nDestroyModeEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x2c94f4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c94f8 */ str x19, [sp, #0x10];
    /* 0x2c94fc */ mov x29, sp;
    /* 0x2c9500 */ mov x19, x2;
    /* 0x2c9504 */ nop ;
    /* 0x2c9508 */ adr x1, #0x1e1361;
    /* 0x2c950c */ adrp x2, #0x1d5000;
    /* 0x2c9510 */ add x2, x2, #0x397;
    /* 0x2c9514 */ mov w0, #6;
    /* 0x2c9518 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    return x0;
}
