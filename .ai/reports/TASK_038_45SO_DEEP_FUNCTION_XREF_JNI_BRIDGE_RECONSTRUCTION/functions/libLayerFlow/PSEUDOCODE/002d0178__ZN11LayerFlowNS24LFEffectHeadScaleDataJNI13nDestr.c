// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d0178
// Recovered Name: _ZN11LayerFlowNS24LFEffectHeadScaleDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d0178 | Size: 92 bytes | SHA256: ede19750e12c91e57cc22903d90c6a83015061c11a4f2070d3bd59559853d6f7
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5346d0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModel is called,addr => %p"

jobject _ZN11LayerFlowNS24LFEffectHeadScaleDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x2d0178 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d017c */ str x19, [sp, #0x10];
    /* 0x2d0180 */ mov x29, sp;
    /* 0x2d0184 */ mov x19, x2;
    /* 0x2d0188 */ nop ;
    /* 0x2d018c */ adr x1, #0x1e1361;
    /* 0x2d0190 */ adrp x2, #0x1e0000;
    /* 0x2d0194 */ add x2, x2, #0x1ae;
    /* 0x2d0198 */ mov w0, #6;
    /* 0x2d019c */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    return x0;
}
