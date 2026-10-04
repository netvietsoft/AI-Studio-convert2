// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cb4c8
// Recovered Name: _ZN11LayerFlowNS24LFEffectDenseHairDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cb4c8 | Size: 108 bytes | SHA256: 45d687128a4b2dc5c16c665212161723a31ad19e2e70863fee17140cf88b41b2
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5338e8)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModular is called,addr => %p"

jobject _ZN11LayerFlowNS24LFEffectDenseHairDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x2cb4c8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2cb4cc */ str x19, [sp, #0x10];
    /* 0x2cb4d0 */ mov x29, sp;
    /* 0x2cb4d4 */ mov x19, x2;
    /* 0x2cb4d8 */ nop ;
    /* 0x2cb4dc */ adr x1, #0x1e1361;
    /* 0x2cb4e0 */ adrp x2, #0x1d9000;
    /* 0x2cb4e4 */ add x2, x2, #0xa24;
    /* 0x2cb4e8 */ mov w0, #6;
    /* 0x2cb4ec */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    return x0;
}
