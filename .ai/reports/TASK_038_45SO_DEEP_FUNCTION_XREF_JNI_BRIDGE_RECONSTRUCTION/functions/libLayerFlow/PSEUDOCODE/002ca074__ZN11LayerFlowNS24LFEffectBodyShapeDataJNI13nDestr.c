// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ca074
// Recovered Name: _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ca074 | Size: 92 bytes | SHA256: 25189c36e1ccd8f651a1cc654f1e13bad417d90b5f028fdcc63cd97b9599da98
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x533590)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModel is called,addr => %p"

jobject _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x2ca074 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ca078 */ str x19, [sp, #0x10];
    /* 0x2ca07c */ mov x29, sp;
    /* 0x2ca080 */ mov x19, x2;
    /* 0x2ca084 */ nop ;
    /* 0x2ca088 */ adr x1, #0x1e1361;
    /* 0x2ca08c */ adrp x2, #0x1e0000;
    /* 0x2ca090 */ add x2, x2, #0x1ae;
    /* 0x2ca094 */ mov w0, #6;
    /* 0x2ca098 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    return x0;
}
