// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d415c
// Recovered Name: _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d415c | Size: 148 bytes | SHA256: e639ca57f8f4d2ab056a87f2d7941d3ce8cdfded004ec91622908574e725869b
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x535660)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModular is called,addr => %p"

jobject _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x2d415c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d4160 */ str x19, [sp, #0x10];
    /* 0x2d4164 */ mov x29, sp;
    /* 0x2d4168 */ mov x19, x2;
    /* 0x2d416c */ nop ;
    /* 0x2d4170 */ adr x1, #0x1e1361;
    /* 0x2d4174 */ adrp x2, #0x1d9000;
    /* 0x2d4178 */ add x2, x2, #0xa24;
    /* 0x2d417c */ mov w0, #6;
    /* 0x2d4180 */ mov x3, x19;
    __android_log_print();
    return x0;
    _ZdlPv();
    _ZdlPv();
}
