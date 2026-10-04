// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2eea38
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2eea38 | Size: 124 bytes | SHA256: 15b02e87e8ac785e0a86c43474177650989686fec36b3c63ade574ba095e7c5a
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x539678)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "iklf_"
//   "nDestroyInfo is called,addr => %p"

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 31 instructions
    /* 0x2eea38 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2eea3c */ str x19, [sp, #0x10];
    /* 0x2eea40 */ mov x29, sp;
    /* 0x2eea44 */ mov x19, x2;
    /* 0x2eea48 */ adrp x1, #0x1e1000;
    /* 0x2eea4c */ add x1, x1, #0x361;
    /* 0x2eea50 */ adrp x2, #0x1dd000;
    /* 0x2eea54 */ add x2, x2, #0xecd;
    /* 0x2eea58 */ mov w0, #6;
    /* 0x2eea5c */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
}
