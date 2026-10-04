// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2eed28
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI21nDestroyWakeSkinParamEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2eed28 | Size: 76 bytes | SHA256: b4f1a24b66bca49498c71ca3b3d723b6d890a96b82cfb59121707735df93f847
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x539948)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "iklf_"
//   "nDestroyWakeSkinParam is called,addr => %p"

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI21nDestroyWakeSkinParamEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2eed28 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2eed2c */ str x19, [sp, #0x10];
    /* 0x2eed30 */ mov x29, sp;
    /* 0x2eed34 */ mov x19, x2;
    /* 0x2eed38 */ adrp x1, #0x1e1000;
    /* 0x2eed3c */ add x1, x1, #0x361;
    /* 0x2eed40 */ adrp x2, #0x1de000;
    /* 0x2eed44 */ add x2, x2, #0x80;
    /* 0x2eed48 */ mov w0, #6;
    /* 0x2eed4c */ mov x3, x19;
    __android_log_print();
    return x0;
}
