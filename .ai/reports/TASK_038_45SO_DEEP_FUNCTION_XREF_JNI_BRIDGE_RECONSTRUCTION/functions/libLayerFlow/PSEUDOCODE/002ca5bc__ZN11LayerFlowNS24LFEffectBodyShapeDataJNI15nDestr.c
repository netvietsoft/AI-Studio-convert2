// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ca5bc
// Recovered Name: _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ca5bc | Size: 192 bytes | SHA256: a9a753657707fc361bba244fd9151767bcf159a91f59c318bf4391ef1215a305
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5336f8)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModular is called,addr => %p"

jobject _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 48 instructions
    /* 0x2ca5bc */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2ca5c0 */ str x21, [sp, #0x10];
    /* 0x2ca5c4 */ stp x20, x19, [sp, #0x20];
    /* 0x2ca5c8 */ mov x29, sp;
    /* 0x2ca5cc */ mov x19, x2;
    /* 0x2ca5d0 */ nop ;
    /* 0x2ca5d4 */ adr x1, #0x1e1361;
    /* 0x2ca5d8 */ adrp x2, #0x1d9000;
    /* 0x2ca5dc */ add x2, x2, #0xa24;
    /* 0x2ca5e0 */ mov w0, #6;
    /* 0x2ca5e4 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
}
