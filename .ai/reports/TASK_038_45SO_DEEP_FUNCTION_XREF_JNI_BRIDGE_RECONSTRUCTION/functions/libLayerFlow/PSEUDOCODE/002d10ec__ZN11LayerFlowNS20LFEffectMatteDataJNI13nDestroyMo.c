// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d10ec
// Recovered Name: _ZN11LayerFlowNS20LFEffectMatteDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d10ec | Size: 76 bytes | SHA256: 197d015a072abd149f45ee70bef89fa41f757ae9435bb748ab619dda91f791d0
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x534820)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModel is called,addr => %p"

jobject _ZN11LayerFlowNS20LFEffectMatteDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2d10ec */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d10f0 */ str x19, [sp, #0x10];
    /* 0x2d10f4 */ mov x29, sp;
    /* 0x2d10f8 */ mov x19, x2;
    /* 0x2d10fc */ nop ;
    /* 0x2d1100 */ adr x1, #0x1e1361;
    /* 0x2d1104 */ adrp x2, #0x1e0000;
    /* 0x2d1108 */ add x2, x2, #0x1ae;
    /* 0x2d110c */ mov w0, #6;
    /* 0x2d1110 */ mov x3, x19;
    __android_log_print();
    return x0;
}
