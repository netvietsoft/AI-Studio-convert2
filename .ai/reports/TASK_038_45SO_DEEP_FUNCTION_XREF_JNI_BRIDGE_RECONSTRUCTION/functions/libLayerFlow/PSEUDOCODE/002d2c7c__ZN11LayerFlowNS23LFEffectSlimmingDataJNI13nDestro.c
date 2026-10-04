// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d2c7c
// Recovered Name: _ZN11LayerFlowNS23LFEffectSlimmingDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d2c7c | Size: 108 bytes | SHA256: e1efc4ccda6e315191c45c1afde2cb02c6a0a96265e0b67fcbfa3febb97db299
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroyModel(J)V (table at 0x534fa0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModel is called,addr => %p"

jobject _ZN11LayerFlowNS23LFEffectSlimmingDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x2d2c7c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d2c80 */ str x19, [sp, #0x10];
    /* 0x2d2c84 */ mov x29, sp;
    /* 0x2d2c88 */ mov x19, x2;
    /* 0x2d2c8c */ nop ;
    /* 0x2d2c90 */ adr x1, #0x1e1361;
    /* 0x2d2c94 */ adrp x2, #0x1e0000;
    /* 0x2d2c98 */ add x2, x2, #0x1ae;
    /* 0x2d2c9c */ mov w0, #6;
    /* 0x2d2ca0 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    return x0;
}
