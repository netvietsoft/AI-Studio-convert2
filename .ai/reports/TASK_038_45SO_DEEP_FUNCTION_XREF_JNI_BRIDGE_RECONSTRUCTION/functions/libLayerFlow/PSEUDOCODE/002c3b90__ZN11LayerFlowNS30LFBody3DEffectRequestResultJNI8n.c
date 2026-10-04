// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c3b90
// Recovered Name: _ZN11LayerFlowNS30LFBody3DEffectRequestResultJNI8nDestroyEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c3b90 | Size: 148 bytes | SHA256: 7a284dddc5bbcbbe10f4869edadfee6e08163f7c4e3ed0a1d5c69b51094e56a6
// Callers: 0 | Callees: 3 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x532948)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "LFBody3DEffectRequestResultJNI::nDestroy addr => %p"

jobject _ZN11LayerFlowNS30LFBody3DEffectRequestResultJNI8nDestroyEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x2c3b90 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c3b94 */ str x19, [sp, #0x10];
    /* 0x2c3b98 */ mov x29, sp;
    /* 0x2c3b9c */ mov x19, x2;
    /* 0x2c3ba0 */ nop ;
    /* 0x2c3ba4 */ adr x1, #0x1e1361;
    /* 0x2c3ba8 */ adrp x2, #0x1d8000;
    /* 0x2c3bac */ add x2, x2, #0x8d4;
    /* 0x2c3bb0 */ mov w0, #6;
    /* 0x2c3bb4 */ mov x3, x19;
    __android_log_print();
    sub_2bdb7c();
    sub_2bd6fc();
    sub_2bd3d0();
    sub_2bd3d0();
    sub_2bd3d0();
    sub_2bd3d0();
    return x0;
}
