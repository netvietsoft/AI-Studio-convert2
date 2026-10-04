// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ce7e4
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ce7e4 | Size: 124 bytes | SHA256: 65e105843b31907b779afac24ba599240246a8493a6aa14b440cf20127e16d09
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x534490)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModel is called,addr => %p"

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 31 instructions
    /* 0x2ce7e4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ce7e8 */ str x19, [sp, #0x10];
    /* 0x2ce7ec */ mov x29, sp;
    /* 0x2ce7f0 */ mov x19, x2;
    /* 0x2ce7f4 */ nop ;
    /* 0x2ce7f8 */ adr x1, #0x1e1361;
    /* 0x2ce7fc */ adrp x2, #0x1e0000;
    /* 0x2ce800 */ add x2, x2, #0x1ae;
    /* 0x2ce804 */ mov w0, #6;
    /* 0x2ce808 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
}
