// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d010c
// Recovered Name: _ZN11LayerFlowNS24LFEffectHeadScaleDataJNI14nDestroyParamsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d010c | Size: 76 bytes | SHA256: 71b6add341839d52ecec1e7390baea0c9f0219f7ee767bbb6b6a9fc1770d67c4
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x534658)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyParams is called,addr => %p"

jobject _ZN11LayerFlowNS24LFEffectHeadScaleDataJNI14nDestroyParamsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2d010c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d0110 */ str x19, [sp, #0x10];
    /* 0x2d0114 */ mov x29, sp;
    /* 0x2d0118 */ mov x19, x2;
    /* 0x2d011c */ nop ;
    /* 0x2d0120 */ adr x1, #0x1e1361;
    /* 0x2d0124 */ adrp x2, #0x1ee000;
    /* 0x2d0128 */ add x2, x2, #0xb3e;
    /* 0x2d012c */ mov w0, #6;
    /* 0x2d0130 */ mov x3, x19;
    __android_log_print();
    return x0;
}
