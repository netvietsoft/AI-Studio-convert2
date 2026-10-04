// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d1168
// Recovered Name: _ZN11LayerFlowNS20LFEffectMatteDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d1168 | Size: 108 bytes | SHA256: c056b03a4c9f4ee9addcec29495dac93fbdb449389270e39d8d8a4f6254fac36
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5348c8)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModular is called,addr => %p"

jobject _ZN11LayerFlowNS20LFEffectMatteDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x2d1168 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d116c */ str x19, [sp, #0x10];
    /* 0x2d1170 */ mov x29, sp;
    /* 0x2d1174 */ mov x19, x2;
    /* 0x2d1178 */ nop ;
    /* 0x2d117c */ adr x1, #0x1e1361;
    /* 0x2d1180 */ adrp x2, #0x1d9000;
    /* 0x2d1184 */ add x2, x2, #0xa24;
    /* 0x2d1188 */ mov w0, #6;
    /* 0x2d118c */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    return x0;
}
