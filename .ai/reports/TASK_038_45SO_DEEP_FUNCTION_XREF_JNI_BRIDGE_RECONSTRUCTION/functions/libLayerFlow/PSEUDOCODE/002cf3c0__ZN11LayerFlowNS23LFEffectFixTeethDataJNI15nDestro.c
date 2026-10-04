// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cf3c0
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cf3c0 | Size: 208 bytes | SHA256: b4d763452548a8aeb923853d232443a15c15c0f0eb83dff4b4147ffa5cd4943f
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5345b0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModular is called,addr => %p"

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 52 instructions
    /* 0x2cf3c0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2cf3c4 */ str x21, [sp, #0x10];
    /* 0x2cf3c8 */ stp x20, x19, [sp, #0x20];
    /* 0x2cf3cc */ mov x29, sp;
    /* 0x2cf3d0 */ mov x19, x2;
    /* 0x2cf3d4 */ nop ;
    /* 0x2cf3d8 */ adr x1, #0x1e1361;
    /* 0x2cf3dc */ adrp x2, #0x1d9000;
    /* 0x2cf3e0 */ add x2, x2, #0xa24;
    /* 0x2cf3e4 */ mov w0, #6;
    /* 0x2cf3e8 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
}
