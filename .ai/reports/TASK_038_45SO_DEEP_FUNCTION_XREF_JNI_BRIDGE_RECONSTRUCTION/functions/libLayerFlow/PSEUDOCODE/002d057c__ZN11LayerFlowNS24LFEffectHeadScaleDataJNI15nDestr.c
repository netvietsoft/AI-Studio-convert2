// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d057c
// Recovered Name: _ZN11LayerFlowNS24LFEffectHeadScaleDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d057c | Size: 176 bytes | SHA256: e85e3a58dd171e3720cef02b95291ac08854ada50104a8cd751da2ed74b5c678
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x534778)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModular is called,addr => %p"

jobject _ZN11LayerFlowNS24LFEffectHeadScaleDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x2d057c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d0580 */ str x21, [sp, #0x10];
    /* 0x2d0584 */ stp x20, x19, [sp, #0x20];
    /* 0x2d0588 */ mov x29, sp;
    /* 0x2d058c */ mov x19, x2;
    /* 0x2d0590 */ nop ;
    /* 0x2d0594 */ adr x1, #0x1e1361;
    /* 0x2d0598 */ adrp x2, #0x1d9000;
    /* 0x2d059c */ add x2, x2, #0xa24;
    /* 0x2d05a0 */ mov w0, #6;
    /* 0x2d05a4 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
}
