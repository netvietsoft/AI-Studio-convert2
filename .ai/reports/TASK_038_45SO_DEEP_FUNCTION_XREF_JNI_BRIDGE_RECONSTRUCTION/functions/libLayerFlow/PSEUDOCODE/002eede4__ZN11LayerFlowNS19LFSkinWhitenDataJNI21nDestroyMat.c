// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2eede4
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI21nDestroyMaterialParamEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2eede4 | Size: 76 bytes | SHA256: 532048eccdbe697b39a8503042d5c76d5b39b508189a0ded2d6a3bdea1b921ce
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x539d08)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "iklf_"
//   "nDestroyModular is called,addr => %p"

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI21nDestroyMaterialParamEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2eede4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2eede8 */ str x19, [sp, #0x10];
    /* 0x2eedec */ mov x29, sp;
    /* 0x2eedf0 */ mov x19, x2;
    /* 0x2eedf4 */ adrp x1, #0x1e1000;
    /* 0x2eedf8 */ add x1, x1, #0x361;
    /* 0x2eedfc */ adrp x2, #0x1d9000;
    /* 0x2eee00 */ add x2, x2, #0xa24;
    /* 0x2eee04 */ mov w0, #6;
    /* 0x2eee08 */ mov x3, x19;
    __android_log_print();
    return x0;
}
