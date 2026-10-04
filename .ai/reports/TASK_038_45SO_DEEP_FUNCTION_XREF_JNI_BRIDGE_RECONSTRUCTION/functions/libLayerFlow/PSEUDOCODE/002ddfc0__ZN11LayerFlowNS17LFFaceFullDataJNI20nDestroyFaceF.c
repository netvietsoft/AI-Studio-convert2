// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ddfc0
// Recovered Name: _ZN11LayerFlowNS17LFFaceFullDataJNI20nDestroyFaceFullInfoEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ddfc0 | Size: 76 bytes | SHA256: f625d50d689aeedfb586c9bbba7db7e4ef715a2236a66a1f3662f47681df0759
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5371e0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyFaceFullInfo try delete ptr  %p"

jobject _ZN11LayerFlowNS17LFFaceFullDataJNI20nDestroyFaceFullInfoEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2ddfc0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ddfc4 */ str x19, [sp, #0x10];
    /* 0x2ddfc8 */ mov x29, sp;
    /* 0x2ddfcc */ mov x19, x2;
    /* 0x2ddfd0 */ nop ;
    /* 0x2ddfd4 */ adr x1, #0x1e9177;
    /* 0x2ddfd8 */ adrp x2, #0x1ee000;
    /* 0x2ddfdc */ add x2, x2, #0xc3d;
    /* 0x2ddfe0 */ mov w0, #6;
    /* 0x2ddfe4 */ mov x3, x19;
    __android_log_print();
    return x0;
}
