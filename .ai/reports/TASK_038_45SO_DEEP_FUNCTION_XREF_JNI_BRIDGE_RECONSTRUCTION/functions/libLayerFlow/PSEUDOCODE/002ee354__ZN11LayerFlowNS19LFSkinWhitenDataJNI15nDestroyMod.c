// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee354
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee354 | Size: 120 bytes | SHA256: d626eca91a1331dcbd72792d6d92c7dd8411db08f5c5031b74e23a6732e455b9
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x539570)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "iklf_"
//   "nDestroyModular is called,addr => %p"

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0x2ee354 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ee358 */ str x19, [sp, #0x10];
    /* 0x2ee35c */ mov x29, sp;
    /* 0x2ee360 */ mov x19, x2;
    /* 0x2ee364 */ adrp x1, #0x1e1000;
    /* 0x2ee368 */ add x1, x1, #0x361;
    /* 0x2ee36c */ adrp x2, #0x1d9000;
    /* 0x2ee370 */ add x2, x2, #0xa24;
    /* 0x2ee374 */ mov w0, #6;
    /* 0x2ee378 */ mov x3, x19;
    __android_log_print();
    sub_2efac4();
    _ZdlPv();
    return x0;
}
