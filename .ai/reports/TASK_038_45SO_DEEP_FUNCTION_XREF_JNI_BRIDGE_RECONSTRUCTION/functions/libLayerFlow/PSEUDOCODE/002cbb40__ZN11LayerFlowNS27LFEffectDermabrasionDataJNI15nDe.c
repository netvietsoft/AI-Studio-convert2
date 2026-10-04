// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cbb40
// Recovered Name: _ZN11LayerFlowNS27LFEffectDermabrasionDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cbb40 | Size: 108 bytes | SHA256: dc2b6af21f4dbb8bbdcdeece7ff1f87b3eb565fee931fb117ccae0c361c04ba7
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x533a38)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModular is called,addr => %p"

jobject _ZN11LayerFlowNS27LFEffectDermabrasionDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x2cbb40 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2cbb44 */ str x19, [sp, #0x10];
    /* 0x2cbb48 */ mov x29, sp;
    /* 0x2cbb4c */ mov x19, x2;
    /* 0x2cbb50 */ nop ;
    /* 0x2cbb54 */ adr x1, #0x1e1361;
    /* 0x2cbb58 */ adrp x2, #0x1d9000;
    /* 0x2cbb5c */ add x2, x2, #0xa24;
    /* 0x2cbb60 */ mov w0, #6;
    /* 0x2cbb64 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    return x0;
}
